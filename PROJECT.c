#include <Servo.h>  
// defines pins numbers
const int trigPin = 9;
const int echoPin = 8;
const int lm1=7;
const int lm2=6;
const int rm1=5;
const int rm2=4;
const int servoPin=10;

Servo myservo;

// defines variables
long duration;
int distance;
int distance_f;
int distance_r;
int distance_l;
int maxLowDistance=30;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

pinMode(lm1,OUTPUT);
pinMode(lm2,OUTPUT);
pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT);

myservo.attach(servoPin);
myservo.write(90);

Serial.begin(9600); // Starts the serial communication
}
void loop() {
   distance_f=ping();
   if(distance_f > maxLowDistance){
     front();
     delay(300);
   }else{
      Break();
      get_Distance();
      if(distance_r > maxLowDistance){
        right();
        delay(700);
        front();
      }else if(distance_l > maxLowDistance){
        left();
        delay(700);
        front();
      }else{ 
        back();
        delay(1000);
        Break();
      }
    