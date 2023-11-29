CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

# variables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin")

project(
    MapMaker
    VERSION 1.0
    LANGUAGES CXX
)

add_executable(
    mapmaker
    main.cpp
)