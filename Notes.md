Notes

The reflective optical sensor has a working range of 7-12 mm. Mechanical design needs to account for that.
Spec sheet: https://www.vishay.com/docs/83760/tcrt5000.pdf

One of the motors is not super responsive, so it rotates a lot slower than the other one. To accomodate for that, I multiplied the speed of the faster one by 0.3 so it was as slow as the other motor.


The current wiring follows the one on the canvas page, with V_out being the white wire on the breadboard

The optical sensor needs a resistor. According to the spec sheet, the typical output current is 0.1 mA, and since we're applying 5 V to it the resistance needs to be 5000 ohms

Had to wire the sensor to A0 and A1; no other analogs were responding.

