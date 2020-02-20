/**
 * GPSManager header 
 * @author Evan Rome-Bailey, Kevin Gao,Shiyu Wang, Yuankun Li
 */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <libgpsmm.h>
#include <string>

#include "Coord.h"

class GPSD
{
	public:
	GPSD();
	~GPSD();
	double GetUptime();
	double GetLongitude();
	double GetLatitude();

	void Update();
	
	private:
	gpsmm * gpsP;
	std::string uptime;
	double longitude, latitude;
};
	
