//ARDUINO LINE FOLLOWER CAR Based On Arduino Motor Driver Shield
//You have to install the AFMotor library before uploading the sketch
//First download the AFMotor Zip file then open Arduino IDE 
//go to sketch >> Include library >> ADD .Zip file >> Select the downloaded AFMotor Zip File >> open 
// Created by DIY Builder
// You Can modify the sketch according to your need.
#include <Arduino.h>
#include <AccelStepper.h>
#include <AFMotor.h> //Include Adafruit Motor Driver Shield Library
//create motor obejects
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

#define LEFT_SENSOR A0 // connect the Left sensor with analog pin A0
#define RIGHT_SENSOR A1 // connect the Right sensor with analog pin A1
AccelStepper stepper1(forwardstep1, backwardstep1);
AccelStepper stepper2(forwardstep2, backwardstep2);


void setup() {
  
pinMode(RIGHT_SENSOR, INPUT); // initialize Right sensor as an inut
pinMode(LEFT_SENSOR, INPUT); // initialize Left sensor as as input
stepper1.setMaxSpeed(200.0);
stepper1.setAcceleration(20.0);
stepper2.setMaxSpeed(200.0);
stepper2.setAcceleration(20.0);
stepper3.setMaxSpeed(200.0);
stepper3.setAcceleration(20.0);
stepper4.setMaxSpeed(200.0);
stepper4.setAcceleration(20.0);

}

void loop() {
if(analogRead(RIGHT_SENSOR)<=35 && analogRead(LEFT_SENSOR)<=35) //compare both sensor value to set the directionc
{
  stepper1.run(FORWARD);
  stepper2.run(FORWARD);
  stepper3.run(FORWARD);
  stepper4.run(FORWARD);
}
 else if(!analogRead(RIGHT_SENSOR)<=35 && analogRead(LEFT_SENSOR)<=35) //compare both sensor value to set the direction
 {
  stepper1.run(FORWARD);
  stepper2.run(FORWARD);
  stepper3.run(BACKWARD);
  stepper4.run(BACKWARD);
  
}
 else if(analogRead(RIGHT_SENSOR)<=35 && !analogRead(LEFT_SENSOR)<=35) //compare both sensor value to set the direction
 {
  stepper1.run(BACKWARD);
  stepper2.run(BACKWARD);
  stepper3.run(FORWARD);
  stepper4.run(FORWARD);
}
else if(!analogRead(RIGHT_SENSOR)<=35 && !analogRead(LEFT_SENSOR)<=35) //compare both sensor value to set the direction
{
  //stop all the motors
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
 }
}