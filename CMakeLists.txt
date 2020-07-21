cmake_minimum_required(VERSION 3.17)
project(ArcEngine)

set (CMAKE_CXX_STANDARD 11)

if (APPLE)
    enable_language(Swift)
    enable_language(OBJCXX)
endif(APPLE)

# Setting Directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/exe")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINDAR_DIR}/bin/lib")

add_subdirectory("ArcEngine")
add_subdirectory("Sandbox")

if (WIN32)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)
endif(WIN32)
