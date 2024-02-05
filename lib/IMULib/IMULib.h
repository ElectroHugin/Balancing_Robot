#ifndef IMULIB_H
#define IMULIB_H

// Include any necessary headers here
#include <Adafruit_BNO08x.h>

/* global definitions */

#define BNO08X_CS 10
#define BNO08X_INT 9
#define BNO08X_RESET -1

/* global objects */
extern Adafruit_BNO08x bno08x;
extern struct euler_t ypr;
extern sh2_SensorValue_t sensorValue;

/* global functions */
void IMU_Setup();
void setReports(sh2_SensorId_t reportType, long report_interval);
void quaternionToEuler(float qr, float qi, float qj, float qk, euler_t* ypr, bool degrees = false);
void quaternionToEulerRV(sh2_RotationVectorWAcc_t* rotational_vector, euler_t* ypr, bool degrees = false);
void quaternionToEulerGI(sh2_GyroIntegratedRV_t* rotational_vector, euler_t* ypr, bool degrees = false);
float getYaw();
float getPitch();
float getRoll();


#endif // IMULIB_H
