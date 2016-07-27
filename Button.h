#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button
{
 public:
  Button(int pin);
  int readState();
 private:
  int _pin;
  int _old_val;
  int _state;
  int _getNewState(int val);
};

#endif
