# How we test the car

We try to compare changes on the same piece of track instead of judging them from one good run.

For a mechanical or control change we normally:

1. write down what problem we are trying to fix;
2. change one main thing at a time where possible;
3. repeat the same straight/corner/obstacle section several times;
4. record failures as well as successful attempts;
5. keep the change only if it makes the car more repeatable.

For V2 we also need electrical tests that did not exist in the same form on V1: current/rail sag, full power-cycle startup, PixyCam under different lighting, SPI/I2C with the motor running and driver/regulator temperatures.

The final challenge validation will use repeated Open and Obstacle runs. The working sheet is [`hardware_v2_validation_template.md`](hardware_v2_validation_template.md).
