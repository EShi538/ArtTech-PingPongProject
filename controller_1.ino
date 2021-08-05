#include <Wire.h>

const int trigPin = 9;
const int echoPin = 10;

const int distanceToDetect = 60;

long duration;
int distance;


void setup() {
  Wire.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*.034/2;

  Wire.beginTransmission(9);
  if(distance <= distanceToDetect){

    
    Wire.write(1);

    
    Serial.print(distance);
    Serial.println("   I see something!");
  }else{
    Wire.write(0);
  }
  
  Wire.endTransmission();
}
