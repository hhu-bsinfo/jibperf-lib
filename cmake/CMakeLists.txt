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

project(detectorJNI)

cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

# Get JNI variables
find_package(JNI REQUIRED)

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
        OUTPUT_VARIABLE DETECTORJNI_GIT_BRANCH ERROR_QUIET)
string(STRIP "${DETECTORJNI_GIT_BRANCH}" DETECTORJNI_GIT_BRANCH)
if (DETECTORJNI_GIT_BRANCH STREQUAL "")
    set(DETECTORJNI_GIT_BRANCH "master")
endif()

# Set source directory variables
set(DETECTORJNI_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}/..")
set(DETECTORJNI_SRC_DIR "${DETECTORJNI_ROOT_DIR}/src/main/cpp")

# Set output directory variables
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${DETECTORJNI_ROOT_DIR}/build/libs)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${DETECTORJNI_ROOT_DIR}/build/libs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DETECTORJNI_ROOT_DIR}/build/libs)

# Set compiler-flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

include(ExternalProject)

ExternalProject_Add(detector_git
        GIT_REPOSITORY https://github.com/hhu-bsinfo/detector.git
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/detector
        INSTALL_COMMAND "")

ExternalProject_Get_Property(detector_git binary_dir)
ExternalProject_Get_Property(detector_git source_dir)

add_library(detector STATIC IMPORTED)
set_property(TARGET detector PROPERTY IMPORTED_LOCATION ${binary_dir}/ar/libdetector.a)

add_dependencies(detector detector_git)

include_directories(${source_dir}/src)

add_subdirectory(detectorJNI)
