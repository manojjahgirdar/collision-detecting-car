# Collision detecting car

Built a collision detecting car that stops when any obstacle is detected in its path.

## Learnings & Skills

1. Arduino C programming language
1. Working of HC-SR04 ultrasonic sensor
1. Working of gear motors
1. Working of 4x4 motor driver

## Circuit Diagram

![architecture](/doc/src/images/architecture.png)

## Technical Description

The car consists of 4 gear motors that powers the 4 wheels of the car. There is a motor driver that takes power from 9V battery and powers upto 4 motors. I choose gear motor over the regular motor because of the good traction between the wheels and ground. The car is equipped with ultrasonic sensor HC-SR04 at the front that keeps calculating the distance of any object in-front of it based on the time taken for the ultrasonic wave to return after hitting the object. If the distance is less than 7in, the vehicle stops to avoid collision. The brain of this car is an Arduino uno and the code has been written in Arduino C language.

## Source code

The source code can be found here:
    - [collision_detecting_car.ino](/src/collision_detecting_car/collision_detecting_car.ino)

## References

1. [Ping Ultrasonic Range Finder](https://docs.arduino.cc/built-in-examples/sensors/Ping/)
1. [Control DC, Stepper & Servo with L293D Motor Driver Shield & Arduino](https://lastminuteengineers.com/l293d-motor-driver-shield-arduino-tutorial/)