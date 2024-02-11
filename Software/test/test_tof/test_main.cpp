#include <unity.h>
#include "ToFLib.h"
#include <Arduino.h>
#include <Wire.h>

void setUp(void)
{
    Wire.begin();
    Wire.setClock(400000);
}

void tearDown(void)
{
    // clean stuff up here
}

void test_VL53L0XEH()
{
    // Create an instance of the ToFLib class
    VL53L0XEH ToF;

    // Perform distance measurement
    TEST_ASSERT_TRUE(ToF.init());
    TEST_ASSERT_TRUE(ToF.measure());

    // Assert that the measured distance is within a valid range
    TEST_ASSERT_INT16_WITHIN(500, 0, ToF.getRangeMilliMeter());
}

void setup()
{
    delay(2000);

    Wire.begin();
    Wire.setClock(400000);
    
    UNITY_BEGIN();
    RUN_TEST(test_VL53L0XEH);
    UNITY_END();
}

void loop() {
    // loop stuff here
}