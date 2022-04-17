#include "Tachometer.h"


/// Create an instance of a Tachometer  
Tachometer::Tachometer(uint8_t magnetPin, uint8_t magnetPerwheel)
{
	_magnetPin = magnetPin;
	_magnetPerwheel = magnetPerwheel;
	currentTime = 0;
	previousTime = 0;
	currentRPS = 0;
	
}

uint8_t Tachometer::begin(){

	pinMode(_magnetPin, INPUT);

}

void Tachometer::magnetFound(){

	currentTime = micros();
    double deltaTIme = (currentTime - previousTime) / 1.0e6;
    double speed = 1 / deltaTIme;
    currentRPS = speed / _magnetPerwheel;

    previousTime = currentTime;
}

double Tachometer::getRPM(){
	return currentRPS*60;
}

double Tachometer::getRPS(){
	return currentRPS;
}
double Tachometer::getRadPSec(){
	return 2*pi*currentRPS;
}