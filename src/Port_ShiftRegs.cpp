#include "Port_ShiftRegs.h"

Port_ShiftRegs::Port_ShiftRegs(const uint8_t slaveSelect) : slaveSelect(slaveSelect)
{
    pinMode(slaveSelect, OUTPUT);
}

/* begin() should be called once from sketch setup().
Initializes shift register's shift/load pin.
*/
void Port_ShiftRegs::begin()
{
    digitalWrite(slaveSelect, HIGH);
    SPI.begin();
}

/* writeLow() sets pin output LOW.
pin is bit pattern, where pin being set is 1.
*/
void Port_ShiftRegs::writeLow(const uint8_t pin)
{
    outputVal &= ~pin;                          //set pin output to low

    digitalWrite(slaveSelect, LOW);
    SPI.transfer(outputVal);
    digitalWrite (slaveSelect, HIGH);
}

/* writeHigh() sets pin output HIGH.
pin is bit pattern, where pin being set is 1.
*/
void Port_ShiftRegs::writeHigh(const uint8_t pin)
{
    outputVal |= pin;                           //set pin output to high

    digitalWrite(slaveSelect, LOW);
    SPI.transfer(outputVal);
    digitalWrite (slaveSelect, HIGH);
}
