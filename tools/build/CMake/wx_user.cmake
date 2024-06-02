message(STATUS "SW_DIR = ${SW_DIR}")
message(STATUS "BUILD_TESTS_DIR = ${BUILD_TESTS_DIR}")

set( CMAKE_INSTALL_PREFIX "./" CACHE PATH "Default install path")

##############################################################################
# Common Directories                                                         #
##############################################################################
set( common_platform_includes "${SW_DIR}/Platform" CACHE PATH "Default")

set( core_sw "${SW_DIR}/Core" CACHE PATH "Default")

set( linkedlist_sw "${core_sw}/LinkedList" CACHE PATH "Default")
set( queue_sw "${core_sw}/Queue" CACHE PATH "Default")
set( stack_sw "${core_sw}/Stack" CACHE PATH "Default")
set( tree_sw "${core_sw}/Tree" CACHE PATH "Default")
set( graph_sw "${core_sw}/Graph" CACHE PATH "Default")
set( math_sw "${core_sw}/Math" CACHE PATH "Default")

set( app_sw "${SW_DIR}/App" CACHE PATH "Default")

##############################################################################
# App Software Components                                                    #
############################################################################## 

##############################################################################
# Frameworks                                                                 #
############################################################################## 

##############################################################################
# Dependencies                                                               #
##############################################################################

##############################################################################
# Functions                                                                 #
##############################################################################