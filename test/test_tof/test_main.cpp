#include <unity.h>
#include "ToFLib.h"

void test_distance_measurement()
{
    // Create an instance of the ToFLib class

    // Perform distance measurement
    uint16_t distance = ToF_GetRangeMilliMeter();

    // Assert that the measured distance is within a valid range
    TEST_ASSERT_TRUE(distance >= 0);
    TEST_ASSERT_TRUE(distance <= 2000);
}

void setup()
{
    UNITY_BEGIN();
    RUN_TEST(test_distance_measurement);
    UNITY_END();
}

int main(int argc, char** argv)
{
    setup();
    return 0;
}
