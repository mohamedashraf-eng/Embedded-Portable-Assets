# CMake Version Check
cmake_minimum_required(VERSION 3.14)

# Project
project(wxsdk_math 
        LANGUAGES C CXX
        VERSION "1.0.0"
        DESCRIPTION "math")

##############################################################################        
# Include Common Compilation Settings                                       #
##############################################################################

include(tools/CMake/math_compile.cmake)

##############################################################################
# Extract Module Path in build/CMake/Test/                                   #
##############################################################################

##############################################################################
# Build Configuration                                                        #
##############################################################################

# Compilation Mode: Only build the library
if(MODE STREQUAL "COMPILING")
  add_library(wxsdk_math ${math_sources_list})
  target_compile_options(wxsdk_math PRIVATE ${math_compile_options})
  target_include_directories(wxsdk_math PRIVATE ${math_includes})
  target_compile_definitions(wxsdk_math PRIVATE ${math_defines})
elseif (MODE STREQUAL "TESTING")
  include(tools/cmake/math_tests.cmake)
  add_library(math ${math_ut_sources_list})
  target_compile_options(math PRIVATE ${math_tests_compile_options})
  target_include_directories(math PRIVATE ${math_tests_includes})
  target_compile_definitions(math PRIVATE ${math_tests_defines})
endif()