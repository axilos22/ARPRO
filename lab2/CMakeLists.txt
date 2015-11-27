project(lab2)
cmake_minimum_required(VERSION 2.8)

# we use Boost library
set(Boost_USE_STATIC_LIBS   OFF)
set(Boost_USE_MULTITHREADED OFF)
set(Boost_ADDITIONAL_VERSIONS "1.44" "1.44.0")
find_package(Boost COMPONENTS thread date_time program_options filesystem system REQUIRED)

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

