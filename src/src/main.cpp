#include <Arduino.h>
#include <Lights.h>
#include <Lidar.h>
#include <Engine.h>
#include <Compass.h>
#include <ESP32Servo.h>
#include <Wire.h>
#include <Pixy2.h>
#include <CompetitionMode.h>

// Hardware / control constants
const int BUTTON_PIN = 14;
const int ENABLE_MOTOR = 32;
const int MOTOR_1 = 26;
const int MOTOR_2 = 25;
const int ROBOT_WIDTH = 150;
const int MIN_ANGLE = 60;
const int MAX_ANGLE = 120;
const int STRAIGHT_ANGLE = 88;
const int TARGET_DISTANCE = 300;
const int WIDTH_THRESHOLD = 150;

// Obstacle-vision tuning
const int PIXY_MIN_BLOCK_HEIGHT = 8;
const int PIXY_MAX_BLOCK_HEIGHT = 70;
const int PIXY_SIGNATURE_1_OFFSET = -105;
const int PIXY_OTHER_SIGNATURE_OFFSET = 55;
const float PIXY_STEERING_GAIN = 0.32;
const unsigned long OBSTACLE_RECOVERY_MS = 450;

// PPD constants
const float Kp = 0.09;
const float Kg = 0.95;
const float Kd = 0.05;

enum class RobotState : uint8_t {
  WAIT_FOR_START,
  NORMAL_DRIVING,
  TURNING,
  OBSTACLE_AVOIDANCE,
  OBSTACLE_RECOVERY,
  FINISHED,
  ERROR
};

RobotState robotState = RobotState::WAIT_FOR_START;

// Global variables
float last_error = 0;
float last_time = 0;
float targetAngle = 0;
int edge = 0;
bool isClockwise = true;
bool sideLock = false;
int sectorWidth[4] = {0};
int cumulativeWidth = 0;
int measurementCount = 0;
unsigned long clockStop = 0;
bool button_state = 1;
unsigned long obstacleRecoveryUntil = 0;

auto engine = Engine(MOTOR_1, MOTOR_2, ENABLE_MOTOR);
Compass robotCompass;
Servo myservo;
Distance_Sensor leftSensor;
Distance_Sensor rightSensor;
Distance_Sensor frontSensor;
Pixy2 pixy;

void setRobotState(RobotState nextState) {
  robotState = nextState;
}

void resetRunTracking() {
  last_error = 0;
  last_time = 0;
  edge = 0;
  isClockwise = true;
  sideLock = false;
  for (int i = 0; i < 4; i++) {
    sectorWidth[i] = 0;
  }
  cumulativeWidth = 0;
  measurementCount = 0;
  clockStop = 0;
  obstacleRecoveryUntil = 0;
}

void failStartup(const char* message) {
  Serial.println(message);
  setRobotState(RobotState::ERROR);
  while (1) {
    delay(100);
  }
}

void setup() {
  Serial.begin(115200);
  Wire.begin();

  set_light_state(2, 0);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  pinMode(MOTOR_1, OUTPUT);
  pinMode(MOTOR_2, OUTPUT);
  pinMode(ENABLE_MOTOR, OUTPUT);

  // Keep all three identical-address VL53L1X sensors disabled, then
  // initialize them one-by-one and assign unique I2C addresses.
  pinMode(5, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(15, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(18, LOW);
  digitalWrite(15, LOW);
  delay(50);

  if (!frontSensor.begin(15, 0x30)) {
    failStartup("Front ToF failed!");
  }

  delay(50);

  if (!leftSensor.begin(5, 0x31)) {
    failStartup("Left ToF failed!");
  }

  delay(50);

  if (!rightSensor.begin(18, 0x32)) {
    failStartup("Right ToF failed!");
  }

  if (!robotCompass.begin()) {
    failStartup("Compass failed!");
  }

  ledcSetup(0, 30000, 8);
  ledcAttachPin(ENABLE_MOTOR, 0);
  engine.begin();

  myservo.attach(33, 500, 2400);
  myservo.write(STRAIGHT_ANGLE);
  set_light_state(2, 3);

  // Pixy2 performs CCC processing and is read directly by the ESP32.
  pixy.init();
  pixy.setLamp(1, 0);
  pixy.setLED(0, 0, 0);

  setRobotState(RobotState::WAIT_FOR_START);
}

void loop() {
  button_state = digitalRead(BUTTON_PIN);
  blink_lights();

  if (button_state == 0) {
    delay(400);
    if (robotState == RobotState::WAIT_FOR_START || robotState == RobotState::FINISHED) {
      resetRunTracking();
      targetAngle = robotCompass.getYaw();
      setRobotState(RobotState::NORMAL_DRIVING);
    } else if (robotState != RobotState::ERROR) {
      setRobotState(RobotState::WAIT_FOR_START);
    }
  }

  // States that require no driving are handled immediately. The remaining
  // states continue into the shared sensing/control section below.
  switch (robotState) {
    case RobotState::WAIT_FOR_START:
      set_light_state(2, 3);
      engine.stop();
      return;

    case RobotState::FINISHED:
      set_light_state(2, 3);
      engine.stop();
      return;

    case RobotState::ERROR:
      set_light_state(2, 0);
      engine.stop();
      return;

    case RobotState::NORMAL_DRIVING:
    case RobotState::TURNING:
    case RobotState::OBSTACLE_AVOIDANCE:
    case RobotState::OBSTACLE_RECOVERY:
      break;
  }

  set_light_state(2, 1);
  engine.drive(255);

  // Direct Pixy2 -> ESP32 obstacle data.
  pixy.ccc.getBlocks();

  float heading = targetAngle - robotCompass.getYaw();
  if (heading > 180) heading -= 360;
  if (heading < -180) heading += 360;

  Distance_Result frontDistance = frontSensor.measureDistance();
  const Distance_Result leftDistance = leftSensor.measureDistance();
  const Distance_Result rightDistance = rightSensor.measureDistance();
  const int width = leftDistance.distance + rightDistance.distance;
  const int currentSector = abs(targetAngle) / 90;
  int nextSector = currentSector + 1;
  if (nextSector == 4) {
    nextSector = 0;
  }

  Serial.println(String("L: ") + leftDistance.distance + "mm (" + leftDistance.status + ") R: "
    + rightDistance.distance + "(" + rightDistance.status + ") Gyro: " + heading + " Front: "
    + frontDistance.distance + "mm (" + frontDistance.status + ") Sector: " + currentSector
    + " Width: " + sectorWidth[currentSector] + " Next: " + nextSector);

  const bool cornerDetected =
    frontDistance.distance <= (ROBOT_WIDTH + (sectorWidth[nextSector] == 0 ? TARGET_DISTANCE : (sectorWidth[nextSector] / 2)))
    && frontDistance.status == 0
    && width >= 900;

  if (cornerDetected) {
    setRobotState(RobotState::TURNING);

    if (!sideLock) {
      isClockwise = (leftDistance.distance <= 700 && (leftDistance.status == 0 || leftDistance.status == 2));
      sideLock = true;
    }

    if (!OBSTACLE_ROUND && measurementCount > 0) {
      sectorWidth[currentSector] = constrain(cumulativeWidth / measurementCount, 500, 900);
    }

    while (frontDistance.distance <= 1500 || frontDistance.distance >= 2700 || frontDistance.status == 4) {
      frontDistance = frontSensor.measureDistance();
      myservo.write(isClockwise ? MIN_ANGLE : MAX_ANGLE);
      delay(20);
    }

    targetAngle += isClockwise ? -90 : 90;
    targetAngle = fmod(targetAngle, 360.0);
    edge++;
    cumulativeWidth = 0;
    measurementCount = 0;
    setRobotState(RobotState::NORMAL_DRIVING);
  }

  float angle = Kg * heading;

  // Select the closest useful Pixy2 CCC block (largest image Y) while
  // rejecting detections that are too small or implausibly large.
  int maxY = 0;
  Block selectedBlock;
  bool obstacleFound = false;

  for (int i = 0; i < pixy.ccc.numBlocks; i++) {
    const Block candidate = pixy.ccc.blocks[i];
    if (candidate.m_y > maxY
        && candidate.m_height > PIXY_MIN_BLOCK_HEIGHT
        && candidate.m_height < PIXY_MAX_BLOCK_HEIGHT) {
      maxY = candidate.m_y;
      selectedBlock = candidate;
      obstacleFound = true;
    }
  }

  if (OBSTACLE_ROUND) {
    if (obstacleFound && millis() > obstacleRecoveryUntil) {
      setRobotState(RobotState::OBSTACLE_AVOIDANCE);
    } else if (robotState == RobotState::OBSTACLE_AVOIDANCE && !obstacleFound) {
      obstacleRecoveryUntil = millis() + OBSTACLE_RECOVERY_MS;
      setRobotState(RobotState::OBSTACLE_RECOVERY);
    } else if (robotState == RobotState::OBSTACLE_RECOVERY && millis() > obstacleRecoveryUntil) {
      setRobotState(RobotState::NORMAL_DRIVING);
    }
  }

  // In OBSTACLE_AVOIDANCE the camera contribution temporarily becomes
  // dominant. Different signatures use different target offsets so the
  // vehicle passes the obstacle on the required side.
  if (robotState == RobotState::OBSTACLE_AVOIDANCE && obstacleFound) {
    const int offset = selectedBlock.m_signature == 1
      ? PIXY_SIGNATURE_1_OFFSET
      : PIXY_OTHER_SIGNATURE_OFFSET;

    const int cameraError = pixy.frameWidth / 2 + offset - selectedBlock.m_x;
    angle = PIXY_STEERING_GAIN * cameraError;
  }

  // Clockwise driving follows the left (outer) wall; counter-clockwise
  // driving follows the right (outer) wall.
  const Distance_Result outerDistance = isClockwise ? leftDistance : rightDistance;
  const int targetWallDistance = sectorWidth[currentSector] == 0
    ? TARGET_DISTANCE
    : sectorWidth[currentSector] / 2;
  const float dist_err = outerDistance.distance - targetWallDistance;
  float err = last_error - heading;

  const bool wallControlAllowed =
    (!OBSTACLE_ROUND && sideLock)
    || (OBSTACLE_ROUND && robotState == RobotState::NORMAL_DRIVING);

  if (wallControlAllowed
      && outerDistance.distance <= 850
      && width <= 1100
      && (sectorWidth[currentSector] == 0 || abs(sectorWidth[currentSector] - width) <= WIDTH_THRESHOLD)) {
    angle += Kp * dist_err * (isClockwise ? 1 : -1);

    if (abs(dist_err) < 50 && edge >= 12 && abs(heading) <= 5) {
      if (clockStop == 0) {
        clockStop = millis();
      } else if ((millis() - clockStop) >= 2000) {
        setRobotState(RobotState::FINISHED);
        engine.stop();
        return;
      }
    }

    if (!OBSTACLE_ROUND && abs(heading) <= 3) {
      cumulativeWidth += width;
      measurementCount++;
    }
  }

  // Derivative damping.
  if (last_error == 0) {
    last_time = millis();
    last_error = err;
  } else {
    const float dt = millis() - last_time;
    if (dt > 0) {
      err /= dt;
      angle += Kd * err;
    }
    last_time = millis();
  }

  if (abs(angle) < 1) {
    angle = 0;
  }

  const int angle_constrained = constrain(STRAIGHT_ANGLE + round(angle), MIN_ANGLE, MAX_ANGLE);
  myservo.write(angle_constrained);
}
