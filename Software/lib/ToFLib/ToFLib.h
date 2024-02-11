/**
 * @file   ToFLib.h
 * @brief   This file contains the declaration of the VL53L0XEH class, which is a library for interfacing with the VL53L0X time-of-flight sensor.
 *      This library makes use of the Adafruit_VL53L0X library. 
 *      The VL53L0XEH class provides methods for initializing the sensor, measuring distances, and retrieving the measured range in different units.
 *      The VL53L0XEH class is a wrapper for the Adafruit_VL53L0X class.
 *      The Adafruit_VL53L0X library is a wrapper for the STMicroelectronics VL53L0X API.
 * 
 * @author ElectroHugin
 * @date 12/02/2024
 */
/* * * * * * * * * * * * * * * * * * * * * **/
#ifndef TOFLIB_H
#define TOFLIB_H

// Include any necessary headers here
#include "Adafruit_VL53L0X.h"
#include <Adafruit_Sensor.h>
#include <Wire.h>

/**
 * @brief The VL53L0XEH class represents a wrapper for the VL53L0X time-of-flight sensor.
 * 
 * This class provides methods to initialize the sensor, measure distances, and retrieve the measured range in different units.
 * 
 */
class VL53L0XEH {
public:
    /**
     * @brief Default constructor for the VL53L0XEH class.
     */
    VL53L0XEH();

    /**
     * @brief Destructor for the VL53L0XEH class.
     */
    ~VL53L0XEH();

    /**
     * @brief Initializes the VL53L0X sensor.
     * 
     * @return True if initialization is successful, false otherwise.
     */
    bool init();

    /**
     * @brief Performs a distance measurement using the VL53L0X sensor.
     * 
     * @return True if measurement is successful, false otherwise.
     */
    bool measure();

    /**
     * @brief Retrieves the measured range in millimeters.
     * 
     * @return The measured range in millimeters.
     */
    uint16_t getRangeMilliMeter();

    /**
     * @brief Retrieves the measured range in centimeters.
     * 
     * @return The measured range in centimeters.
     */
    float getRangeCentiMeter();

    /**
     * @brief Retrieves the measured range in meters.
     * 
     * @return The measured range in meters.
     */
    float getRangeMeter();

private:
    Adafruit_VL53L0X tof_sensor;  // Instance of the Adafruit_VL53L0X class
    VL53L0X_RangingMeasurementData_t measurement;  // Measurement data structure
};

#endif // TOFLIB_H
