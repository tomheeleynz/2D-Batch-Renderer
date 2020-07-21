cmake_minimum_required(VERSION 3.17)
project(glad)

file(GLOB SRC "src/glad.c")
file(GLOB GLAD "include/glad/glad.h")
file(GLOB KHR "include/KHR/khrplatform.h")

add_library(glad ${SRC} ${GLAD} ${KHR})

target_include_directories(glad PUBLIC "include")