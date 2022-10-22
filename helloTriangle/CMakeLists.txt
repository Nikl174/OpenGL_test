cmake_minimum_required(VERSION 3.4)
project(hellogl)

find_package(glfw3 3.3 REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(GLAD src/glad.c)
target_include_directories(GLAD 
PUBLIC include)

add_executable(MAIN src/main.cpp)
target_include_directories(MAIN 
    PUBLIC include
)
target_link_libraries(MAIN
PUBLIC GLAD
PUBLIC glfw)


