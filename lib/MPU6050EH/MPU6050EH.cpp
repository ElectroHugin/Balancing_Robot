#include "MPU6050EH.h"

MPU6050EH::MPU6050EH() {
    //
}
MPU6050EH::~MPU6050EH() {
    mpu.resetFIFO();
}

bool MPU6050EH::init() {
    bool initSuccess = false;
    mpu.initialize();
    if (mpu.testConnection()) {
        initSuccess = true;
    } else {
        initSuccess = false;
    }

    devStatus = mpu.dmpInitialize();

    mpu.setXGyroOffset(-2168);
    mpu.setYGyroOffset(-142);
    mpu.setZGyroOffset(754);
    mpu.setXAccelOffset(161);
    mpu.setYAccelOffset(-82);
    mpu.setZAccelOffset(20);

    // Make sure it worked (returns 0 if so)
    if (devStatus == 0) {
        mpu.setDMPEnabled(true);
        mpuIntStatus = mpu.getIntStatus();

        dmpReady = true;
        packetSize = mpu.dmpGetFIFOPacketSize();
        initSuccess = true;
    } else {
		// In case of an error with the DMP
        initSuccess = false;
    }
    return initSuccess;
}



float MPU6050EH::yaw(){
	return (ypr[0] * 180/M_PI);
}

float MPU6050EH::pitch(){
	return (ypr[1] * 180/M_PI);
}

float MPU6050EH::roll(){
	return (ypr[2] * 180/M_PI);
}

float MPU6050EH::angRate(){
	return -((float)gyro[1]/131.0);
}

int16_t MPU6050EH::getAccelX(){
    return mpu.getAccelerationX();
}

int16_t MPU6050EH::getAccelY(){
    return mpu.getAccelerationY();
}

int16_t MPU6050EH::getAccelZ(){
    return mpu.getAccelerationZ();
}

int16_t MPU6050EH::getTemp(){
    return mpu.getTemperature();
}

bool MPU6050EH::accelgyroData(){
    bool dataSuccess = true;
    // Reset interrupt flag and get INT_STATUS byte
    mpuIntStatus = mpu.getIntStatus();

    // Get current FIFO count
    fifoCount = mpu.getFIFOCount();

    // Check for overflow (this should never happen unless our code is too inefficient)
    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        // Reset so we can continue cleanly
        mpu.resetFIFO();
        //Serial.println("Warning - FIFO Overflowing!");
        dataSuccess = false;

    // otherwise, check for DMP data ready interrupt (this should happen exactly once per loop: 100Hz)
    // mpuIntStatus & 0x02
    } else if (true) {
        // Wait for correct available data length, should be less than 1-2ms, if any!
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();


        // read a packet from FIFO
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        
        // track FIFO count here in case there is > 1 packet available
        // (this lets us immediately read more without waiting for an interrupt)
        fifoCount -= packetSize;

        // Get sensor data
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGyro(gyro, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
        mpu.resetFIFO();

        //Serial.print(ypr[1]);
        //Serial.print(" - ");
        //Serial.println(ypr[0]);
    }
    return dataSuccess;
}

