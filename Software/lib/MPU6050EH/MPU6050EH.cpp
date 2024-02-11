/**
 * @file MPU6050EH.cpp
 * @brief Implementation file for the MPU6050EH class.
 * 
 * This file contains the implementation of the MPU6050EH class, which is a library for interfacing with the MPU6050 sensor.
 * 
 * @author ElectroHugin
 * @date 12/02/2024
 */

#include "MPU6050EH.h"

/**
 * @brief Default constructor for the MPU6050EH class.
 */
MPU6050EH::MPU6050EH() {
    //
}

/**
 * @brief Destructor for the MPU6050EH class.
 */
MPU6050EH::~MPU6050EH() {
    mpu.resetFIFO();
}

/**
 * @brief Initializes the MPU6050 sensor.
 * @return True if initialization is successful, false otherwise.
 */
bool MPU6050EH::init() {
    bool initSuccess = false;
    
    mpu.initialize();
    mpu.testConnection() ? initSuccess = true : initSuccess = false;

    devStatus = mpu.dmpInitialize();

    mpu.setXAccelOffset(-2168);
    mpu.setYAccelOffset(-142);
    mpu.setZAccelOffset(754);

    mpu.setXGyroOffset(161);
    mpu.setYGyroOffset(-82);
    mpu.setZGyroOffset(20);
    
    if (devStatus == 0) {
        initSuccess = true;
        // Calibration Time: generate offsets and calibrate our MPU6050
        mpu.CalibrateAccel(6);
        mpu.CalibrateGyro(6);
        //mpu.PrintActiveOffsets();
        // turn on the DMP, now that it's ready
        mpu.setDMPEnabled(true);

        // enable interrupt detection
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else {
        initSuccess = false;
    }

    // configure LED for output
    pinMode(LED_PIN, OUTPUT);

    return initSuccess;
}

/**
 * @brief Interrupt service routine for the MPU6050 data ready interrupt.
 */
volatile bool mpuInterrupt = false;
void dmpDataReady() {
    mpuInterrupt = true;
}

/**
 * @brief Calculates and returns the yaw angle in degrees.
 * @return The yaw angle in degrees.
 */
float MPU6050EH::yaw(){
	return (ypr[0] * 180/M_PI);
}

/**
 * @brief Calculates and returns the pitch angle in degrees.
 * @return The pitch angle in degrees.
 */
float MPU6050EH::pitch(){
	return (ypr[1] * 180/M_PI);
}

/**
 * @brief Calculates and returns the roll angle in degrees.
 * @return The roll angle in degrees.
 */
float MPU6050EH::roll(){
	return (ypr[2] * 180/M_PI);
}

/**
 * @brief Returns the X-axis acceleration value.
 * @return The X-axis acceleration value.
 */
int16_t MPU6050EH::getAccelX(){
    return aaWorld.x;
}

/**
 * @brief Returns the Y-axis acceleration value.
 * @return The Y-axis acceleration value.
 */
int16_t MPU6050EH::getAccelY(){
    return aaWorld.y;
}

/**
 * @brief Returns the Z-axis acceleration value.
 * @return The Z-axis acceleration value.
 */
int16_t MPU6050EH::getAccelZ(){
    return aaWorld.z;
}

/**
 * @brief Returns the temperature value.
 * @return The temperature value.
 */
int16_t MPU6050EH::getTemp(){
    return mpu.getTemperature();
}

/**
 * @brief Reads the accelerometer and gyroscope data from the MPU6050 sensor.
 * @return True if data reading is successful, false otherwise.
 */
bool MPU6050EH::accelgyroData(){
    bool dataSuccess = false;

    // if programming failed, don't try to do anything
    if (!dmpReady) return dataSuccess;
    // read a packet from FIFO
    if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) { // Get the Latest packet 

        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
        mpu.dmpGetAccel(&aa, fifoBuffer);
        mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
        mpu.dmpGetLinearAccelInWorld(&aaWorld, &aaReal, &q);

        dataSuccess = true;
    }

    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);

    return dataSuccess;
}

