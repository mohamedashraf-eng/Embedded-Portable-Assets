#include "unity.h"
#include "unity_fixture.h"

/* Running all test cases within the group */
TEST_GROUP_RUNNER(Node)
{
    RUN_TEST_CASE(Node, test_node_XYZ);
}