cmake_minimum_required(VERSION 3.5.1)

project(starcraft VERSION 1.1.0)

### include cmake_helpers files with functions
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers_c.cmake)

### message to display the project name and version
message(STATUS "Project: ${PROJECT_NAME} v${PROJECT_VERSION}")

### set variable for the source folder
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

### generate project binary
add_executable(
    ${PROJECT_NAME}

    ${SRC_DIR}/AirShip.c
    ${SRC_DIR}/BattleCruser.c
    ${SRC_DIR}/BattleField.c
    ${SRC_DIR}/Carrier.c
    ${SRC_DIR}/main.c
    ${SRC_DIR}/Phoenix.c
    ${SRC_DIR}/ProtossAirShip.c
    ${SRC_DIR}/TerranAirShip.c
    ${SRC_DIR}/Vector.c
    ${SRC_DIR}/Viking.c
)

### include the include folder with the header files
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

### set target for the C standard using function from helpers_c.cmake file
set_target_c_standard(${PROJECT_NAME} 11)
enable_target_c_warnings(${PROJECT_NAME})
