#include "ToFLib.h"

Adafruit_VL53L0X tof_sensor = Adafruit_VL53L0X();
VL53L0X_RangingMeasurementData_t measurement;

/**
 * @brief Set up the Time-of-Flight (ToF) sensor.
 * 
 * This function initializes the ToF sensor and checks if it successfully boots.
 * If the sensor fails to boot, the function prints an error message and enters an infinite loop.
 */
void ToF_Setup() {
    //Serial.println("VL53L0X sensor test");
    if (!tof_sensor.begin()) {
        Serial.println(F("Failed to boot VL53L0X"));
        while (1);
    }
}

/**
 * @brief Get the range in millimeters from the Time-of-Flight (ToF) sensor.
 * 
 * This function reads a measurement from the ToF sensor and returns the range in millimeters.
 * If the measurement is successful, the range value is returned. If there is a phase failure,
 * the function returns -1 to indicate an out-of-range measurement.
 * 
 * @return uint16_t The range in millimeters, or -1 if the measurement is out of range.
 */
uint16_t ToF_GetRangeMilliMeter() {
    //Serial.print("Reading a measurement... ");
    tof_sensor.rangingTest(&measurement, false); // pass in 'true' to get debug data printout!

    if (measurement.RangeStatus != 4) {  // phase failures have incorrect data
        //Serial.print("Distance (mm): "); 
        //Serial.println(measure.RangeMilliMeter);
        return measurement.RangeMilliMeter;
    } else {
        return -1;
        //Serial.println(" out of range ");
    }
}
