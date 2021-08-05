#include <Servo.h>
#include <Wire.h>

Servo servo;
int angle = 10;

int x = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(8);
  servo.write(angle);

  Wire.begin(9);
  Wire.onReceive(receiveEvent);
  
}

void receiveEvent(int bytes){
  x = Wire.read();
}

void loop() {
  if (x == 1){
    for(angle = 10; angle < 180; angle++){
      servo.write(angle);
      delay(15);
    }
  
    for(angle = 180; angle > 10; angle--){
      servo.write(angle);
      delay(15);
    }
  }
}
