// Arduino Code
#include <Servo.h>
#include <HardwareSerial.h>
 
const int servoPin = 9;
 
Servo servo;
 
void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
}
 
 
void loop() {
  char str[2];
  if(Serial.available() > 0) {
    char data = Serial.read();
    char str[2];
    str[0] = data;
    str[1] = '\0';
    Serial.print(data);
      if (str == "f\0") {
        return;
    }
  }
 
  // scan from 30 to 150 degrees
  int angle = 0;
  for(angle = 30; angle <= 150; angle++) {                                  
    servo.write(angle);              
    delay(60);
    if (str == "f\0") {
        return;
    }              
  }
  // now scan back from 150 to 30 degrees
  for(angle = 150; angle >= 30; angle--) {                                
    servo.write(angle);          
    delay(60);
    if (str == "f\0") {
        return;
    }    
  }
}
