#include "Arduino.h"
#include "Button.h"

Button::Button(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
  _old_val = 0;
  _state = 0;
}

int Button::readState()
{
  int val = digitalRead(_pin);
  int state = _getNewState(val);

  _old_val = val;

  return state;
}

int Button::_getNewState(int val) {
  if ((val == HIGH) && (_old_val == LOW)) {
    _state = 1 - _state;
    delay(20);
  }

  if ((val == LOW) && (_old_val == HIGH)) {
    delay(20);
  }

  return _state;
}
