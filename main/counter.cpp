#include "counter.h"
#include "Arduino.h"

Counter::Counter(const int gpioPin)
    : _gpioPin(gpioPin)
{
    // Setup Pin mode input pull up
    pinMode(_gpioPin, INPUT_PULLUP);
}

long Counter::getValue()
{
    Serial.print("Counter ");
    Serial.print(_gpioPin);
    Serial.print(" value = ");
    Serial.println(_value);

    return _value;
}

void Counter::update()
{
    // Read pin
    bool current_state = digitalRead(_gpioPin);

    if (current_state != _prevState)
    {
        _prevState = current_state;
        _value++;
    }
}