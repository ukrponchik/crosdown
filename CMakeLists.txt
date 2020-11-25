cmake_minimum_required(VERSION 3.18.0)
project(Lightdown VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/bus)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/set)
# add_subdirectory(${CMAKE_SOURCE_DIR}/src/3)