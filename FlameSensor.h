// ===== FlameSensor.h =====
#ifndef FLAME_SENSOR_H
#define FLAME_SENSOR_H

#include <Arduino.h>
#include "Config.h"

// Analog flame sensor. Ateş varken analog değer düşer.
class FlameSensor {
public:
  void begin() { pinMode(PIN_FLAME_AO, INPUT); }
  uint16_t raw() const { return analogRead(PIN_FLAME_AO); }
};

#endif