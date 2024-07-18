#include "unity.h"
#include "unity_fixture.h"

/* Running all test cases within the group */
TEST_GROUP_RUNNER(LinkedList)
{
    RUN_TEST_CASE(LinkedList, test_linkedlist_XYZ);
}