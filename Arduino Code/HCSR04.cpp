/****************************
 * Thomas Pannozzo
 * HCSR04ProxSensor.cpp
*****************************/

#include "HCSR04.h"

HCSR04ProxSensor::HCSR04ProxSensor() {}		//default constructor

HCSR04ProxSensor::HCSR04ProxSensor(int echo, int trigger) {
	distance = -1;					/*	Sets up a flag so garbage memory is not accidentally used if 
										distance's value is queried before the proximity sensor puts a new value into it. */
	lastValueDistance = -1;
	
	echoPin = echo;					//Saves user input as object variables
	triggerPin = trigger;
	
	pinMode(echoPin, INPUT);		//Sets up inputs and outputs
	pinMode(triggerPin, OUTPUT);
	

}


double HCSR04ProxSensor::readSensor(void){
	
	lastValueDistance = distance;
	
	digitalWrite(triggerPin, HIGH);						//pulse
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);
	double temp = pulseIn(echoPin, HIGH);
	distance = temp / 58;
	
	if (distance > 400) readSensor();		/*	Proximity sensor is equipped to read from 2 to 400 cm, if value greater than this is 
												received, an error has occured, continue scanning until valid entry is received */
	else				return distance; 
}

double HCSR04ProxSensor::getLastValue(void){
	
	return lastValueDistance;
	
}