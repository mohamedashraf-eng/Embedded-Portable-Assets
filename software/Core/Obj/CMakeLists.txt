# CMake Version Check
cmake_minimum_required(VERSION 3.14)

# Project
project(wxsdk_obj 
        LANGUAGES C CXX
        VERSION "1.0.0"
        DESCRIPTION "obj")

##############################################################################        
# Include Common Compilation Settings                                       #
##############################################################################

include(tools/CMake/obj_compile.cmake)

##############################################################################
# Extract Module Path in build/CMake/Test/                                   #
##############################################################################

##############################################################################
# Build Configuration                                                        #
##############################################################################

# Compilation Mode: Only build the library
if(MODE STREQUAL "COMPILING")
  add_library(wxsdk_obj ${obj_sources_list})
  target_compile_options(wxsdk_obj PRIVATE ${obj_compile_options})
  target_include_directories(wxsdk_obj PRIVATE ${obj_includes})
  target_compile_definitions(wxsdk_obj PRIVATE ${obj_defines})
elseif (MODE STREQUAL "TESTING")
  include(tools/cmake/obj_tests.cmake)
  add_library(obj ${obj_ut_sources_list})
  target_compile_options(obj PRIVATE ${obj_tests_compile_options})
  target_include_directories(obj PRIVATE ${obj_tests_includes})
  target_compile_definitions(obj PRIVATE ${obj_tests_defines})
endif()