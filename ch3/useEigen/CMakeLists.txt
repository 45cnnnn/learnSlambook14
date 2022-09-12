cmake_minimum_required(VERSION 3.12)
project(useEigen)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGs "-03")

# Eigen 库只有头文件，所以不需要target_link_libraries语句将程序链接到库上
# 其他大部分库还是需要
include_directories("/usr/include/eigne3") 
add_executable(eigenMatrix eigenMatrix.cpp)