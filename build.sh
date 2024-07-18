#!/usr/bin/env bash

rebuild=$1
test=$2
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
        echo_color "$RED" "${BOLD}Error: File '$1' not found.${RESET}"
        exit 1
    fi
}

echo "------------------------------------------------------------------------------------------------------"

# Build the project
echo_color "$BLUE" "${BOLD}Building from CMake${RESET}"
if [ "$test" == "1" ]; then 
    echo_color "$BLUE" "${BOLD}Testing software${RESET}"
    if ! make unit_test; then
        echo_color "$RED" "${BOLD}Error: Build failed.${RESET}"
        exit 1
    fi
else
    echo_color "$BLUE" "${BOLD}Building software${RESET}"
    if [ "$rebuild" == "1" ]; then
        echo_color "$BLUE" "${BOLD}Rebuilding is True${RESET}"
        if ! make build rebuild=1; then
            echo_color "$RED" "${BOLD}Error: Build failed.${RESET}"
            exit 1
        fi
    else
        if ! make build; then
            echo_color "$RED" "${BOLD}Error: Build failed.${RESET}"
            exit 1
        fi
    fi
fi
echo "------------------------------------------------------------------------------------------------------"