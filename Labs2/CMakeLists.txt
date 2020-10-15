cmake_minimum_required(VERSION 3.17)
project(Labs2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Labs2 cmake-build-debug/Vehicle.cpp cmake-build-debug/Vehicle.h cmake-build-debug/Showroom.cpp cmake-build-debug/Showroom.h cmake-build-debug/Dealership.cpp cmake-build-debug/Dealership.h cmake-build-debug/main.cpp)