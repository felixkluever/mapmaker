CMAKE_MINIMUM_REQUIRED(VERSION 3.21)
set (CMAKE_CXX_STANDARD 23)

# variables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin")



project(
    MapMaker
    VERSION 1.0
    LANGUAGES CXX
)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/include/*.h"
    "${PROJECT_SOURCE_DIR}/include/*.hpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.c"
)

add_executable(
    mapmaker
    ${all_SRCS}
)
