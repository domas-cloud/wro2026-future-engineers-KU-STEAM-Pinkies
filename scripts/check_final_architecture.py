from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
main_cpp = (ROOT / "src" / "src" / "main.cpp").read_text(encoding="utf-8")
lidar_h = (ROOT / "src" / "lib" / "Lidar" / "Lidar.h").read_text(encoding="utf-8")
platformio = (ROOT / "src" / "platformio.ini").read_text(encoding="utf-8")
mode_header_path = ROOT / "src" / "include" / "CompetitionMode.h"


def require(condition: bool, message: str) -> None:
    if not condition:
        raise AssertionError(message)


# Competition mode must be selected explicitly at build time, never by editing main.cpp.
require(
    "const bool OBSTACLE_ROUND = false" not in main_cpp
    and "const bool OBSTACLE_ROUND = true" not in main_cpp,
    "Challenge mode is still hard-coded in main.cpp; use CompetitionMode.h",
)
require("#include <CompetitionMode.h>" in main_cpp, "main.cpp must include CompetitionMode.h")
require(mode_header_path.exists(), "src/include/CompetitionMode.h is missing")
mode_header = mode_header_path.read_text(encoding="utf-8")
require("WRO_CHALLENGE_MODE" in mode_header, "CompetitionMode.h must use WRO_CHALLENGE_MODE")
require(
    "constexpr bool OBSTACLE_ROUND = (WRO_CHALLENGE_MODE == 1);" in mode_header,
    "CompetitionMode.h must derive OBSTACLE_ROUND from WRO_CHALLENGE_MODE",
)
require("#error" in mode_header, "CompetitionMode.h must reject missing/invalid challenge-mode values")

# Both competition configurations must be reproducible without editing source code.
require("[env:open_challenge]" in platformio, "PlatformIO env open_challenge is missing")
require("[env:obstacle_challenge]" in platformio, "PlatformIO env obstacle_challenge is missing")
require(
    "-DWRO_CHALLENGE_MODE=0" in platformio,
    "open_challenge must define WRO_CHALLENGE_MODE=0",
)
require(
    "-DWRO_CHALLENGE_MODE=1" in platformio,
    "obstacle_challenge must define WRO_CHALLENGE_MODE=1",
)

# The final controller must expose an explicit state machine, not only implicit booleans/timers.
require("enum class RobotState" in main_cpp, "RobotState enum is missing")
for state in [
    "WAIT_FOR_START",
    "NORMAL_DRIVING",
    "TURNING",
    "OBSTACLE_AVOIDANCE",
    "OBSTACLE_RECOVERY",
    "FINISHED",
    "ERROR",
]:
    require(f"RobotState::{state}" in main_cpp, f"Robot state {state} is missing")
require("switch (robotState)" in main_cpp, "main loop must dispatch through robotState")
require("setRobotState(" in main_cpp, "state transitions must use setRobotState()")

# Final ToF architecture: all three distance sensors use VL53L1X.
require("VL53L4CD" not in lidar_h, "Lidar.h still contains VL53L4CD implementation")
require("VL53L4CD" not in platformio, "platformio.ini still depends on VL53L4CD")
require("VL53L1X" in lidar_h, "Lidar.h must use VL53L1X")
require("pololu/VL53L1X" in platformio, "PlatformIO must include the VL53L1X library")

# Final vision architecture: Pixy2 talks directly to the ESP32.
require("#include <Pixy2.h>" in main_cpp, "main.cpp must include Pixy2.h")
require("Pixy2 pixy" in main_cpp, "main.cpp must instantiate Pixy2 directly")
require("pixy.init()" in main_cpp, "Pixy2 must be initialized directly by the ESP32")
require("pixy.ccc.getBlocks()" in main_cpp, "ESP32 must read Pixy2 CCC blocks directly")
require("HardwareSerial" not in main_cpp, "UART camera bridge must not remain in final firmware")
require("VISION," not in main_cpp, "UART VISION packet parser must not remain in final firmware")
require("RXD2" not in main_cpp and "TXD2" not in main_cpp, "UART2 camera pins must not remain in final firmware")
require("arduino12/pixy2" in platformio.lower(), "PlatformIO must include the Pixy2 dependency")

# All three ToF devices must still have independent XSHUT/address initialization.
for pin, address, label in [(15, "0x30", "front"), (5, "0x31", "left"), (18, "0x32", "right")]:
    require(
        f"{label}Sensor.begin({pin}, {address})" in main_cpp,
        f"{label} ToF must initialize on XSHUT GPIO{pin} with address {address}",
    )

print("Final architecture checks passed: explicit state machine + open/obstacle modes + 3x VL53L1X + direct Pixy2 -> ESP32.")
