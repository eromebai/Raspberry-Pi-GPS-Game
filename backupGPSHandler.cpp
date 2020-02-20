/**
 * @author Kevin Gao
 * GPSHandler class
 */
#include "GPSHandler.h"
#include "math.h"

GPSHandler::GPSHandler()
{
    gps = new GPSD();
}

GPSHandler::~GPSHandler()
{
    delete gps;
}

/**
 * Updates coordinates on gps then returns them
 */
Coord GPSHandler::GetCoordinates()
{
    Coord coord;
    gps->Update();
    coord.x = gps->GetLatitude();
    coord.y = gps->GetLongitude();
    return coord;
}

double GPSHandler::CalculateDistance(Coord current, Coord dest)
{
    Coord diff;
    diff.x = dest.x - current.x;
    diff.y = dest.y - current.y;
    double dist = sqrt(pow(diff.x, 2) + pow(diff.y, 2));

    return dist;
}
