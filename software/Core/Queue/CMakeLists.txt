# CMake Version Check
cmake_minimum_required(VERSION 3.14)

# Project
project(queue 
        LANGUAGES C CXX
        VERSION "1.0.0"
        DESCRIPTION "queue")

##############################################################################
# Extract Module Path in build/CMake/Test/                                   #
##############################################################################
extract_module_path(queue MOCK_FILE_PATH)

##############################################################################
# Include Common Compilation Settings                                       #
##############################################################################
include(tools/CMake/queue_compile.cmake)

##############################################################################
# Build Configuration                                                        #
##############################################################################

# Compilation Mode: Only build the library

if(MODE STREQUAL "COMPILING")
  add_library(queue ${queue_sources_list})
  target_compile_options(queue PRIVATE ${queue_compile_options})
  target_include_directories(queue PRIVATE ${queue_includes})
  target_compile_definitions(queue PRIVATE ${queue_defines})
elseif (MODE STREQUAL "TESTING")
  include(tools/CMake/queue_test.cmake)
  add_library(queue ${queue_ut_sources_list})
  target_compile_options(queue PRIVATE ${queue_tests_compile_options})
  target_include_directories(queue PRIVATE ${queue_tests_includes})
  target_compile_definitions(queue PRIVATE ${queue_tests_defines})
endif()

if(MODE STREQUAL "TESTING")  
  # Execute CMock script
  execute_process(
    COMMAND ruby ${CMOCK_SCRIPT} -o${CMOCK_CONFIG_FILE} ${queue_mock_header_files}
    OUTPUT_VARIABLE CMOCK_OUTPUT
    WORKING_DIRECTORY ${MOCK_FILE_PATH}
  )
  message("CMock output: ${CMOCK_OUTPUT}")

  # Testing Mode: Build the library and test executable
  add_executable(queue_test ${queue_tests_sources_list} ${unity_common_sources})
  target_compile_definitions(queue_test PRIVATE ${queue_tests_defines})
  target_compile_options(queue_test PRIVATE ${queue_tests_compile_options})
  target_include_directories(queue_test PRIVATE ${queue_tests_includes} ${unity_common_includes})
  target_link_libraries(queue_test PRIVATE ${queue_tests_libs})
endif()