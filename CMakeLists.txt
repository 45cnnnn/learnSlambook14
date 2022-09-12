cmake_minimum_required(VERSION 3.12)
project(chapter3)

set(CMAKE_CXX_FLAGS "-std=c++11")

set(OpenCV_DIR  ~/Downloads/opencv/opencv-4.5.2/build)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# 加入各子项目
add_subdirectory(ch3)
add_subdirectory(ch5)
add_subdirectory(ch6)
add_subdirectory(ch7)
add_subdirectory(vo_project/0.1)