#include "unity_fixture.h"

/* Function to run all the test groups @this swc */
static void RunAllTests(void)
{
    RUN_TEST_GROUP(Node);
}

/* Entry point for the tests */
int main(int argc, const char * argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}