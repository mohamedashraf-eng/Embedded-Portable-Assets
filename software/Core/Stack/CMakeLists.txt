# CMake Version Check
cmake_minimum_required(VERSION 3.14)

# Project
project(stack 
        LANGUAGES C CXX
        VERSION "1.0.0"
        DESCRIPTION "stack")

##############################################################################
# Extract Module Path in build/CMake/Test/                                   #
##############################################################################
extract_module_path(stack MOCK_FILE_PATH)

##############################################################################
# Include Common Compilation Settings                                       #
##############################################################################
include(tools/CMake/stack_compile.cmake)

##############################################################################
# Build Configuration                                                        #
##############################################################################

# Compilation Mode: Only build the library

if(MODE STREQUAL "COMPILING")
  add_library(stack ${stack_sources_list})
  target_compile_options(stack PRIVATE ${stack_compile_options})
  target_include_directories(stack PRIVATE ${stack_includes})
  target_compile_definitions(stack PRIVATE ${stack_defines})
elseif (MODE STREQUAL "TESTING")
  include(tools/CMake/stack_test.cmake)
  add_library(stack ${stack_ut_sources_list})
  target_compile_options(stack PRIVATE ${stack_tests_compile_options})
  target_include_directories(stack PRIVATE ${stack_tests_includes})
  target_compile_definitions(stack PRIVATE ${stack_tests_defines})
endif()

if(MODE STREQUAL "TESTING")  
  # Execute CMock script
  execute_process(
    COMMAND ruby ${CMOCK_SCRIPT} -o${CMOCK_CONFIG_FILE} ${stack_mock_header_files}
    OUTPUT_VARIABLE CMOCK_OUTPUT
    WORKING_DIRECTORY ${MOCK_FILE_PATH}
  )
  message("CMock output: ${CMOCK_OUTPUT}")

  # Testing Mode: Build the library and test executable
  add_executable(stack_test ${stack_tests_sources_list} ${unity_common_sources})
  target_compile_definitions(stack_test PRIVATE ${stack_tests_defines})
  target_compile_options(stack_test PRIVATE ${stack_tests_compile_options})
  target_include_directories(stack_test PRIVATE ${stack_tests_includes} ${unity_common_includes})
  target_link_libraries(stack_test PRIVATE ${stack_tests_libs})
endif()