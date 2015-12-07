project(lab4)
cmake_minimum_required(VERSION 2.8)
add_executable(lab4
main.cpp warmup.cpp shared.h
isensor.h cbinarysensor.h cbinarysensor.cpp ccontinuoussensor.cpp ccontinuoussensor.h
ccamerasensor.h ccamerasensor.cpp)

