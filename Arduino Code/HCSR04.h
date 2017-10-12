/****************************
 * Thomas Pannozzo
 * HCSR04ProxSensor.h
*****************************/

#ifndef HCSR04PROXSENSOR_h											//prevents defining same class twice
#define HCSR04PROXSENSOR_h

#include "Arduino.h"

class HCSR04ProxSensor {
	
	public:
		explicit HCSR04ProxSensor();								//Default Constructor
		explicit HCSR04ProxSensor(int echo, int trigger);			//Constructor, accepts 
		
		double readSensor(void);									//Returns float of sensor in cm
		double getLastValue(void);									//Returns previous reading
		
		private:			
			double distance;										//float of distance, most recent call
			double lastValueDistance; 								//"distance" gets passed into this each loop
			int echoPin;
			int triggerPin;
};

#endif //HCSR04PROXSENSOR_h