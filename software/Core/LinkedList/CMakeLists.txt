# CMake Version Check
cmake_minimum_required(VERSION 3.14)

# Project
project(wxsdk_linkedlist 
        LANGUAGES C CXX
        VERSION "1.0.0"
        DESCRIPTION "linkedlist")

##############################################################################        
# Include Common Compilation Settings                                       #
##############################################################################

include(tools/CMake/linkedlist_compile.cmake)

##############################################################################
# Extract Module Path in build/CMake/Test/                                   #
##############################################################################

##############################################################################
# Build Configuration                                                        #
##############################################################################

# Compilation Mode: Only build the library
if(MODE STREQUAL "COMPILING")
  add_library(wxsdk_linkedlist ${linkedlist_sources_list})
  target_compile_options(wxsdk_linkedlist PRIVATE ${linkedlist_compile_options})
  target_include_directories(wxsdk_linkedlist PRIVATE ${linkedlist_includes})
  target_compile_definitions(wxsdk_linkedlist PRIVATE ${linkedlist_defines})
elseif (MODE STREQUAL "TESTING")
  include(tools/cmake/linkedlist_tests.cmake)
  add_library(linkedlist ${linkedlist_ut_sources_list})
  target_compile_options(linkedlist PRIVATE ${linkedlist_tests_compile_options})
  target_include_directories(linkedlist PRIVATE ${linkedlist_tests_includes})
  target_compile_definitions(linkedlist PRIVATE ${linkedlist_tests_defines})
endif()