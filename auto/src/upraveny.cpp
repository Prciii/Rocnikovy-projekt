//ARDUINO LINE FOLLOWER CAR Based On Arduino Motor Driver Shield
//You have to install the AFMotor library before uploading the sketch
//First download the AFMotor Zip file then open Arduino IDE 
//go to sketch >> Include library >> ADD .Zip file >> Select the downloaded AFMotor Zip File >> open 
// Created by DIY Builder
// You Can modify the sketch according to your need.
#include<Arduino.h>
#include<AFMotor.h> //Include Adafruit Motor Driver Shield Library
//create motor obejects
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

int rychlost = 150;

#define LEFT_SENSOR A0 // connect the Left sensor with analog pin A0
#define RIGHT_SENSOR A1 // connect the Right sensor with analog pin A1
void rychlost_motory(int a, int b, int c , int d , int rychlost){
  motor1.run(a); // run motor1 clockwise
  motor1.setSpeed(rychlost); // set motor1 speed 50 percent
  motor2.run(b); // run motor2 clockwise
  motor2.setSpeed(rychlost); // set motor2 speed 50 percent
  motor3.run(c); // run motor3 clockwise
  motor3.setSpeed(rychlost); // set motor3 speed 50 percent
  motor4.run(d); // run motor4 clockwise
  motor4.setSpeed(rychlost); // set motor4 speed 50 percent
}

void setup() {
  
pinMode(RIGHT_SENSOR, INPUT); // initialize Right sensor as an inut
pinMode(LEFT_SENSOR, INPUT); // initialize Left sensor as as input

}

void loop() {              
if(analogRead(RIGHT_SENSOR)<= 1020 && analogRead(LEFT_SENSOR)<=1020) //compare both sensor value to set the directionc
  rychlost_motory(RELEASE,RELEASE,RELEASE,RELEASE,rychlost);
else if(!analogRead(RIGHT_SENSOR)<=1020 && analogRead(LEFT_SENSOR)<=1020) //compare both sensor value to set the direction
  rychlost_motory(FORWARD,FORWARD,BACKWARD,BACKWARD,rychlost);
else if(analogRead(RIGHT_SENSOR)<=1020 && analogRead(LEFT_SENSOR)<=1020) //compare both sensor value to set the direction
  rychlost_motory(BACKWARD,BACKWARD,FORWARD,FORWARD,rychlost);
else if( analogRead(RIGHT_SENSOR) > 1020 && analogRead(LEFT_SENSOR) > 1020) //compare both sensor value to set the direction
  rychlost_motory(FORWARD,FORWARD,FORWARD,FORWARD,rychlost);
}