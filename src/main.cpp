#include <Arduino.h>
#include <Wire.h>
#include "ToFLib.h"
#include "MPU6050Lib.h"

MPU6050 mpu;

u_int16_t tof_distance;
u_long imu_timestamp;

void setup() {
  Serial.begin(115200);

    while (! Serial) {
        delay(1);
    }

    ToF_Setup();
    mpu.init(MPU6050_RANGE_8_G, MPU6050_RANGE_250_DEG, MPU6050_BAND_5_HZ);
}

void loop() {
  imu_timestamp = micros();
  float accelX, accelY, accelZ, gyroX, gyroY, gyroZ, temp;
  tof_distance = ToF_GetRangeMilliMeter();
  mpu.getData(accelX, accelY, accelZ, gyroX, gyroY, gyroZ, temp);
  
  Serial.print("ToF distance: ");
  Serial.println(tof_distance);

  Serial.print("Accel X: ");
  Serial.println(accelX);

  Serial.print("Accel Y: ");
  Serial.println(accelY);

  Serial.print("Accel Z: ");
  Serial.println(accelZ);

  Serial.print("Gyro X: ");
  Serial.println(gyroX);

  Serial.print("Gyro Y: ");
  Serial.println(gyroY);

  Serial.print("Gyro Z: ");
  Serial.println(gyroZ);

  Serial.print("Temperature: ");
  Serial.println(temp);

  delay(500);
}
