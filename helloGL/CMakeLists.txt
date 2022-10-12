cmake_minimum_required(VERSION 3.4)
project(hellogl)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(GLFW REQUIRED)


add_executable(MAIN src/main.cpp)
target_include_directories(MAIN PUBLIC include) 

