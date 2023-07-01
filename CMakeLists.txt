cmake_minimum_required(VERSION 2.8.9)
project(dmst)

#Bring the headers into the project
include_directories(inc)

#Can manually add the sources using the set command as follows:
set(SOURCES src/dmst.cpp src/dmst_cfg.cpp src/main.cpp )

#However, the file(GLOB...) allows for wildcard additions:
#file(GLOB SOURCES "src/*.cpp")

add_executable(artifact ${SOURCES})