
#ifndef ABSTRACTLIGHT_H
#define ABSTRACTLIGHT_H

class abstractLight{
	public:
		abstractLight();
		~abstractLight();
		virtual void blink() = 0;
		virtual void turnOn() = 0;
		virtual void turnOff() = 0;
		virtual void changeColor(int color) = 0;

	private:
};

#endif
