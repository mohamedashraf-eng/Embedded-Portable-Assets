include Makefile.variables

##############################################################################
# Shell Colors                                                               #
##############################################################################
UND=\e[4m
CUR=\e[3m
NC=\033[0m

ERROR=\033[0;31m
INFO=\033[32m
WARNING=\033[92m
HEADRS=$(UND)$(CUR)

##############################################################################
# Build                                                                      #
##############################################################################

CMAKE_BUILD_VARIABLES =
CMAKE_BUILD_VARIABLES += -DTOOLCHAIN_DIR=$(TOOLCHAIN_DIR)
CMAKE_BUILD_VARIABLES += -DCMAKE_PROJECT_DIR=$(CMAKE_PROJECT_DIR)
CMAKE_BUILD_VARIABLES += -DSW_DIR=$(SW_DIR)
CMAKE_BUILD_VARIABLES += -DMODE=COMPILING

CMAKE_BUILD_VARIABLES += -DCMAKE_TOOLCHAIN_FILE=$(CMAKE_PROJECT_DIR)/wx_build_native_toolchain.cmake
build_native_core:
ifeq ($(rebuild),1)
	-@rm -rf $(BUILD_DIR)
endif
	@mkdir -p $(BUILD_DIR)
	@echo "BUILD_DIR=$(BUILD_DIR)"
	cd $(BUILD_DIR)/ && \
	cmake -S $(CURDIR) -B $(BUILD_DIR) -DSOFTWARE_COMPONENT=wxsdk $(CMAKE_BUILD_VARIABLES) ; \
 	make wxsdk install -j$(MAXIMUM_CPU_CORES) 

CMAKE_BUILD_VARIABLES += -DCMAKE_TOOLCHAIN_FILE=$(CMAKE_PROJECT_DIR)/wx_build_target_toolchain.cmake
build_target_core:
ifeq ($(rebuild),1)
	-@rm -rf $(BUILD_DIR)
endif
	@mkdir -p $(BUILD_DIR)
	@echo "BUILD_DIR=$(BUILD_DIR)"
	cd $(BUILD_DIR)/ && \
	cmake -S $(CURDIR) -B $(BUILD_DIR) -DSOFTWARE_COMPONENT=core_sw $(CMAKE_BUILD_VARIABLES) ;\
 	make wxsdk install -j$(MAXIMUM_CPU_CORES)

##############################################################################
# Test                                                                       #
##############################################################################

##############################################################################
# Build Test files                                                           #
##############################################################################

##############################################################################
# Check Dependencies                                                        #
##############################################################################

error_msg:
	@echo "--------------------------------------------------------------------------------------------------------------------------------"
	@echo "${ERROR}Your dev container run out of data.${NC}"
	@echo "--------------------------------------"
	@echo "    1. Remove the Docker container using the command: ${INFO}docker rm -f mycontainer $(shell cat /etc/hostname)${NC}"
	@echo "If any of the above steps fail, please check your setup and try again."
	@echo "--------------------------------------------------------------------------------------------------------------------------------"

##############################################################################
# help                                                                       #
##############################################################################
help:
	@echo ""
	@echo "${HEADRS}Available targets:${NC}"
	@echo "  build        - Generate executable files for the target MCU."
	@echo "  unit_test    - Run unit tests of project components."
	@echo "  build_test   - Sub-process from ${HEADRS}unit_test${NC} to build test files only."
	@echo "  test         - Sub-process from ${HEADRS}unit_test${NC} to execute pre-built test files."
	@echo ""
	@echo "${HEADRS}Available Options:${NC}"
	@echo "  rebuild=1           - It will rebuild whole project (valid for build and unit_test only)."
	@echo "                      - ${HEADRS}Options${NC}: {0,1}"
	@echo "                      - ${HEADRS}Defailt Value${NC}: 0"
	@echo ""
	@echo "  HTML_THEME=green    - It will generate html with selected theme (valid for coverage and unit_test only)."
	@echo "                      - ${HEADRS}Options${NC}: {green,blue,github.blue,github.green,github.dark-green,github.dark-blue}"
	@echo "                      - ${HEADRS}Defailt Value${NC}: github.green"
	@echo ""
	@echo "${HEADRS}Use${NC}: make ${INFO}<target> <Option1> <Option2> ...${NC} "
	@echo ""

all: build_target_core build_native_core

.PHONY: build_target_core build_native_core