cmake_minimum_required(VERSION 2.6)
project (Mtgsim)
file(GLOB Sources "src/*.cpp")
file(GLOB Includes "include/*.h")
include_directories(include)
add_executable(mtg main.cpp ${Sources} ${Includes} )

SET(GCC_COVERAGE_COMPILE_FLAGS "-w")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
