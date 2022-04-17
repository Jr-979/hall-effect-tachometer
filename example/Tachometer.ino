#include "Tachometer.h"

const uint8_t magnetPin = 12;
const uint8_t magnetPerWheel = 1;

Tachometer rpmcount(magnetPin, magnetPerWheel);

void setup()
{
    pinMode(13, OUTPUT);
    digitalWrite(13,HIGH);
    rpmcount.begin();
    attachInterrupt(magnetPin, detected, FALLING);
    Serial.begin(115200);

}
void loop()
{
    double rpm = rpmcount.getRPM();
    Serial.print("RPM  : ");
    Serial.println(rpm);

}

void detected(){
    rpmcount.magnetFound();
}
