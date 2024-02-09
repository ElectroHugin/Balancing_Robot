/* * * * * * * * * * * * * * * * * * * * * *
 *  This Library makes use of the I2Cdev and MPU6050 libraries, and the demonstration
 *  sketch written by (Jeff Rowberg <jeff@rowberg.net>) and modifications by
 *  Simon Bluett <hello@chillibasket.com> (Website: wired.chillibasket.com)
 *  -- -- -- -- -- -- -- -- -- -- -- -- -- --
 *  I2Cdev device library code is placed under the MIT license
 *  Copyright (c) 2012 Jeff Rowberg
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 * * * * * * * * * * * * * * * * * * * * * */
#ifndef MPU6050EH_H
#define MPU6050EH_H

#include <I2Cdev.h>
//#include <MPU6050.h>
#include <MPU6050_6Axis_MotionApps20.h>
#include <Wire.h>

class MPU6050EH {
public:
    MPU6050EH();
    ~MPU6050EH();

    bool init();

    float yaw();

    float pitch();

    float roll();

    float angRate();

    bool accelgyroData();

    int16_t getAccelX();

    int16_t getAccelY();

    int16_t getAccelZ();

    int16_t getTemp();

    Quaternion q;                   // [w, x, y, z]       Quaternion Container
    VectorFloat gravity;           	// [x, y, z]            Gravity Vector
    int16_t gyro[3];               	// [x, y, z]            Gyro Vector
    float ypr[3];                   // [yaw, pitch, roll]   Yaw/Pitch/Roll & gravity vector
    float averagepitch[50];        	// Used for averaging pitch value

private:
    // Specific I2C addresses may be passed as a parameter here
    MPU6050 mpu;        			// Default: AD0 low = 0x68

    bool dmpReady = false;         	// Set true if DMP init was successful
    uint8_t devStatus;              // Return status after device operation (0 = success, !0 = error)
    uint8_t mpuIntStatus;           // Holds actual interrupt status byte from MPU
    uint16_t packetSize;            // Expected DMP packet size (default is 42 bytes)
    uint16_t fifoCount;             // Count of all bytes currently in FIFO
    uint8_t fifoBuffer[64];         // FIFO storage buffer
};


#endif //MPU6050EH_H