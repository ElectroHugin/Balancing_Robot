#include <Arduino.h>
#include "ToFLib.h"

u_int16_t tof_distance;

void setup() {
  Serial.begin(115200);

    while (! Serial) {
        delay(1);
    }

    ToF_Setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  tof_distance = ToF_GetRangeMilliMeter();
  delay(1000);
}

// put function definitions here:
