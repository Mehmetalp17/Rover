// ===== SkidSteerMotors.cpp =====
#include "SkidSteerMotors.h"

void SkidSteerMotors::begin() {
  pinMode(PIN_LEFT_IN1, OUTPUT);  pinMode(PIN_LEFT_IN2, OUTPUT);  pinMode(PIN_LEFT_ENA, OUTPUT);
  pinMode(PIN_RIGHT_IN3, OUTPUT); pinMode(PIN_RIGHT_IN4, OUTPUT); pinMode(PIN_RIGHT_ENB, OUTPUT);
  stop();
}
void SkidSteerMotors::drive(int l, int r) {
  setSide(PIN_LEFT_IN1, PIN_LEFT_IN2, PIN_LEFT_ENA, l);
  setSide(PIN_RIGHT_IN3, PIN_RIGHT_IN4, PIN_RIGHT_ENB, r);
}
void SkidSteerMotors::forward(uint8_t s) { drive(s, s); }
void SkidSteerMotors::reverse(uint8_t s) { drive(-(int)s, -(int)s); }
void SkidSteerMotors::stop()             { drive(0, 0); }
void SkidSteerMotors::pointTurnLeft(uint8_t s)  { drive(-(int)s, (int)s); }
void SkidSteerMotors::pointTurnRight(uint8_t s) { drive((int)s, -(int)s); }

void SkidSteerMotors::setSide(uint8_t inA, uint8_t inB, uint8_t en, int speed) {
  if (speed > 0)      { digitalWrite(inA, HIGH); digitalWrite(inB, LOW);  }
  else if (speed < 0) { digitalWrite(inA, LOW);  digitalWrite(inB, HIGH); }
  else                { digitalWrite(inA, LOW);  digitalWrite(inB, LOW);  }
  int mag = speed; if (mag < 0) mag = -mag; if (mag > 255) mag = 255;
  analogWrite(en, (uint8_t)mag);
}