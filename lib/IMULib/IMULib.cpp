#include "IMULib.h"

Adafruit_BNO08x bno08x = Adafruit_BNO08x(BNO08X_RESET);
struct euler_t {
  float yaw;
  float pitch;
  float roll;
} ypr;

sh2_SensorValue_t sensorValue;

sh2_SensorId_t reportType = SH2_ARVR_STABILIZED_RV;
long reportIntervalUs = 5000;

void setReports(sh2_SensorId_t reportType, long report_interval) {
  Serial.println("Setting desired reports");
  if (! bno08x.enableReport(reportType, report_interval)) {
    Serial.println("Could not enable stabilized remote vector");
  }
}

void IMU_Setup() {
    //Serial.println("Adafruit BNO08x test!");

    // Try to initialize!
    if (!bno08x.begin_I2C()) {
    //if (!bno08x.begin_UART(&Serial1)) {  // Requires a device with > 300 byte UART buffer!
    //if (!bno08x.begin_SPI(BNO08X_CS, BNO08X_INT)) {
        //Serial.println("Failed to find BNO08x chip");
        while (1) { delay(10); }
    }
    //Serial.println("BNO08x Found!");

    setReports(reportType, reportIntervalUs);

    //Serial.println("Reading events");
}

void quaternionToEuler(float qr, float qi, float qj, float qk, euler_t* ypr, bool degrees) {

    float sqr = sq(qr);
    float sqi = sq(qi);
    float sqj = sq(qj);
    float sqk = sq(qk);

    ypr->yaw = atan2(2.0 * (qi * qj + qk * qr), (sqi - sqj - sqk + sqr));
    ypr->pitch = asin(-2.0 * (qi * qk - qj * qr) / (sqi + sqj + sqk + sqr));
    ypr->roll = atan2(2.0 * (qj * qk + qi * qr), (-sqi - sqj + sqk + sqr));

    if (degrees) {
      ypr->yaw *= RAD_TO_DEG;
      ypr->pitch *= RAD_TO_DEG;
      ypr->roll *= RAD_TO_DEG;
    }
}

void quaternionToEulerRV(sh2_RotationVectorWAcc_t* rotational_vector, euler_t* ypr, bool degrees) {
    quaternionToEuler(rotational_vector->real, rotational_vector->i, rotational_vector->j, rotational_vector->k, ypr, degrees);
}

void quaternionToEulerGI(sh2_GyroIntegratedRV_t* rotational_vector, euler_t* ypr, bool degrees) {
    quaternionToEuler(rotational_vector->real, rotational_vector->i, rotational_vector->j, rotational_vector->k, ypr, degrees);
}

float getYaw() {
    quaternionToEulerRV(&sensorValue.un.arvrStabilizedRV, &ypr, true);
    return ypr.yaw;
}

float getPitch() {
    quaternionToEulerRV(&sensorValue.un.arvrStabilizedRV, &ypr, true);
    return ypr.pitch;
}

float getRoll() {
    quaternionToEulerRV(&sensorValue.un.arvrStabilizedRV, &ypr, true);
    return ypr.roll;
}
