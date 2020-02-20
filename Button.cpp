/**
 * @author Shiyu Wang
 * Button Class for breadboard
 */
#include "Button.h"

/**
 * Button Constructor
 */
Button::Button(){
	if(wiringPiSetup() < 0) { //when initialize wiringPi failed, print message to screen
		printf("setup wiringPi failed !\n");
		return;
		
}

};

/**
 * checks for button click
 * @return boolean isclicked
 */
bool Button::isClicked(){
	buttonNum = 1;
	
	pinMode(buttonNum,INPUT);
	pullUpDnControl(buttonNum, PUD_UP);

	if(digitalRead(buttonNum) == LOW){
			return true;
			
	}
	
	return false;
	
	
	}
	

