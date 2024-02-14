#include "DriveLib.h"


volatile long rhCount = 0;
volatile long lhCount = 0;

/**
 * @brief Default constructor for the DriveLib class.
 */

JGA25_371::JGA25_371() {
    //
}

/**
 * @brief Destructor for the DriveLib class.
 */

JGA25_371::~JGA25_371() {
    //
}

/**
 * @brief Initializes the DriveLib class.
 * @return
 * 
 * @return True if initialization is successful, false otherwise.
 */ 

bool JGA25_371::init() {
    bool initSuccess = false;
    pinMode(RH_ENCODER_A, INPUT);
    pinMode(RH_ENCODER_B, INPUT);
    attachInterrupt(digitalPinToInterrupt(RH_ENCODER_A), rhEncoderEvent, CHANGE);
    attachInterrupt(digitalPinToInterrupt(RH_ENCODER_B), lhEncoderEvent, CHANGE);
    initSuccess = true;
    return initSuccess;
}

long JGA25_371::getRhCount() {
    return rhCount;
}

long JGA25_371::getRHturns() {
    return rhCount / pulse_per_revolution;
}

long JGA25_371::getLhCount() {
    return lhCount;
}

long JGA25_371::getLHturns() {
    return lhCount / pulse_per_revolution;
}

void IRAM_ATTR rhEncoderEvent() {
    if (digitalRead(RH_ENCODER_A) == HIGH) {
      if (digitalRead(RH_ENCODER_B) == LOW) {
        rhCount++;
      }
      else if (digitalRead(RH_ENCODER_B) == HIGH) {
        //rhCount--;
      }
    }
    else if (digitalRead(RH_ENCODER_A) == LOW) {
      if (digitalRead(RH_ENCODER_B) == LOW) {
        rhCount--;
      }
      else if (digitalRead(RH_ENCODER_B) == HIGH) {
        //rhCount++;
      }
    }
}

void IRAM_ATTR lhEncoderEvent() {
    if (digitalRead(LH_ENCODER_A) == HIGH) {
      if (digitalRead(LH_ENCODER_B) == LOW) {
        lhCount++;
      }
      else if (digitalRead(LH_ENCODER_B) == HIGH) {
        //lhCount--;
      }
    }
    else if (digitalRead(LH_ENCODER_A) == LOW) {
      if (digitalRead(LH_ENCODER_B) == LOW) {
        lhCount--;
      }
      else if (digitalRead(LH_ENCODER_B) == HIGH) {
        //rhCount++;
      }
    }
}
