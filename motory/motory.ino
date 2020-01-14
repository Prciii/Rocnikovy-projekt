
#include<AFMotor.h> //Include Adafruit Motor Driver Shield Library
//create motor obejects
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  motor1.run(FORWARD); // run motor1 clockwise
  motor1.setSpeed(150); // set motor1 speed 50 percent
  motor2.run(FORWARD); // run motor2 clockwise
  motor2.setSpeed(150); // set motor2 speed 50 percent
  motor3.run(FORWARD); // run motor3 clockwise
  motor3.setSpeed(150); // set motor3 speed 50 percent
  motor4.run(FORWARD); // run motor4 clockwise
  motor4.setSpeed(150); // set motor4 speed 50 percent

}
