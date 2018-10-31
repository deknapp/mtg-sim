cmake_minimum_required(VERSION 2.6)
project (Mtgsim)
file(GLOB Sources "*.cpp")
add_executable(mtg main.cpp ${Sources} )

