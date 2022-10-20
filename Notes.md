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

To calibrate the motors, we modified the DC Motor Test example script to just run the servos in the same direction constantly. This script is called "CalibrateMotors.ino". We also needed to make sure that in the code, the two servos ran in opposite directions (which translated to them running in the same direction in real life). This made sense because the motors are flipped relative to each other, so in order for them to rotate in the same direction, they must be given opposite instructions.

We attached the wheels and lifted them off the ground so it was easier to visually analyze the rotation of the servos. Essentially, we kept plugging in speed values for the two motors we had, marked a line on each of the wheels, and plugged and chugged with the speeds until we visually saw the two lines passing by us at the same frequency. 

It happened to be that when the left wheel operated at speed 54, the right wheel operated at about speed 100.

When testing the final chassis on the ground, we realized that it was quite heavy, and couldn't actually move at lower speeds.


# Calibrating the Sensors

Calibration of the sensors was needed because the distance to the ground varied a bit. This was done by assembling the car, and measuring each value on the floor. We realized we needed to also calibrate the resistor value using a bit of trial and error. The original value used, 5kOhm, was not enouhg to distinguish between the floor and tape. The combination fo the shadows created by the bot, and the distance from the ground. The robot was on 2 wheels so slightly tipped forward when not moving. Therefore, we needed to make sure the resistor value was high enough that even while tipped (increasing the measured distance), the sensors could differentiate between floor and tape.

10 kOhms wasn't enough for some tilt angles. 50 kOhms was too much and when the bot was perfectly upright, it couldnt' distinguish between the tape and floor. 20 kOhms seemed to be perfect.

Next, by using the TestIRSensor.ino file, we looked at the analog read value and tried to find the patterns. It happened that when the read value was maxed out (1023), the sensor was reading black tape. Any other value could represent the floor. But to give a bit of leeway, we made the threshold be a bit lower than 1023. We used a threshold of 900.

IN addition to calibrating each sensor based on their distance to the ground, we needed to "calibrate" the distnace between them to properly allow the tape to be between them without being sensed, but not too far apart that it takes too long for corrections to happen.


Notes to self:
* need to mount the sensors securely. the fuckin tape does jack shit and falls off every other run
* look into how to properly implement bang-bang
* possibly need to make a calibration curve for the sensor readings vs. distance
