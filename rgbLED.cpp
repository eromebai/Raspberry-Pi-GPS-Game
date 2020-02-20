/**
 * Concerte implementation of abstractlight used for the blinking LED
 * \author Shiyu Wang
 */

#include "rgbLED.h"


/**
 * Contructor which innitialized wiringPi
 */
rgbLED::rgbLED(){
	if(wiringPiSetup() < 0) { //when initialize wiringPi failed, print message to screen
	printf("setup wiringPi failed !\n");
	return;
	}};

rgbLED::~rgbLED(){};


void rgbLED::blink(){
	};
void rgbLED::turnOn(){};

/**
 * Shuts off the LED
 */
void rgbLED::turnOff(){
	changeColor(0xFFFFFF);
	delay(10);
};

/**
 * Used for getting the correct colour to display from the LED
 */
int rgbLED::map(int x, int in_min, int in_max, int out_min, int out_max)
{
	return (x -in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/**
 * Changes the colour of the LED 
  */
void rgbLED::changeColor(int color){

	int redValue, greenValue;

	
	softPwmCreate(REDPORTNUM,  0, 100);  
	softPwmCreate(GREENPORTNUM,0, 100);
	

	redValue = (color & 0xFF0000) >> 16;  
	greenValue = (color & 0x00FF00) >> 8;  

	redValue = map(redValue, 0, 255, 0, 100);  
	greenValue = map(greenValue, 0, 255, 0, 100);

	softPwmWrite(REDPORTNUM,   100 - redValue); 
	softPwmWrite(GREENPORTNUM, 100 - greenValue);

	
};

