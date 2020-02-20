/**
 * Factory which returns abstract lights, decides whether to make a solidLight or a LED based on client input
 * \author Shiyu Wang and Evan Rome-Bailey
 */
 
#include "lightFactory.h"


using namespace std;

lightFactory::lightFactory(){};

/**
 * Uses client input to determine what type of light to create and which port to assign
 */

abstractLight* lightFactory::createLight(int num){
	if(num == 0){
		
	singleLight *blue = new singleLight(0);
	return blue;
		
		}
	else if(num == 1){
	singleLight *yellow = new singleLight(2);
	return yellow;

		}
	else if(num == 2){
		
	singleLight *green = new singleLight(3);
	return green;

		}
	else if(num == 3){
		
	singleLight *red = new singleLight(25);
	return red;
	
		}
		
	else if(num == 4){
		rgbLED *led = new rgbLED();
		return led;
	}				
	else{
		return NULL;
		}
	
	
	}
