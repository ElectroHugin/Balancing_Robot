/**
 * @file MPU6050EH.h
 * @brief This file contains the declaration of the MPU6050EH class, which is a library for interfacing with the MPU6050 sensor.
 * 
 * This library makes use of the I2Cdev and MPU6050 libraries, and the demonstration sketch written by Jeff Rowberg with modifications by ElectroHugin.
 * 
 * The MPU6050EH class provides methods for initializing the sensor, reading accelerometer and gyroscope data, and calculating yaw, pitch, and roll angles.
 * 
 * @author ElectroHugin
 * @date 12/02/2024
 */
/* * * * * * * * * * * * * * * * * * * * * *
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

#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "Wire.h"

#define INTERRUPT_PIN 2
#define LED_PIN 13 


void dmpDataReady();

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

private:
    // class default I2C address is 0x68
    // specific I2C addresses may be passed as a parameter here
    // AD0 low = 0x68 (default for SparkFun breakout and InvenSense evaluation board)
    // AD0 high = 0x69
    MPU6050 mpu;        			// Default: AD0 low = 0x68

    bool blinkState = false;

    // MPU control/status vars
    bool dmpReady = false;  // set true if DMP init was successful
    uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
    uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
    uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
    uint16_t fifoCount;     // count of all bytes currently in FIFO
    uint8_t fifoBuffer[64]; // FIFO storage buffer

    // orientation/motion vars
    Quaternion q;           // [w, x, y, z]         quaternion container
    VectorInt16 aa;         // [x, y, z]            accel sensor measurements
    VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
    VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
    VectorFloat gravity;    // [x, y, z]            gravity vector
    float euler[3];         // [psi, theta, phi]    Euler angle container
    float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

    
};


#endif //MPU6050EH_H