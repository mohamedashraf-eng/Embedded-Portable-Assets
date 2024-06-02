# Set common compiler flags
set(COMMON_FLAGS "-g")

# Add optimization flags
set(OPTIMIZATION_FLAGS "-O2")

# Add useful warning flags
set(WARNING_FLAGS "-Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wcast-qual -Wcast-align -Wnull-dereference -Wredundant-decls -Wswitch-default -Wswitch-enum -Wunused-parameter -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations")

# Add standard compliance flag
set(STANDARD_FLAGS "-std=c11")

# Add some more helpful flags
set(ADDITIONAL_FLAGS "-fstack-protector-strong -D_FORTIFY_SOURCE=2 -fsanitize=address,undefined -fno-omit-frame-pointer -fno-common")

# Combine all flags
set(CMAKE_C_FLAGS "${COMMON_FLAGS} ${OPTIMIZATION_FLAGS} ${WARNING_FLAGS} ${STANDARD_FLAGS} ${ADDITIONAL_FLAGS}")

# Optionally, set specific flags for Release and Debug configurations
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -g3")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3 -DNDEBUG")

set(CMAKE_C_COMPILER    gcc)
set(CMAKE_CXX_COMPILER  g++)
set(CMAKE_AR            gcc-ar)

set(CMAKE_C_CREATE_STATIC_LIBRARY "<CMAKE_AR> -crs <TARGET> <LINK_FLAGS> <OBJECTS>")

# Print the used flags for verification
message(STATUS "C Compiler Flags: ${CMAKE_C_FLAGS}")
