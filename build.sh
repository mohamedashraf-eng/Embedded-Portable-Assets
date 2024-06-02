#!/bin/bash

rebuild=$1
ide=$2
num_cores=$(nproc)

# Color codes for styling
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
BLUE="\033[0;34m"
BOLD="\033[1m"
RESET="\033[0m"

# Function to echo colored text
echo_color() {
    local color=$1
    local message=$2
    echo -e "${color}${message}${RESET}"
}

# Function to check if a file exists
check_file_exists() {
    if [ ! -f "$1" ]; then
        echo_color $RED "${BOLD}Error: File '$1' not found.${RESET}"
        
    fi
}

# Pre conditions
echo "------------------------------------------------------------------------------------------------------"
echo_color $BLUE "${BOLD}Building Software${RESET}"

echo_color $BLUE "${BOLD}Building from CMake${RESET}"
if [ "$rebuild" == "1" ]; then
    echo_color $BLUE "${BOLD}Rebuilding is True${RESET}"
    if ! make build_native_core rebuild=1; then
        echo_color $RED "${BOLD}Error: Build failed.${RESET}"
        
    fi
else
    if ! make build_native_core; then
        echo_color $RED "${BOLD}Error: Build failed.${RESET}"
        
    fi
fi

echo "------------------------------------------------------------------------------------------------------"


echo "------------------------------------------------------------------------------------------------------"

echo "------------------------------------------------------------------------------------------------------"

echo "------------------------------------------------------------------------------------------------------"
# Redirect the output of Target Application

echo "------------------------------------------------------------------------------------------------------"
echo_color $BLUE "${BOLD}Program Execution Output${RESET}"
./tools/build/CMake/output/build/wxsdk
echo "------------------------------------------------------------------------------------------------------"