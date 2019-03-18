# Copyright (C) 2018 Heinrich-Heine-Universitaet Duesseldorf,
# Institute of Computer Science, Department Operating Systems
#
# This program is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation, either version 3 of the License,
# or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>

cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

# Get JNI variables
find_package(JNI)

if(JNI_FOUND)
    message(STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
    message(STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")

    include_directories(${JNI_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "JNI location not found! Aborting build...")
endif()

# Set git branch
execute_process(COMMAND git rev-parse --symbolic-full-name --abbrev-ref HEAD
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        OUTPUT_VARIABLE IBPERFLIBJNI_GIT_BRANCH ERROR_QUIET)
string(STRIP "${IBPERFLIBJNI_GIT_BRANCH}" IBPERFLIBJNI_GIT_BRANCH)
if (IBPERFLIBJNI_GIT_BRANCH STREQUAL "")
    set(IBPERFLIBJNI_GIT_BRANCH "master")
endif()

# Set source directory variables
set(IBPERFLIBJNI_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}/..")
set(IBPERFLIBJNI_SRC_DIR "${IBPERFLIBJNI_ROOT_DIR}/src/main/cpp")

# Set output directory variables
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${IBPERFLIBJNI_ROOT_DIR}/build/libs)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${IBPERFLIBJNI_ROOT_DIR}/build/libs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${IBPERFLIBJNI_ROOT_DIR}/build/libs)

# Set compiler-flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

# Add IbPerfLib as external project
ExternalProject_Add(IbPerfLib_git
        GIT_REPOSITORY https://github.com/hhu-bsinfo/ibperf-lib.git
        GIT_TAG ${IBPERFLIBJNI_GIT_BRANCH}
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/IbPerfLib
        INSTALL_COMMAND "")

ExternalProject_Get_Property(IbPerfLib_git binary_dir)
ExternalProject_Get_Property(IbPerfLib_git source_dir)

add_library(IbPerfLib STATIC IMPORTED)
set_property(TARGET IbPerfLib PROPERTY IMPORTED_LOCATION ${binary_dir}/ar/libIbPerfLib.a)

add_dependencies(IbPerfLib IbPerfLib_git)

include_directories(${source_dir}/src)

add_subdirectory(IbPerfLibJNI)
