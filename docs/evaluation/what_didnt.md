# What did not work well

The first steering geometry created too much servo load. Trying to tune software around that did not solve the real problem; changing the linkage did.

Earlier front wheels slipped too much, so a correct servo movement did not always become a correct turn. The metal differential also created more binding in corners than the LEGO solution.

At the motor extremes, the slow option limited the car too much and the 1000 rpm option was difficult to use well on the V1 build. That is why the V2 motor test will look at complete-car behaviour instead of only advertised speed.

The Pi Zero camera system worked as a development step, but for V2 we decided the extra computer, boot process, power branch and UART link were complexity we no longer wanted. PixyCam moves the colour processing onto the camera and lets the ESP32 remain the only main controller.
