# CMake Version Check
cmake_minimum_required(VERSION 3.14)

# Project
project(wxsdk 
        LANGUAGES C CXX
        VERSION "1.0.0"
        DESCRIPTION "wxsdk")

set(SOFTWARE_COMPONENT "wxsdk")
##############################################################################
# Include Common Compilation Settings                                       #
##############################################################################

include(tools/CMake/wxsdk_compile.cmake)

##############################################################################
# Build Configuration                                                        #
##############################################################################

# Compilation Mode: Only build the library
if(MODE STREQUAL "COMPILING")
  add_executable(wxsdk ${wxsdk_sources_list})
  target_compile_options(wxsdk PRIVATE ${wxsdk_compile_options})
  target_include_directories(wxsdk PRIVATE ${wxsdk_includes})
  target_compile_definitions(wxsdk PRIVATE ${wxsdk_defines})
  target_link_libraries(wxsdk PRIVATE ${wxsdk_libs})

  install( PROGRAMS $<TARGET_FILE:wxsdk>  PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ DESTINATION ${CMAKE_BINARY_DIR}/../output/build RENAME wxsdk)

elseif (MODE STREQUAL "TESTING")
  include(tools/cmake/wxsdk_tests.cmake)
  add_executable(wxsdk_test ${wxsdk_tests_sources_list})
endif()
