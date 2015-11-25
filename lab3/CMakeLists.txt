cmake_minimum_required(VERSION 2.8)
# we use Boost library
set(Boost_USE_STATIC_LIBS   ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_ADDITIONAL_VERSIONS "1.44" "1.44.0")
find_package(Boost COMPONENTS thread date_time program_options filesystem system REQUIRED)
find_package(Threads REQUIRED)

# 
find_package(PythonLibs REQUIRED)


#SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" "-lpython2.7 -std=c++11")


# all include libraries
include_directories(${Boost_INCLUDE_DIRS}
                    ${PYTHON_INCLUDE_DIRS}
                    include
)

# Robot library
add_library(robot SHARED src/robot.cpp src/sensor_range.cpp include/robot.h include/envir.h include/sensor.h include/sensor_range.h)

# Lab 3: using the robot class
# Lab 4: sensors on robot
add_executable(lab3 src/main.cpp include/defaults.h)
target_link_libraries(lab3 robot ${PYTHON_LIBRARIES})



# Lab 5: using Boost
#target_link_libraries(myboost ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})
