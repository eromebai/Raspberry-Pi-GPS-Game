#include <iostream>
#include <wiringPi.h>
#include "abstractLight.h"

class singleLight : public abstractLight{
	
	public:
		
		void blink();
		void turnOn();
		void turnOff();
		void changeColor(int color);

		singleLight(int num);
		~singleLight();

	private:
		int portNum;
		
		
};
