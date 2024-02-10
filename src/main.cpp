#include <Arduino.h>
#include <Wire.h>
#include "ToFLib.h"
#include "MPU6050EH.h"

#define DELAY 1000

MPU6050EH mpuEH;

u_int16_t tof_distance;
u_long imu_timestamp;
u_long current_time;

void setup() {
  Wire.begin();
        Wire.setClock(400000);

   Serial.begin(115200);

    while (!Serial) {
        delay(1);
    }

    Serial.println(F("Initializing I2C devices..."));
    ToF_Setup();

    if(mpuEH.init()) {
      Serial.println("MPU6050 Found!");
    } else {
      Serial.println("Failed to find MPU6050 chip");
    }
  current_time = millis();
}

void loop() {
  //imu_timestamp = micros();
  
  if (millis() - current_time > DELAY) {
    current_time = millis();

    tof_distance = ToF_GetRangeMilliMeter();
    Serial.print("ToF Distance: ");
    Serial.println(tof_distance/10.0);

    if (mpuEH.accelgyroData()) {
      Serial.print("Yaw: ");
      Serial.println(mpuEH.yaw());

      Serial.print("Pitch: ");
      Serial.println(mpuEH.pitch());

      Serial.print("Roll: ");
      Serial.println(mpuEH.roll());

      Serial.print("AccelX: ");
      Serial.println(mpuEH.getAccelX());

      Serial.print("AccelY: ");
      Serial.println(mpuEH.getAccelY());

      Serial.print("AccelZ: ");
      Serial.println(mpuEH.getAccelZ());

    }

  }
}
