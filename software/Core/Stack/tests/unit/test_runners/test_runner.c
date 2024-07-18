#include "unity.h"
#include "unity_fixture.h"

/* Running all test cases within the group */
TEST_GROUP_RUNNER(Stack)
{
    RUN_TEST_CASE(Stack, test_stack_XYZ);
}