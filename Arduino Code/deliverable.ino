//Thomas Pannozzo, Code for Venus Fly Trap Project

#include "HCSR04.h"                                       //Prox Sensor library
#include <Servo.h>                                        //Servo library

#define servopin 7                                        //Pins for servo & prox sensor
#define echoPin 8
#define triggerPin 9

HCSR04ProxSensor distanceSensor(echoPin,triggerPin);      //Creates servo & prox sensor objects
Servo myservo;

void setup() {
  Serial.begin(9600);                                     //Creates serial line 
  delay(1000);
  
}

void loop() {
  double distance_CM = distanceSensor.readSensor();       //Creates a double which updates each loop with current position from prox sensor in CM
  
  Serial.print(distance_CM);
  Serial.print("\n");

   if (distance_CM < 5){ 
   //If hand gets within 5 cm, shut jaw
      delay(1);
      myservo.attach(servopin);   //Connects continuous servo to power
      myservo.write(180);           //Unwinds fishing line connected to servo, letting jaw drop
      delay(500);      //Servo unwinds for this long
      myservo.detach();           //Disconnect from power
      delay(2000);                //Jaw stays shut for this long
      myservo.attach(servopin);   //Reconnect to power
      myservo.write(1);         //Rewind fishing line to servo, retracting jaw to upright position
      delay(500);        //Servo winds for this long
      myservo.detach();           //Disconnect from power, does not reconnect until prox sensor detects another 5 cm distance
      delay(5000);
      Serial.print("Done\n");
    }
}
