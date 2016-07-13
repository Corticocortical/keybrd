#ifndef LED_PCA9655E_H
#define LED_PCA9655E_H
#include <Arduino.h>
#include <inttypes.h>
#include <Wire.h>
#include <LED.h>
#include <StrobePort_PCA9655E.h>

/* A LED_PCA9655E object is an PCA9655E pin that is connected to an LED indicator light.
Input/Ouput Direction configuration are set to ouput in StrobePort_PCA9655E.begin() and ReadPort_PCA9655E.begin().
*/
class LED_PCA9655E: public LED
{
    private:
        //IOEPort& port;
        //const uint8_t outputByteCommand;        //General Purpose Input/Ouput register address
        StrobePort_PCA9655E& refPort;
        const uint8_t pin;                      //bitwise pin to LED

    public:
        LED_PCA9655E(StrobePort_PCA9655E& refPort, const uint8_t pin)
            : refPort(refPort), pin(pin) {}

        virtual void on();
        virtual void off();
};
#endif
