
#include "singleLight.h"
#include "rgbLED.h"

class lightFactory{
	public:
		
		lightFactory();
		abstractLight* createLight(int);

	private:
};
