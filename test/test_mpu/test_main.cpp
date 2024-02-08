#include "Unity.h"
#include "MPU6050Lib.h"

void test_MPU6050Lib()
{
    // Create an instance of the MPU6050Lib
    MPU6050 mpu;

    // Initialize the MPU6050Lib
    TEST_ASSERT_TRUE(mpu.init(MPU6050_RANGE_8_G, MPU6050_RANGE_250_DEG, MPU6050_BAND_5_HZ));

    // Perform some tests
    float accelX, accelY, accelZ, gyroX, gyroY, gyroZ, temp;
    TEST_ASSERT_TRUE(mpu.getData(accelX, accelY, accelZ, gyroX, gyroY, gyroZ, temp));

    // Test the accelerometer
    TEST_ASSERT_FLOAT_WITHIN(10.0, 0.0, accelX);
    TEST_ASSERT_FLOAT_WITHIN(10.0, 0.0, accelY);
    TEST_ASSERT_FLOAT_WITHIN(10.0, 0.0, accelZ);

    // Test the gyroscope
    TEST_ASSERT_FLOAT_WITHIN(10.0, 0.0, gyroX);
    TEST_ASSERT_FLOAT_WITHIN(10.0, 0.0, gyroY);
    TEST_ASSERT_FLOAT_WITHIN(10.0, 0.0, gyroZ);

    // Test the temperature
    TEST_ASSERT_FLOAT_WITHIN(30.0, 30.0, temp);
}

int main()
{
    UNITY_BEGIN();

    // Run the MPU6050Lib test
    RUN_TEST(test_MPU6050Lib);

    UNITY_END();
}