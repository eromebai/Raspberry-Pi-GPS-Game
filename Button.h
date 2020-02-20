#include <wiringPi.h>
#include <stdio.h>
#include <iostream>

#ifndef BUTTON_H
#define BUTTON_H

class Button{
	
	public:
		Button();
		bool isClicked();
		
	
	private:
	
		int buttonNum;
	
	};

#endif
