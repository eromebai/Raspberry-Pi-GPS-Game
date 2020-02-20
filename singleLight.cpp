/**
 * Concerte implementation of abstractlight used for the solid single lights
 * @author Shiyu Wang and Evan Rome-Bailey
 */

#include "singleLight.h"


/**
 * Quickly blinks the light on and off
 */		
void singleLight::blink(){
	digitalWrite(portNum, HIGH);
     
	digitalWrite(portNum, LOW);
};
		
/**
 * turns the light on
 */	
void singleLight::turnOn(){
	digitalWrite(portNum, HIGH);
};

/**
 * turns the light off
 */
void singleLight::turnOff(){
	 digitalWrite(portNum, LOW);

};

void singleLight::changeColor(int){};

/**
 * Initializes the light with the given port
 */
singleLight::singleLight(int num){
	if(wiringPiSetup() < 0) { //when initialize wiringPi failed, print message to screen
	printf("setup wiringPi failed !\n");}
	portNum = num;
	pinMode(portNum, OUTPUT);

};
	
singleLight::~singleLight(){};

	

	

