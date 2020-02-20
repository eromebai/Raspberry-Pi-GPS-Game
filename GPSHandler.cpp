#include "GPSHandler.h"
#include "math.h"
using namespace std;

GPSHandler::GPSHandler()
{
    gps = new GPSD();
    
    double destX, destY, x, y;
    destX = 50;
    destY = 50;

    vect.push_back(Coord());
    vect[0].x = destX;
    vect[0].y = destY;
    
    x = 0;
    y = 0;
    int counter = 1;
    
    while(x < destX || y < destY)
    {
        vect.push_back(Coord());
        vect[counter].x = x;
        vect[counter].y = y;
        x += 5;
        y += 5;
        counter ++;
    }
    vect.push_back(Coord());
    vect[counter].x = destX;
    vect[counter].y = destY;
    counter++;
    vect.push_back(Coord());
    vect[counter].x = destX;
    vect[counter].y = destY;
    counter++;
    
    vect.push_back(Coord());
    vect[counter].x = destX;
    vect[counter].y = destY;
    counter++;
    
    destX = 15;
    destY = 15;
    
    vect.push_back(Coord());
    vect[counter].x = destX;
    vect[counter].y = destY;
    counter++;
    
    destX = 10;
    destY = 10;
    
    vect.push_back(Coord());
    vect[counter].x = destX;
    vect[counter].y = destY;
    counter++;
    
    destX = 5;
    destY = 5;
    
    vect.push_back(Coord());
    vect[counter].x = destX;
    vect[counter].y = destY;
    counter++;
    
    
    vect.push_back(Coord());
    vect[counter].x = destX;
    vect[counter].y = destY;
    counter++;
    
    
    destX = 50;
    destY = 50;
    x = 10;
    y = 10;
    
    while(x < destX || y < destY){
        
        vect.push_back(Coord());
        vect[counter].x = x;
        vect[counter].y = y;
        x += 5;
        y += 5;
        counter ++;
        
    }
    
        
    count = 0;
    
}

/**
 * GPSHandler destructor
 */
GPSHandler::~GPSHandler()
{
    delete gps;
}

/**
 * Updates coordinates on gps then returns them
 */
Coord GPSHandler::GetCoordinates()
{
    Coord coord = vect.at(count);
    if(count < vect.size() - 1){
       count++;
    }
    return coord;
}

/**
 * @param coord current
 * @param coord destination
 * @return distance
 */
double GPSHandler::CalculateDistance(Coord current, Coord dest)
{
    Coord diff;
    diff.x = dest.x - current.x;
    diff.y = dest.y - current.y;
    double dist = sqrt(pow(diff.x, 2) + pow(diff.y, 2));

    return dist;
}
