CMAKE_MINIMUM_REQUIRED(VERSION 3.21)
set (CMAKE_CXX_STANDARD 20)
set (CMALE_CXX_STANDARD_REQUIRE ON)

project(
    MapMaker
    VERSION 1.0
    LANGUAGES CXX
)

# Find the SFML package
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# variables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin")

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

# Link SFML libraries
target_link_libraries(mapmaker sfml-graphics sfml-window sfml-system)

