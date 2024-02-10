/**
 * @file ToFLib.cpp
 * @brief Implementation file for the ToFLib library.
 * 
 * @author ElectroHugin
 * @date 12/02/2024
 */

#include "ToFLib.h"

/**
 * @brief Default constructor for the VL53L0XEH class.
 */
VL53L0XEH::VL53L0XEH() {
    //
}

/**
 * @brief Destructor for the VL53L0XEH class.
 */
VL53L0XEH::~VL53L0XEH() {
    //
}

/**
 * @brief Initializes the VL53L0X sensor.
 * @return True if initialization is successful, false otherwise.
 */
bool VL53L0XEH::init() {
    bool initSuccess = false;

    if (!tof_sensor.begin()) {
        initSuccess = false;
    } else {
        initSuccess = true;
    }

    return initSuccess;
}

/**
 * @brief Performs a measurement using the VL53L0X sensor.
 * @return True if measurement is successful, false otherwise.
 */
bool VL53L0XEH::measure() {
    bool measureSuccess = false;
    tof_sensor.rangingTest(&measurement, false);
    if (measurement.RangeStatus != 4) {
        measureSuccess = true;
    } else {
        measureSuccess = false;
    }
    return measureSuccess;
}

/**
 * @brief Gets the range measured by the VL53L0X sensor in millimeters.
 * @return The range in millimeters.
 */
uint16_t VL53L0XEH::getRangeMilliMeter() {
    return measurement.RangeMilliMeter;
}

/**
 * @brief Gets the range measured by the VL53L0X sensor in centimeters.
 * @return The range in centimeters.
 */
float VL53L0XEH::getRangeCentiMeter() {
    u_int16_t range = measurement.RangeMilliMeter;
    return (float)range / 10.0;
}

/**
 * @brief Gets the range measured by the VL53L0X sensor in meters.
 * @return The range in meters.
 */
float VL53L0XEH::getRangeMeter() {
    u_int16_t range = measurement.RangeMilliMeter;
    return (float)range / 1000.0;
}


