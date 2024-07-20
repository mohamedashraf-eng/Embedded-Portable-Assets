cmake_minimum_required(VERSION 3.10)

# Building Core Software
message(STATUS  "Building Core SW @${node_sw}")
add_subdirectory("${node_sw}")

message(STATUS  "Building Core SW @${linkedlist_sw}")
add_subdirectory("${linkedlist_sw}")

message(STATUS  "Building Core SW @${stack_sw}")
add_subdirectory("${stack_sw}")

message(STATUS  "Building Core SW @${queue_sw}")
add_subdirectory("${queue_sw}")

message(STATUS  "Building Core SW @${math_sw}")
add_subdirectory("${math_sw}")

