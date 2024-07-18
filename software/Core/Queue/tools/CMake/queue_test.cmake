set(
    queue_tests_sources_list

    ${queue_sw}/tests/unit/test_queue.c

    # Any mocked file will be under ${MOCK_FILE_PATH}/mocks/mock_headerFileName.c

    # Include Test Runners 
    ${queue_sw}/tests/unit/test_runners/test_runner.c
    ${queue_sw}/tests/unit/test_runners/test_main.c
)

set(
    queue_ut_sources_list
    
    ${queue_sw}/core/Wx_Static_queue.c
)

set (
    queue_mock_header_files
    
)

set(
    queue_tests_includes

    ${queue_sw}/core
    ${platform}
    ${queue_sw}/tests/unit/stubs
    ${MOCK_FILE_PATH}/mocks/
)

set(
    queue_tests_compile_options

)

set(
    queue_tests_defines

)

set(
    queue_tests_libs

    "queue"
)
