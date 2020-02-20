#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include "abstractLight.h"

#define REDPORTNUM    24
#define GREENPORTNUM  4
#define RED 0x00FF00
#define GREEN 0xFF0000


class rgbLED : public abstractLight{
	public:
		
		void blink();
		void turnOn();
		void turnOff();
		void changeColor(int color);
		int map(int ,int, int, int, int);

		rgbLED();
		~rgbLED();
	
	private:
	
	
	
	};
