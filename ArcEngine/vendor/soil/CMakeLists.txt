cmake_minimum_required(VERSION 3.17)
project(SOIL)

file(GLOB SOIL_HEADER_FILES "include/SOIL/*.h")
file(GLOB SOIL_SRC_FILES "src/*.c" "src/original/*.c")

add_library(SOIL STATIC ${SOIL_HEADER_FILES} ${SOIL_SRC_FILES})
target_include_directories(SOIL PUBLIC "include")