#ifndef PRAC_LIGHTMANAGER_H
#define PRAC_LIGHTMANAGER_H

#include "lightFactory.h"
#include <thread>
#include <unistd.h>
#include <math.h>
#include <iostream>

class LightManager{
	
	public:
	LightManager();
	void updateState(int);
	void updateDistance(int);
	
	
	private:
	abstractLight* BlueLight;
	abstractLight* YellowLight;
	abstractLight* GreenLight;
	abstractLight* RedLight;
	abstractLight* LEDLight;
	abstractLight* currentLight;	
	
	int blinkrate;
	bool state3running;
	
	void state1();
	void state2();
	void state3();
	void state4();
	
	void blinker();
	 
	
};

#endif
