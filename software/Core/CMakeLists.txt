cmake_minimum_required(VERSION 3.10)

# Building Core Software
message(STATUS  "Building Core SW @${linkedlist_sw}")
add_subdirectory("${linkedlist_sw}")

message(STATUS  "Building Core SW @${queue_sw}")
add_subdirectory("${queue_sw}")

message(STATUS  "Building Core SW @${Stack_sw}")
add_subdirectory("${stack_sw}")

# message(STATUS  "Building Core SW @${Tree_sw}")
# add_subdirectory("${Tree_sw}")

# message(STATUS  "Building Core SW @${Graph_sw}")
# add_subdirectory("${Graph_sw}")

message(STATUS  "Building Core SW @${Math_sw}")
add_subdirectory("${math_sw}")

