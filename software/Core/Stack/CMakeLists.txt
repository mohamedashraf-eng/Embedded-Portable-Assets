# CMake Version Check
cmake_minimum_required(VERSION 3.14)

# Project
project(wxsdk_stack 
        LANGUAGES C CXX
        VERSION "1.0.0"
        DESCRIPTION "stack")

##############################################################################        
# Include Common Compilation Settings                                       #
##############################################################################

include(tools/CMake/stack_compile.cmake)

##############################################################################
# Extract Module Path in build/CMake/Test/                                   #
##############################################################################

##############################################################################
# Build Configuration                                                        #
##############################################################################

# Compilation Mode: Only build the library
if(MODE STREQUAL "COMPILING")
  add_library(wxsdk_stack ${stack_sources_list})
  target_compile_options(wxsdk_stack PRIVATE ${stack_compile_options})
  target_include_directories(wxsdk_stack PRIVATE ${stack_includes})
  target_compile_definitions(wxsdk_stack PRIVATE ${stack_defines})
elseif (MODE STREQUAL "TESTING")
  include(tools/cmake/stack_tests.cmake)
  add_library(stack ${stack_ut_sources_list})
  target_compile_options(stack PRIVATE ${stack_tests_compile_options})
  target_include_directories(stack PRIVATE ${stack_tests_includes})
  target_compile_definitions(stack PRIVATE ${stack_tests_defines})
endif()