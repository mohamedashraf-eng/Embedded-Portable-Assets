# CMake Version Check
cmake_minimum_required(VERSION 3.14)

# Project
project(wxsdk_queue 
        LANGUAGES C CXX
        VERSION "1.0.0"
        DESCRIPTION "queue")

##############################################################################        
# Include Common Compilation Settings                                       #
##############################################################################

include(tools/CMake/queue_compile.cmake)

##############################################################################
# Extract Module Path in build/CMake/Test/                                   #
##############################################################################

##############################################################################
# Build Configuration                                                        #
##############################################################################

# Compilation Mode: Only build the library
if(MODE STREQUAL "COMPILING")
  add_library(wxsdk_queue ${queue_sources_list})
  target_compile_options(wxsdk_queue PRIVATE ${queue_compile_options})
  target_include_directories(wxsdk_queue PRIVATE ${queue_includes})
  target_compile_definitions(wxsdk_queue PRIVATE ${queue_defines})
elseif (MODE STREQUAL "TESTING")
  include(tools/cmake/queue_tests.cmake)
  add_library(queue ${queue_ut_sources_list})
  target_compile_options(queue PRIVATE ${queue_tests_compile_options})
  target_include_directories(queue PRIVATE ${queue_tests_includes})
  target_compile_definitions(queue PRIVATE ${queue_tests_defines})
endif()