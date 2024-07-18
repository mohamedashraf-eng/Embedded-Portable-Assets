set(
    stack_tests_sources_list

    ${stack_sw}/tests/unit/test_stack.c

    # Any mocked file will be under ${MOCK_FILE_PATH}/mocks/mock_headerFileName.c

    # Include Test Runners 
    ${stack_sw}/tests/unit/test_runners/test_runner.c
    ${stack_sw}/tests/unit/test_runners/test_main.c
)

set(
    stack_ut_sources_list
    
    ${stack_sw}/core/Wx_Static_Stack.c
)

set (
    stack_mock_header_files
    
)

set(
    stack_tests_includes

    ${stack_sw}/core
    ${platform}
    ${stack_sw}/tests/unit/stubs
    ${MOCK_FILE_PATH}/mocks/
)

set(
    stack_tests_compile_options

)

set(
    stack_tests_defines

)

set(
    stack_tests_libs

    "stack"
)
