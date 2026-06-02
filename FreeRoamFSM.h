// ===== FreeRoamFSM.h =====
// Arduino artık tamamen Pi'nin komut kölesi.
// Tüm navigasyon ve ateş misyonu mantığı Pi'de.
// Bu sınıf: gelen komutu al → motoru/pompayı çalıştır.
// Pi susarsa SLAVE_TIMEOUT_MS sonra dur.
#ifndef FREE_ROAM_FSM_H
#define FREE_ROAM_FSM_H

#include <Arduino.h>
#include "Config.h"
#include "SkidSteerMotors.h"
#include "WaterPump.h"
#include "SerialLink.h"

class FreeRoamFSM {
public:
    void begin(SkidSteerMotors* m, WaterPump* p);
    void update(PiCommand& cmd);

private:
    SkidSteerMotors* motors_   = nullptr;
    WaterPump*       pump_     = nullptr;
    unsigned long    tLastCmd_ = 0;
};

#endif
