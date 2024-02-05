#include <unity.h>
#include "IMULib.h"

void test_IMULib_function() {
    // Act
    IMU_Setup();
    float yaw = getYaw();
    float pitch = getPitch();
    float roll = getRoll();

    // Assert
    TEST_ASSERT_FLOAT_WITHIN(0.1f, 360.0f, yaw);
    TEST_ASSERT_FLOAT_WITHIN(0.1f, 360.0f, pitch);
    TEST_ASSERT_FLOAT_WITHIN(0.1f, 360.0f, roll);
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_IMULib_function);
    UNITY_END();
}

void loop() {
    // Empty loop
}
