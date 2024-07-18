#include "unity.h"
#include "unity_fixture.h"

/* Running all test cases within the group */
TEST_GROUP_RUNNER(Queue)
{
    RUN_TEST_CASE(Queue, test_queue_XYZ);
}