cmake_minimum_required(VERSION 3.12)
project(demoOpenCV2)

set(CMAKE_CXX_STANDARD 11)

add_executable(demoOpenCV2 main.cpp)

FIND_PACKAGE(OpenCV REQUIRED)
TARGET_LINK_LIBRARIES(demoOpenCV2 ${OpenCV_LIBS})