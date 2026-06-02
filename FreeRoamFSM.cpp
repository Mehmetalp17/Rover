// ===== FreeRoamFSM.cpp =====
#include "FreeRoamFSM.h"

void FreeRoamFSM::begin(SkidSteerMotors* m, WaterPump* p) {
    motors_   = m;
    pump_     = p;
    tLastCmd_ = millis();
    motors_->stop();
}

void FreeRoamFSM::update(PiCommand& cmd) {
    if (cmd.fresh) {
        tLastCmd_ = cmd.lastCmdMs;
        switch (cmd.type) {
            case CMD_STOP:
            case CMD_ROAM:       motors_->stop(); break;
            case CMD_FORWARD:    motors_->forward   (cmd.speed ? cmd.speed : SPEED_CRUISE);    break;
            case CMD_REVERSE:    motors_->reverse   (cmd.speed ? cmd.speed : SPEED_REVERSE);   break;
            case CMD_TURN_LEFT:  motors_->pointTurnLeft (cmd.speed ? cmd.speed : SPEED_TURN);  break;
            case CMD_TURN_RIGHT: motors_->pointTurnRight(cmd.speed ? cmd.speed : SPEED_TURN);  break;
            case CMD_PUMP_ON:    pump_->on();  break;
            case CMD_PUMP_OFF:   pump_->off(); break;
            default: break;
        }
    } else if (millis() - tLastCmd_ > SLAVE_TIMEOUT_MS) {
        // Pi sessizleşti — güvenli dur
        pump_->off();
        motors_->stop();
        tLastCmd_ = millis();  // sürekli tekrar tetiklenmesin
    }
}
