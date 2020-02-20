all:
	g++ -Wall -std=c++14 GPSD.cpp GPSHandler.cpp Button.cpp ButtonManager.cpp signal.cpp HASP.cpp main.cpp LightManager.cpp lightFactory.cpp singleLight.cpp rgbLED.cpp abstractLight.cpp -o main -lgps -lpthread -lwiringPi -g
