Notes

The reflective optical sensor has a working range of 7-12 mm. Mechanical design needs to account for that.
Spec sheet: https://www.vishay.com/docs/83760/tcrt5000.pdf

One of the motors is not super responsive, so it rotates a lot slower than the other one. To accomodate for that, I multiplied the speed of the faster one by 0.3 so it was as slow as the other motor.


The current wiring follows the one on the canvas page, with V_out being the white wire on the breadboard

The optical sensor needs a resistor. According to the spec sheet, the typical output current is 0.1 mA, and since we're applying 5 V to it the resistance needs to be 5000 ohms

Had to wire the sensor to A0 and A1; no other analogs were responding.


## Reflectance sensor

Soldered the 4 pins to wires. Based on the diagram in https://www.vishay.com/docs/83760/tcrt5000.pdf:

Left side:
* E: thick red wire
* C: White

Right side:
* C: White
* A: black wire


# Testing/calibrating the motors

To test that the motors actually worked, we ran Adafruit's DC Motor Test example script. This turned the servos back and forth appropriately, which indicated that the motors ran. However, we noticed one unexpected thing, which was that the motors didn't run at the same speeds. One of them ran at around twice the speed of the other, despite having the same input values. Thus, calibration was needed.

To calibrate the motors, we modified the DC Motor Test example script to just run the servos in the same direction constantly. This script is called "CalibrateMotors.ino". We attached the wheels and lifted them off the ground so it was easier to visually analyze the rotation of the servos. Essentially, we kept plugging in speed values for the two motors we had, marked a line on each of the wheels, and plugged and chugged with the speeds until we visually saw the two lines passing by us at the same frequency. 

It happened to be that when the left wheel operated at speed 43, the right wheel operated at speed 100.



# Calibrating the Sensors

Calibration of the sensors was needed because the distance to the ground varied a bit.


Notes to self:
* need to make a script to calibrate the sensors. Each sensor should have 2 reading vs. distance curves: one for tile, one for black tape
