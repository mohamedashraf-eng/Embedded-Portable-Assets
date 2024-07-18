set(
    node_tests_sources_list

    ${node_sw}/tests/unit/test_node.c

    # Any mocked file will be under ${MOCK_FILE_PATH}/mocks/mock_headerFileName.c

    # Include Test Runners 
    ${node_sw}/tests/unit/test_runners/test_runner.c
    ${node_sw}/tests/unit/test_runners/test_main.c
)

set(
    node_ut_sources_list
    
    ${node_sw}/core/Wx_Static_Node.c
)

set (
    node_mock_header_files
    
)

set(
    node_tests_includes

    ${node_sw}/core
    ${platform}
    ${node_sw}/tests/unit/stubs
    ${MOCK_FILE_PATH}/mocks/
)

set(
    node_tests_compile_options

)

set(
    node_tests_defines

)

set(
    node_tests_libs

    "node"
)
