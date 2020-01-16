#include<Arduino.h>
#include<AFMotor.h> //Knihovna ovládající motory.

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

#define LEFT_SENSOR A0 // připojení levého senzoru na analogový pin A0.
#define RIGHT_SENSOR A1 // připojení pravého senzoru na analogový pin A1.
int rychlost= 80;
int zatacka = 150;

void setup() {
  
pinMode(RIGHT_SENSOR, INPUT); // inicializace pravého senzoru jako input.
pinMode(LEFT_SENSOR, INPUT); // inicializace levého senzoru jako input.

}

void loop() {
if(analogRead(RIGHT_SENSOR)<=35 && analogRead(LEFT_SENSOR)<=35) //porovnání obou hodnot které posílá senzor aby mohl být nastaven směr jízdy.
{
  motor1.run(FORWARD);
  motor1.setSpeed(rychlost); 
  motor2.run(FORWARD);
  motor2.setSpeed(rychlost);
  motor3.run(FORWARD); 
  motor3.setSpeed(rychlost); 
  motor4.run(FORWARD); 
  motor4.setSpeed(rychlost);
}
 else if(!analogRead(RIGHT_SENSOR)<=35 && analogRead(LEFT_SENSOR)<=35) //porovnání obou hodnot které posílá senzor aby mohl být nastaven směr jízdy.
 {
  motor1.run(FORWARD); 
  motor1.setSpeed(zatacka); 
  motor2.run(FORWARD); 
  motor2.setSpeed(zatacka); 
  motor3.run(BACKWARD); 
  motor3.setSpeed(zatacka);
  motor4.run(BACKWARD); 
  motor4.setSpeed(zatacka);
  
}
 else if(analogRead(RIGHT_SENSOR)<=35 && !analogRead(LEFT_SENSOR)<=35) //porovnání obou hodnot které posílá senzor aby mohl být nastaven směr jízdy.
 {
  motor1.run(BACKWARD); 
  motor1.setSpeed(zatacka); 
  motor2.run(BACKWARD); 
  motor2.setSpeed(zatacka); 
  motor3.run(FORWARD);  
  motor3.setSpeed(zatacka);
  motor4.run(FORWARD); 
  motor4.setSpeed(zatacka);
}
else if(!analogRead(RIGHT_SENSOR)<=35 && !analogRead(LEFT_SENSOR)<=35) //porovnání obou hodnot které posílá senzor aby mohl být nastaven směr jízdy.
{
  //Zastavení motorů v případě, že oba senzory narazily na čáru.
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
 }
}