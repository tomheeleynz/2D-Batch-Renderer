cmake_minimum_required(VERSION 3.17)
project(Sandbox)

# Setting C++ Standard
set (CMAKE_CXX_STANDARD 17)

# GLOB together Files
file(GLOB ENTRY "src/*.cpp" "src/*.h")

# Setting Include Directory For Arc
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../ArcEngine/src)

# Creating Executable
if(WIN32)
    # Setting Definitions
	add_definitions(-DARC_PLATFORM_WINDOWS)
    add_executable(Sandbox ${ENTRY})
endif(WIN32)

if (APPLE)
    add_definitions(-DARC_PLATFORM_MACOSX)
    add_executable(Sandbox ${ENTRY})
endif(APPLE)

# Linking ArcEngine to Sandbox App
target_link_libraries(Sandbox ArcEngine)
