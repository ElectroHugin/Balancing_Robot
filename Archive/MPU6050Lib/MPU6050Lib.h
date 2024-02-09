#ifndef MPU6050LIB_H
#define MPU6050LIB_H

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
//#include <MPU6050.h>
#include <Wire.h>

/**
 * @class MPU6050
 * @brief Represents an MPU6050 sensor module.
 * 
 * This class provides methods to initialize the sensor, retrieve sensor data, and access individual sensor readings.
 */
class MPU6050 {
public:
    /**
     * @brief Default constructor.
     */
    MPU6050();

    /**
     * @brief Initializes the MPU6050 sensor with the specified settings.
     * 
     * @param accelRange The accelerometer range to be set.
     * @param gyroRange The gyroscope range to be set.
     * @param filterBandwidth The filter bandwidth to be set.
     * @return True if initialization is successful, false otherwise.
     */
    bool init(mpu6050_accel_range_t accelRange, mpu6050_gyro_range_t gyroRange, mpu6050_bandwidth_t filterBandwidth);

    /**
     * @brief Retrieves the sensor data including accelerometer readings, gyroscope readings, and temperature.
     * 
     * @param accelX Reference to store the accelerometer reading along the X-axis.
     * @param accelY Reference to store the accelerometer reading along the Y-axis.
     * @param accelZ Reference to store the accelerometer reading along the Z-axis.
     * @param gyroX Reference to store the gyroscope reading along the X-axis.
     * @param gyroY Reference to store the gyroscope reading along the Y-axis.
     * @param gyroZ Reference to store the gyroscope reading along the Z-axis.
     * @param temp Reference to store the temperature reading.
     * @return True if data retrieval is successful, false otherwise.
     */

    bool getData(float& accelX, float& accelY, float& accelZ, float& gyroX, float& gyroY, float& gyroZ, float& temp);

    /**
     * @brief Retrieves the accelerometer reading along the X-axis.
     * 
     * @return The accelerometer reading along the X-axis.
     */
    float getAccelX();

    /**
     * @brief Retrieves the accelerometer reading along the Y-axis.
     * 
     * @return The accelerometer reading along the Y-axis.
     */
    float getAccelY();

    /**
     * @brief Retrieves the accelerometer reading along the Z-axis.
     * 
     * @return The accelerometer reading along the Z-axis.
     */
    float getAccelZ();

    /**
     * @brief Retrieves the gyroscope reading along the X-axis.
     * 
     * @return The gyroscope reading along the X-axis.
     */
    float getGyroX();

    /**
     * @brief Retrieves the gyroscope reading along the Y-axis.
     * 
     * @return The gyroscope reading along the Y-axis.
     */
    float getGyroY();

    /**
     * @brief Retrieves the gyroscope reading along the Z-axis.
     * 
     * @return The gyroscope reading along the Z-axis.
     */
    float getGyroZ();

    /**
     * @brief Retrieves the temperature reading.
     * 
     * @return The temperature reading.
     */
    float getTemp();

private:
    Adafruit_MPU6050 mpu;
};

#endif //MPU6050LIB_H