message(STATUS "SW_DIR = ${SW_DIR}")
message(STATUS "BUILD_TESTS_DIR = ${BUILD_TESTS_DIR}")

set( CMAKE_INSTALL_PREFIX "./" CACHE PATH "Default install path")

##############################################################################
# Common Directories                                                         #
##############################################################################

set( ports_dir "ports/" CACHE PATH "Default")
set( software_dir "${SW_DIR}" CACHE PATH "Default")
set( core_dir "${SW_DIR}/Core" CACHE PATH "Default")
set( platform "${SW_DIR}/Platform" CACHE PATH "Default")


##############################################################################
# Core Software Components                                                 #
############################################################################## 

set( node_sw "${core_dir}/Node" CACHE PATH "Default")
set( linkedlist_sw "${core_dir}/LinkedList" CACHE PATH "Default")
set( stack_sw "${core_dir}/Stack" CACHE PATH "Default")
set( queue_sw "${core_dir}/Queue" CACHE PATH "Default")
set( tree_sw "${core_dir}/Tree" CACHE PATH "Default")
set( graph_sw "${core_dir}/Graph" CACHE PATH "Default")
#
set( math_sw "${core_dir}/Math" CACHE PATH "Default")

##############################################################################
# Frameworks                                                                 #
############################################################################## 

set( CMOCK_ROOT_DIR  "/workspace/tools/frameworks/CMock" CACHE PATH "Default")
set( UNITY_ROOT_DIR  "${CMOCK_ROOT_DIR}/vendor/unity" CACHE PATH "Default")

set(CMOCK_SCRIPT "${CMOCK_ROOT_DIR}/lib/cmock.rb")
set(CMOCK_CONFIG_FILE "/workspace/tools/build/CMake/cmockConfig.yml")

##############################################################################
# Dependencies                                                               #
##############################################################################
set(
    unity_common_sources

    ${UNITY_ROOT_DIR}/src/unity.c
    ${UNITY_ROOT_DIR}/extras/fixture/src/unity_fixture.c
    ${CMOCK_ROOT_DIR}/src/cmock.c
)
set(
    unity_common_includes

    ${CMOCK_ROOT_DIR}/src
    ${UNITY_ROOT_DIR}/src
    ${UNITY_ROOT_DIR}/extras/fixture/src
    ${UNITY_ROOT_DIR}/extras/memory/src/
)
##############################################################################
# Functions                                                                 #
##############################################################################
function(extract_module_path source_var_name dest_var_name)
    # Extract the desired path
    string(REGEX REPLACE "^/workspace" "" MODULE_PATH "${${source_var_name}}")

    # Concatenate with BUILD_TESTS_DIR
    set(${dest_var_name} "${BUILD_TESTS_DIR}${MODULE_PATH}" PARENT_SCOPE)
endfunction()