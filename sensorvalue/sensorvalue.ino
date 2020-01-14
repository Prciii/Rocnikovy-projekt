#define LEFT_SENSOR A0 // connect the Left sensor with analog pin A0
#define RIGHT_SENSOR A1 // connect the Right sensor with analog pin A1

//Variables:
int l;
int r;


void setup(){
  
  pinMode(LEFT_SENSOR, INPUT);  //Set pin 3 as 'input'
  pinMode(RIGHT_SENSOR, INPUT);
  Serial.begin(115200);       //Begin serial communication

}

void loop(){
  
  l = analogRead(LEFT_SENSOR);         //Read and save digital value from ir sensor
  r = analogRead(RIGHT_SENSOR);
  Serial.println(r);               //Print value
 
}
