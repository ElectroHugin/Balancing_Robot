#include "Unity.h"
#include "MPU6050EH.h"
#include <Arduino.h>
#include <Wire.h>

void setUp(void)
{
    
}

void tearDown(void)
{
    // clean stuff up here
}

void test_MPU6050EH()
{
    // Create an instance of the MPU6050Lib
    MPU6050EH mpuEH;

    // Initialize the MPU6050Lib
    TEST_ASSERT_TRUE(mpuEH.init());

    // Perform some tests
    TEST_ASSERT_TRUE(mpuEH.accelgyroData());

    // Test the accelerometer
    TEST_ASSERT_INT16_WITHIN(10, 0, mpuEH.getAccelX());
    TEST_ASSERT_INT16_WITHIN(10, 0, mpuEH.getAccelY());
    TEST_ASSERT_INT16_WITHIN(10, 0, mpuEH.getAccelZ());

    // Test the gyroscope
    TEST_ASSERT_INT16_WITHIN(5, 0, mpuEH.yaw());
    TEST_ASSERT_INT16_WITHIN(5, 0, mpuEH.pitch());
    TEST_ASSERT_INT16_WITHIN(5, 0, mpuEH.roll());
}

void setup()
{
    delay(2000);
    
    Wire.begin();
    Wire.setClock(400000);
    
    UNITY_BEGIN();
    test_MPU6050EH();
    UNITY_END();
}

void loop() {
    // loop stuff here
}