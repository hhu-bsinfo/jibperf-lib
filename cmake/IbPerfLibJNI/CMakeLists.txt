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

project(IbPerfLibJNI)
message(STATUS "Project " ${PROJECT_NAME})

include_directories(${IBPERFLIBJNI_SRC_DIR})
 
set(SOURCE_FILES
        ${IBPERFLIBJNI_SRC_DIR}/ibperflib-jni/Common.cpp
        ${IBPERFLIBJNI_SRC_DIR}/ibperflib-jni/NativeBuildConfig.cpp
        ${IBPERFLIBJNI_SRC_DIR}/ibperflib-jni/IbFabric.cpp
        ${IBPERFLIBJNI_SRC_DIR}/ibperflib-jni/IbNode.cpp
        ${IBPERFLIBJNI_SRC_DIR}/ibperflib-jni/IbPort.cpp
        ${IBPERFLIBJNI_SRC_DIR}/ibperflib-jni/IbDiagPerfCounter.cpp)
 
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/include/infiniband -libverbs -libmad -libnetdisc")

target_link_libraries(${PROJECT_NAME} IbPerfLib)
