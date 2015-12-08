project(lab4)
cmake_minimum_required(VERSION 2.8)
add_executable(lab4
shared.h isensor.h cbinarysensor.h  ccontinuoussensor.h ccamerasensor.h
main.cpp warmup.cpp cbinarysensor.cpp ccontinuoussensor.cpp ccamerasensor.cpp)

