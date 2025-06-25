set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED True)

cmake_minimum_required(VERSION 3.10)

project(pagination VERSION 1.0)

file(GLOB SOURCES "src/*.cpp")
add_executable(pagination ${SOURCES})

target_include_directories(pagination PRIVATE includes)
