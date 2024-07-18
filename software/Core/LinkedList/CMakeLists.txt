# CMake Version Check
cmake_minimum_required(VERSION 3.14)

# Project
project(linkedlist 
        LANGUAGES C CXX
        VERSION "1.0.0"
        DESCRIPTION "linkedlist")

##############################################################################
# Extract Module Path in build/CMake/Test/                                   #
##############################################################################
extract_module_path(linkedlist MOCK_FILE_PATH)

##############################################################################
# Include Common Compilation Settings                                       #
##############################################################################
include(tools/CMake/linkedlist_compile.cmake)

##############################################################################
# Build Configuration                                                        #
##############################################################################

# Compilation Mode: Only build the library

if(MODE STREQUAL "COMPILING")
  add_library(linkedlist ${linkedlist_sources_list})
  target_compile_options(linkedlist PRIVATE ${linkedlist_compile_options})
  target_include_directories(linkedlist PRIVATE ${linkedlist_includes})
  target_compile_definitions(linkedlist PRIVATE ${linkedlist_defines})
elseif (MODE STREQUAL "TESTING")
  include(tools/CMake/linkedlist_test.cmake)
  add_library(linkedlist ${linkedlist_ut_sources_list})
  target_compile_options(linkedlist PRIVATE ${linkedlist_tests_compile_options})
  target_include_directories(linkedlist PRIVATE ${linkedlist_tests_includes})
  target_compile_definitions(linkedlist PRIVATE ${linkedlist_tests_defines})
endif()

if(MODE STREQUAL "TESTING")  
  # Execute CMock script
  execute_process(
    COMMAND ruby ${CMOCK_SCRIPT} -o${CMOCK_CONFIG_FILE} ${linkedlist_mock_header_files}
    OUTPUT_VARIABLE CMOCK_OUTPUT
    WORKING_DIRECTORY ${MOCK_FILE_PATH}
  )
  message("CMock output: ${CMOCK_OUTPUT}")

  # Testing Mode: Build the library and test executable
  add_executable(linkedlist_test ${linkedlist_tests_sources_list} ${unity_common_sources})
  target_compile_definitions(linkedlist_test PRIVATE ${linkedlist_tests_defines})
  target_compile_options(linkedlist_test PRIVATE ${linkedlist_tests_compile_options})
  target_include_directories(linkedlist_test PRIVATE ${linkedlist_tests_includes} ${unity_common_includes})
  target_link_libraries(linkedlist_test PRIVATE ${linkedlist_tests_libs})
endif()