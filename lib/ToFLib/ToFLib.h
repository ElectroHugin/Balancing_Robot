#ifndef TOFLIB_H
#define TOFLIB_H

// Include any necessary headers here
#include "Adafruit_VL53L0X.h"

/* global objects */
extern Adafruit_VL53L0X tof_sensor;
extern VL53L0X_RangingMeasurementData_t measurement;

/* global functions */
void ToF_Setup();
uint16_t ToF_GetRangeMilliMeter();


#endif // TOFLIB_H
