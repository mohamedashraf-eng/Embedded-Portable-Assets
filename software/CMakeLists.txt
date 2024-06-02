cmake_minimum_required(VERSION 3.10)

# Building Core Software
message(STATUS "Building Core SW @${core_sw}")
add_subdirectory("${core_sw}")

message(STATUS  "Building Core SW @${app_sw}")
add_subdirectory("${app_sw}")