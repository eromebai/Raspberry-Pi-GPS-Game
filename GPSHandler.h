#ifndef GPS_HANDLER_H
#define GPS_HANDLER_H
#include <vector>
#include "Coord.h"
#include "GPSD.h"
class GPSHandler
{

public:
    GPSHandler();
    ~GPSHandler();
    Coord GetCoordinates();
    double CalculateDistance(Coord c1, Coord c2);

private:
	std::vector<Coord> vect;
    void GPSThread();
    GPSD * gps;
    int count;
};

#endif
