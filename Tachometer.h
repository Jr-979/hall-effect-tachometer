
#ifndef Tachometer_h
#define Tachometer_h
#include "Arduino.h"
#endif

class Tachometer
{
  public:
  
	Tachometer(uint8_t magnetPin, uint8_t magnetPerwheel);

  double currentRPS;
  double pi = 3.1415926535897932384626433832795;

  uint8_t begin();
  double getRPM();
  double getRPS();
  double getRadPSec();
  void magnetFound();

  
  private:

  uint8_t _magnetPin;
  uint8_t _magnetPerwheel;
  double currentTime;
  double previousTime;
  

};
