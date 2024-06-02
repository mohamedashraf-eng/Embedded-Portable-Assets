cmake_minimum_required(VERSION 3.10)

project(wxsdk)

include("${CMAKE_PROJECT_DIR}/wx_user.cmake")

# Building SW
message(STATUS "Building SW @${SW_DIR}")
add_subdirectory("${SW_DIR}")
