/**
 * Class which controls lights and makes them respond correctly to game data
 * \author Evan Rome-Bailey
 */

#include "LightManager.h"

/**
 * Contructor class
 */
LightManager::LightManager(){
	
	lightFactory *fact = new lightFactory();
	
	BlueLight = fact->createLight(0);
	YellowLight = fact->createLight(1);
	GreenLight = fact->createLight(2);
	RedLight = fact->createLight(3);
	LEDLight = fact->createLight(4);
	currentLight = BlueLight;
	
	BlueLight->turnOff();
	YellowLight->turnOff();
	GreenLight->turnOff();
	RedLight->turnOff();
	LEDLight->turnOff();
	
	state3running = false;	
	blinkrate = 100;
}

void LightManager::updateState(int state){
	
	switch(state){
		
		case 1:
			state1();
			break;
			
		case 2:
			state2();
			break;
			
		case 3:
			state3();
			break;
			
		case 4:
			state4();
			break;
		
	}
}

/**
 * Method which is called by the main game to control blinking speed while searching
 */
void LightManager::updateDistance(int dist){
	
	blinkrate = dist;	
	
}

/**
 * Method for entering state 1, sets on blue light
 */
void LightManager::state1(){
	
	state3running = false;
	currentLight->turnOff();
	BlueLight->turnOn();
	currentLight = BlueLight;
	
}

/**
 * Method for entering state 2, sets on yellow light
 */
void LightManager::state2(){
	
	state3running = false;
	currentLight->turnOff();
	YellowLight->turnOn();
	currentLight=YellowLight;
		
}

/**
 * Method for entering state 3, sets on green light and starts loop which controls LED blinkspeed and colour
 */
void LightManager::state3(){
	
	state3running = true;
	blinkrate = 100;
	currentLight->turnOff();
	GreenLight->turnOn();
	currentLight = GreenLight;
	LightManager * lm = this;
	std::thread b(&LightManager::blinker, lm);
	b.detach();
	
}

/**
 * Method for entering state 4, sets on red light and kills LED, turns red light off after 2 seconds signifying the end of the game
 */
void LightManager::state4(){
	
	state3running = false;
	LEDLight->turnOff();
	currentLight->turnOff();
	RedLight->turnOn();
	currentLight = RedLight;
	delay(2000);
	RedLight->turnOff();
	
}

/**
 * Method used for controlling the colour and blink speed of the LED, using data from main game and gps, speeds up blinking while getting closer. red light shows youve moved further away
 */
void LightManager::blinker(){
	
	int last = 500;
	int col = 0xFF0000;
	int waitTime;
	
	while(state3running){
				
		if(last < blinkrate){
			col = 0x00FF00;
		}
		else if(last > blinkrate){
			col = 0xFF0000;
		}
		
				
		last = blinkrate;
		
		waitTime = pow(blinkrate, 3);
		
		LEDLight->changeColor(col);
		
		usleep(waitTime);
		
		LEDLight->turnOff();
		
		usleep(waitTime);				
	
	}
}



