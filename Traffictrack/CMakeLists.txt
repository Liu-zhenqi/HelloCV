cmake_minimum_required(VERSION 3.10)
project(trafficTrack)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
add_executable(trafficTrack  trafficTrack.cpp)
target_link_libraries(trafficTrack ${OpenCV_LIBS})
