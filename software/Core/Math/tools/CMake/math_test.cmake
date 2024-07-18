set(
    math_tests_sources_list

    ${math_sw}/tests/unit/test_math.c

    # Any mocked file will be under ${MOCK_FILE_PATH}/mocks/mock_headerFileName.c

    # Include Test Runners 
    ${math_sw}/tests/unit/test_runners/test_runner.c
    ${math_sw}/tests/unit/test_runners/test_main.c
)

set(
    math_ut_sources_list
    
    ${math_sw}/core/Wx_Math.c
)

set (
    math_mock_header_files
    
)

set(
    math_tests_includes

    ${math_sw}/core
    ${platform}
    ${math_sw}/tests/unit/stubs
    ${MOCK_FILE_PATH}/mocks/
)

set(
    math_tests_compile_options

)

set(
    math_tests_defines

)

set(
    math_tests_libs

    "math"
)
