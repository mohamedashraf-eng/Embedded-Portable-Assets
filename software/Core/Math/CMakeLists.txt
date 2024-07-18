# CMake Version Check
cmake_minimum_required(VERSION 3.14)

# Project
project(math 
        LANGUAGES C CXX
        VERSION "1.0.0"
        DESCRIPTION "math")

##############################################################################
# Extract Module Path in build/CMake/Test/                                   #
##############################################################################
extract_module_path(math MOCK_FILE_PATH)

##############################################################################
# Include Common Compilation Settings                                       #
##############################################################################
include(tools/CMake/math_compile.cmake)

##############################################################################
# Build Configuration                                                        #
##############################################################################

# Compilation Mode: Only build the library

if(MODE STREQUAL "COMPILING")
  add_library(math ${math_sources_list})
  target_compile_options(math PRIVATE ${math_compile_options})
  target_include_directories(math PRIVATE ${math_includes})
  target_compile_definitions(math PRIVATE ${math_defines})
elseif (MODE STREQUAL "TESTING")
  include(tools/CMake/math_test.cmake)
  add_library(math ${math_ut_sources_list})
  target_compile_options(math PRIVATE ${math_tests_compile_options})
  target_include_directories(math PRIVATE ${math_tests_includes})
  target_compile_definitions(math PRIVATE ${math_tests_defines})
endif()

if(MODE STREQUAL "TESTING")  
  # Execute CMock script
  execute_process(
    COMMAND ruby ${CMOCK_SCRIPT} -o${CMOCK_CONFIG_FILE} ${math_mock_header_files}
    OUTPUT_VARIABLE CMOCK_OUTPUT
    WORKING_DIRECTORY ${MOCK_FILE_PATH}
  )
  message("CMock output: ${CMOCK_OUTPUT}")

  # Testing Mode: Build the library and test executable
  add_executable(math_test ${math_tests_sources_list} ${unity_common_sources})
  target_compile_definitions(math_test PRIVATE ${math_tests_defines})
  target_compile_options(math_test PRIVATE ${math_tests_compile_options})
  target_include_directories(math_test PRIVATE ${math_tests_includes} ${unity_common_includes})
  target_link_libraries(math_test PRIVATE ${math_tests_libs})
endif()