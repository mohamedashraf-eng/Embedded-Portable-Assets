set(COMMON_FLAGS "-Wall")

set(CMAKE_C_FLAGS          "${COMMON_FLAGS}")
set(CMAKE_CXX_FLAGS        "${COMMON_FLAGS}")

set(CMAKE_C_COMPILER       gcc)
set(CMAKE_CXX_COMPILER     g++)
set(CMAKE_AR               ar)

set(CMAKE_EXE_LINKER_FLAGS "-Wl,-Map,wxpsec_swc.map")

set(CMAKE_C_CREATE_STATIC_LIBRARY "<CMAKE_AR> -crs <TARGET> <LINK_FLAGS> <OBJECTS>")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE BOTH)