#include <Arduino.h>
#include <Wire.h>
#include "ToFLib.h"
#include "MPU6050EH.h"
#include "DriveLib.h"

#define DELAY 10

MPU6050EH mpuEH;
VL53L0XEH tofEH;
JGA25_371 motor_1;

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

    if (tofEH.init()) {
        Serial.println("VL53L0X Found!");
    } else {
        Serial.println("Failed to find VL53L0X sensor");
    }

    if(mpuEH.init()) {
      Serial.println("MPU6050 Found!");
    } else {
      Serial.println("Failed to find MPU6050 sensor");
    }

    if(motor_1.init()) {
      Serial.println("Motor 1 initialized!");
    } else {
      Serial.println("Failed to initialize Motor 1");
    }
  current_time = millis();
}

void loop() {
  //imu_timestamp = micros();
  
  if (millis() - current_time > DELAY) {
    current_time = millis();

    //Serial.print("rhCount: ");
    //Serial.println(motor_1.getRhCount());
    Serial.print("RH Turns: ");
    Serial.println(motor_1.getRHturns());

    /*if (tofEH.measure()) {
      tof_distance = tofEH.getRangeMilliMeter();
      Serial.print("Distance: ");
      Serial.print(tof_distance);
      Serial.println(" mm");
    } else {
      Serial.println("Failed to measure distance");
    }

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
    } else {
      Serial.println("Failed to get IMU data");
    }

  */
  }
}
