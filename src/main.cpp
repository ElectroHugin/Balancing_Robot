#include <Arduino.h>
#include <Wire.h>
#include "ToFLib.h"
#include "IMULib.h"

u_int16_t tof_distance;
u_long imu_timestamp;
float yaw, pitch, roll;

void setup() {
  Serial.begin(115200);

    while (! Serial) {
        delay(1);
    }

    ToF_Setup();
}

void loop() {
  imu_timestamp = micros();
  // put your main code here, to run repeatedly:
  tof_distance = ToF_GetRangeMilliMeter();
  yaw = getYaw();
  pitch = getPitch();
  roll = getRoll();

  Serial.print("ToF distance: ");
  Serial.println(tof_distance);

  Serial.print("Yaw: ");
  Serial.println(yaw);

  Serial.print("Pitch: ");
  Serial.println(pitch);

  Serial.print("Roll: ");
  Serial.println(roll);
  delay(1000);
}
