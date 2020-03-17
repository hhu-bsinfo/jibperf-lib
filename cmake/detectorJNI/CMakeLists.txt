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

project("detectorJNI")

message(STATUS "Project " ${PROJECT_NAME})

include_directories(${DETECTORJNI_SRC_DIR})
 
set(SOURCE_FILES
        ${DETECTORJNI_SRC_DIR}/detector-jni/Common.cpp
        ${DETECTORJNI_SRC_DIR}/detector-jni/NativeBuildConfig.cpp
        ${DETECTORJNI_SRC_DIR}/detector-jni/IbFabric.cpp
        ${DETECTORJNI_SRC_DIR}/detector-jni/IbNode.cpp
        ${DETECTORJNI_SRC_DIR}/detector-jni/IbPort.cpp
        ${DETECTORJNI_SRC_DIR}/detector-jni/IbDiagPerfCounter.cpp)
 
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/include/infiniband")

target_link_libraries(${PROJECT_NAME} ibverbs ibmad ibnetdisc detector)
