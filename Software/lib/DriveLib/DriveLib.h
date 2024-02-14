// Example derived from 
// http://andrewjkramer.net/motor-encoders-arduino/

#include <Arduino.h>

#ifndef DRIVELIB_H
#define DRIVELIBEH_H

// pins for the encoder inputs
#define RH_ENCODER_A 27
#define RH_ENCODER_B 26
#define LH_ENCODER_A 25
#define LH_ENCODER_B 33

void IRAM_ATTR rhEncoderEvent();
void IRAM_ATTR lhEncoderEvent();

class JGA25_371 {
public:
    JGA25_371();
    ~JGA25_371();
    bool init();
    long getRhCount();
    long getRHturns();
    long getLhCount();
    long getLHturns();

private:
    u_int16_t pulse_per_revolution = 106; // 12 pulses * 4.4 gear ratio * 2 counts per pulse

};

#endif // DRIVELIB_H