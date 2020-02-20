/**
 * @brief GPSManager class that manages gps data
 * @author Evan Rome-Bailey, Kevin Gao,Shiyu Wang, Yuankun Li
 */

#include "GPSD.h"
using namespace std;

/**
 * GPS constructor
 */
GPSD::GPSD()
{
  gpsP = new gpsmm("localhost", DEFAULT_GPSD_PORT);
}

/**
 * GPS destructor
 */
GPSD::~GPSD()
{
  delete gpsP;
}

/**
 * @return latitude
 */
double GPSD::GetLatitude()
{
  return latitude;
}

/**
 * @return longitude
 */
double GPSD::GetLongitude()
{
  return longitude;
}

/**
 * method that updates the coordinate variables
 */
void GPSD::Update()
{
  if (gpsP->stream(WATCH_JSON | WATCH_ENABLE) == NULL)
  {
    cerr << "gpsdRec not working n";
    exit(1);
  }
  struct gps_data_t *gpsd_data;

  if ((gpsd_data = gpsP->read()) == NULL)
  {
    cerr << "gpsd data error\n";
    exit(1);
  }
  else
  {
    // get to end of queued coords
    while (((gpsd_data = gpsP->read()) == NULL) ||
           (gpsd_data->fix.mode < MODE_2D))
    {
    }
    latitude = gpsd_data->fix.latitude;
    longitude = gpsd_data->fix.longitude;
  }
}
