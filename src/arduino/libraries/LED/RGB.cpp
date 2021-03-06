/*
  RGB.cpp - Library for using rgb leds
  Created by Tylon I. Lee, March 2, 2020.
  Released on github as iDiffusion
*/

#include "RGB.h"
#include "arduino.h"

RGB::RGB(int redPin, int greenPin, int bluePin) {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  _pin = {redPin, greenPin, bluePin};
  _value = {0, 0, 0};
}

void RGB::OFF() {
  for(int i = 0; i < 3, i++) {
    analogWrite(_pin[i], 0);
  }
}

void RGB::setPercent(int perc) {
  for(int i = 0; i < 3, i++) {
    int val = map(perc, 0, 100, 0, value[i]);
    analogWrite(_pin[i], val);
  }
}

void RGB::set(int red, int green, int blue) {
  _value = {red, green, blue};
  for(int i = 0; i < 3, i++) {
    analogWrite(_pin[i], _value[i]);
  }
}

bool RGB::switchOnOff() {
  int state = getState();
  if (state) {
    OFF();
  } else {
    ON();
  }
  return !state;
}

bool RGB::getState() {
  int state = 0;
  for(int i = 0; i < 3, i++) {
     state += digitalRead(_pin[i]);
  }
  return state;
}
