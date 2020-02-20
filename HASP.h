
#ifndef HASP_H
#define HASP_H

#include <iostream>
#include <ctime>
#include <thread>
#include <bits/stdc++.h>
#include "unistd.h"
#include "signal.h"
#include "math.h"
#include "GPSHandler.h"
#include "ButtonManager.h"
#include "LightManager.h"

class HASP: public SigSlotBase{
	public:
		HASP();
		~HASP();
		void start_game();
		
	private:
		FILE *fp;
		int process;
		int jump;
		long start_time;
		long end_time;
		long player1_timeUse;
		long player2_timeUse;
		struct Coord start_location;
		struct Coord object_location;
		struct Coord current_location;
		double distance_percentage;
		struct LightManager* lightManager;
		struct ButtonManager* buttonManager;
		struct GPSHandler* gps;
		void set_object_location();
		void set_start_location_time_and_searching();
		void player1_end();
		void player2_end();
		void player2_start();
		void end_game();
		void nextStage();
		void loop();
};
#endif
