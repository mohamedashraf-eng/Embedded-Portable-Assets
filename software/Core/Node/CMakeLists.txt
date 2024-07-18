# CMake Version Check
cmake_minimum_required(VERSION 3.14)

# Project
project(node 
        LANGUAGES C CXX
        VERSION "1.0.0"
        DESCRIPTION "node")

##############################################################################
# Extract Module Path in build/CMake/Test/                                   #
##############################################################################
extract_module_path(node MOCK_FILE_PATH)

##############################################################################
# Include Common Compilation Settings                                       #
##############################################################################
include(tools/CMake/node_compile.cmake)

##############################################################################
# Build Configuration                                                        #
##############################################################################

# Compilation Mode: Only build the library

if(MODE STREQUAL "COMPILING")
  add_library(node ${node_sources_list})
  target_compile_options(node PRIVATE ${node_compile_options})
  target_include_directories(node PRIVATE ${node_includes})
  target_compile_definitions(node PRIVATE ${node_defines})
elseif (MODE STREQUAL "TESTING")
  include(tools/CMake/node_test.cmake)
  add_library(node ${node_ut_sources_list})
  target_compile_options(node PRIVATE ${node_tests_compile_options})
  target_include_directories(node PRIVATE ${node_tests_includes})
  target_compile_definitions(node PRIVATE ${node_tests_defines})
endif()

if(MODE STREQUAL "TESTING")  
  # Execute CMock script
  execute_process(
    COMMAND ruby ${CMOCK_SCRIPT} -o${CMOCK_CONFIG_FILE} ${node_mock_header_files}
    OUTPUT_VARIABLE CMOCK_OUTPUT
    WORKING_DIRECTORY ${MOCK_FILE_PATH}
  )
  message("CMock output: ${CMOCK_OUTPUT}")

  # Testing Mode: Build the library and test executable
  add_executable(node_test ${node_tests_sources_list} ${unity_common_sources})
  target_compile_definitions(node_test PRIVATE ${node_tests_defines})
  target_compile_options(node_test PRIVATE ${node_tests_compile_options})
  target_include_directories(node_test PRIVATE ${node_tests_includes} ${unity_common_includes})
  target_link_libraries(node_test PRIVATE ${node_tests_libs})
endif()