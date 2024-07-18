#include "unity.h"
#include "unity_fixture.h"

/* Running all test cases within the group */
TEST_GROUP_RUNNER(Math)
{
    RUN_TEST_CASE(Math, test_math_XYZ);
}