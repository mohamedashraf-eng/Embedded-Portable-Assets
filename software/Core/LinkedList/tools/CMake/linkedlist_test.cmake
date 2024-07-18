set(
    linkedlist_tests_sources_list

    ${linkedlist_sw}/tests/unit/test_linkedlist.c

    # Any mocked file will be under ${MOCK_FILE_PATH}/mocks/mock_headerFileName.c

    # Include Test Runners 
    ${linkedlist_sw}/tests/unit/test_runners/test_runner.c
    ${linkedlist_sw}/tests/unit/test_runners/test_main.c
)

set(
    linkedlist_ut_sources_list
    
    ${linkedlist_sw}/core/Wx_Static_LinkedList.c
)

set (
    linkedlist_mock_header_files
    
)

set(
    linkedlist_tests_includes

    ${linkedlist_sw}/core
    ${platform}
    ${linkedlist_sw}/tests/unit/stubs
    ${MOCK_FILE_PATH}/mocks/
)

set(
    linkedlist_tests_compile_options

)

set(
    linkedlist_tests_defines

)

set(
    linkedlist_tests_libs

    "linkedlist"
)
