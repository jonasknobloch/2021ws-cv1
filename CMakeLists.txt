cmake_minimum_required(VERSION 3.17)
project(inf_basx_cv1)

set(CMAKE_CXX_STANDARD 14)
set(OpenCV_DIR /Users/jonas/Build/opencv_build)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(exercise0 src/Ex0_Jonas_Knobloch.cpp)
target_link_libraries(exercise0 ${OpenCV_LIBS})
