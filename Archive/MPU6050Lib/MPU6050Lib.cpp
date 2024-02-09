#include "MPU6050Lib.h"

MPU6050::MPU6050() {
    //
}

/**
 * Initializes the MPU6050 sensor with the specified settings.
 * @param accelRange The accelerometer range to set.
 * @param gyroRange The gyroscope range to set.
 * @param filterBandwidth The filter bandwidth to set.
 * @return True if initialization is successful, false otherwise.
 */
bool MPU6050::init(mpu6050_accel_range_t accelRange, mpu6050_gyro_range_t gyroRange, mpu6050_bandwidth_t filterBandwidth) {
    if (!mpu.begin()) {
        //Serial.println("Failed to find MPU6050 chip");
        return false;
    while (1) {
        delay(10);
    }
    }
    mpu.setAccelerometerRange(accelRange);
    mpu.setGyroRange(gyroRange);
    mpu.setFilterBandwidth(filterBandwidth);
    //Serial.println("MPU6050 Found!");
    return true;
}

/**
 * Retrieves the accelerometer and gyroscope data from the MPU6050 sensor.
 * @param accelX Reference to store the X-axis accelerometer value.
 * @param accelY Reference to store the Y-axis accelerometer value.
 * @param accelZ Reference to store the Z-axis accelerometer value.
 * @param gyroX Reference to store the X-axis gyroscope value.
 * @param gyroY Reference to store the Y-axis gyroscope value.
 * @param gyroZ Reference to store the Z-axis gyroscope value.
 * @param ttemp Reference to store the temperature value.
 * @return True if data retrieval is successful, false otherwise.
 */
bool MPU6050::getData(float& accelX, float& accelY, float& accelZ, float& gyroX, float& gyroY, float& gyroZ, float& ttemp) {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    accelX = a.acceleration.x;
    accelY = a.acceleration.y;
    accelZ = a.acceleration.z;
    gyroX = g.gyro.x;
    gyroY = g.gyro.y;
    gyroZ = g.gyro.z;
    ttemp = temp.temperature;

    return true;
}

/**
 * Retrieves the X-axis accelerometer value from the MPU6050 sensor.
 * @return The X-axis accelerometer value.
 */
float MPU6050::getAccelX() {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    return a.acceleration.x;
}

/**
 * Retrieves the Y-axis accelerometer value from the MPU6050 sensor.
 * @return The Y-axis accelerometer value.
 */
float MPU6050::getAccelY() {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    return a.acceleration.y;
}

/**
 * Retrieves the Z-axis accelerometer value from the MPU6050 sensor.
 * @return The Z-axis accelerometer value.
 */
float MPU6050::getAccelZ() {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    return a.acceleration.z;
}

/**
 * Retrieves the X-axis gyroscope value from the MPU6050 sensor.
 * @return The X-axis gyroscope value.
 */
float MPU6050::getGyroX() {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    return g.gyro.x;
}  

/**
 * Retrieves the Y-axis gyroscope value from the MPU6050 sensor.
 * @return The Y-axis gyroscope value.
 */
float MPU6050::getGyroY() {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    return g.gyro.y;
}

/**
 * Retrieves the Z-axis gyroscope value from the MPU6050 sensor.
 * @return The Z-axis gyroscope value.
 */
float MPU6050::getGyroZ() {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    return g.gyro.z;
}

/**
 * Retrieves the temperature value from the MPU6050 sensor.
 * @return The temperature value.
 */
float MPU6050::getTemp() {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    return temp.temperature;
}
