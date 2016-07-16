// high speed MG995 TowerPro Servo interface
// 17-07-2016 4:11 am
//  for complete instructions visit my site
// www.KartikNighania.com feel free to contact for any help

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    if(pos==0) delay(2000);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
   if(pos==180) delay(2000);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }
}

