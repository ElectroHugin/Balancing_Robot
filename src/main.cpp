#include <Arduino.h>
#include <Wire.h>
#include "ToFLib.h"
#include "MPU6050EH.h"

MPU6050EH mpuEH;

u_int16_t tof_distance;
u_long imu_timestamp;

void setup() {
  Serial.begin(115200);

    while (!Serial) {
        delay(1);
    }

    ToF_Setup();
    if(mpuEH.init()) {
      Serial.println("MPU6050 Found!");
    } else {
      Serial.println("Failed to find MPU6050 chip");
    }
}

void loop() {
  imu_timestamp = micros();
  float accelX, accelY, accelZ, yaw, pitch, roll, temp;
  tof_distance = ToF_GetRangeMilliMeter();
  mpuEH.accelgyroData();
  /*
  Serial.print("ToF distance: ");
  Serial.println(tof_distance);

  Serial.print("Accel X: ");
  Serial.println(mpuEH.getAccelX());

  Serial.print("Accel Y: ");
  Serial.println(mpuEH.getAccelY());

  Serial.print("Accel Z: ");
  Serial.println(mpuEH.getAccelZ());

  Serial.print("Yaw: ");
  Serial.println(mpuEH.yaw());

  Serial.print("Pitch: ");
  Serial.println(mpuEH.pitch());

  Serial.print("Roll: ");
  Serial.println(mpuEH.roll());

  Serial.print("Temperature: ");
  Serial.println(mpuEH.getTemp());
  */
  delay(500);
}
