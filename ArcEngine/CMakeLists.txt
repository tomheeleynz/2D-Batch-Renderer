cmake_minimum_required(VERSION 3.17)
project(ArcEngine)

# Setting C++ Standard
set (CMAKE_CXX_STANDARD 17)

# GLOB together Files
file(GLOB ARC_CORE "src/Arc/Core/*.h" "src/Arc/Core/*.cpp")
file(GLOB ARC_SRC	"src/Arc.h")
file(GLOB ARC_RENDERER "src/Arc/Renderer/*.h" "src/Arc/Renderer/*.cpp")
file(GLOB ARC_SCENE "src/Arc/Scenes/*.h" "src/Arc/Scenes/*.cpp")
file(GLOB ARC_SCRIPTING "src/Arc/Scripting/*.cpp" "src/Arc/Scripting/*.h")
file(GLOB ARC_ECS "src/Arc/ECS/*.h" "src/Arc/ECS/*.cpp")

if (WIN32)
    file(GLOB ARC_POPENGL "src/Platform/Windows/OpenGL/*.h" "src/Platform/Windows/OpenGL/*.cpp")
	file(GLOB ARC_POPENGL_WINDOW "src/Platform/Windows/Window/*.h" "src/Platform/Windows/Window/*.cpp")
endif(WIN32)

if (APPLE)
    file(GLOB ARC_PMACOSX "src/Platform/MacOSX/Metal/*.h" "src/Platform/MacOSX/Metal/*.swift" "src/Platform/MacOSX/Metal/*.mm")
    file(GLOB ARC_PMACOSX_WINDOW "src/Platform/MacOSX/Window/*.h" "src/Platform/MacOSX/Window/*.swift" "src/Platform/MacOSX/Window/*.mm")
endif(APPLE)

# Set Include Directories
include_directories("src")

if (WIN32)
	message(STATUS "Compiling For Windows")

	# Setting Definitions
	add_definitions(-DARC_PLATFORM_WINDOWS)

    # --- GLFW
    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    add_subdirectory("vendor/glfw")

    # --- GLAD
    add_subdirectory("vendor/glad")

	# --- SOIL
	add_subdirectory("vendor/soil")

	#---- GLM
	add_subdirectory("vendor/glm")

    # Finding and Using OpenGL
    find_package(OpenGL REQUIRED)
    include_directories(${OPENGL_INCLUDE_DIRS})

    # Creating Window Library 
    add_library(ArcEngine STATIC 
		${ARC_CORE} 
		${ARC_POPENGL} 
		${ARC_SRC} 
		${ARC_RENDERER} 
		${ARC_SCENE} 
		${ARC_POPENGL_WINDOW}
        ${ARC_ECS}
	)

    # Linking Opengl
    target_link_libraries(ArcEngine ${OPENGL_LIBRARIES})

    # Linking GLFW
    target_link_libraries(ArcEngine glfw)

    # Linking GLAD
    target_link_libraries(ArcEngine glad)

	# Linking SOIL
	target_link_libraries(ArcEngine SOIL)

	# Linking GLM
	target_link_libraries(ArcEngine glm)
endif(WIN32)

if (APPLE)
    message(STATUS "Compiling For MacOSX")
    
	# Setting Definitions
	add_definitions(-DARC_PLATFORM_MACOSX)
    
	add_library(ArcEngine STATIC 
		${ARC_CORE} 
		${ARC_PMACOSX} 
		${ARC_PMACOSX_WINDOW} 
		${ARC_SRC} 
		${ARC_RENDERER} 
		${ARC_SCENE}
        ${ARC_SCRIPTING}
        ${ARC_ECS}
	)
    
    target_link_libraries(ArcEngine "-framework AppKit")
    target_include_directories(ArcEngine PUBLIC "src")

    # Linking Mono
    target_link_libraries(ArcEngine "/Library/Frameworks/Mono.framework/Versions/6.10.0/lib/libmonosgen-2.0.1.dylib")
    target_include_directories(ArcEngine PUBLIC "vendor/mono/mono-2.0")
    
    # Linking GLM
    target_include_directories(ArcEngine PUBLIC "vendor/glm")

    # Linking Entt
    target_include_directories(ArcEngine PUBLIC "vendor/entt/single_include")

    # Linking Rapid Json
    target_include_directories(ArcEngine PUBLIC "vendor/rapidjson/include")

endif(APPLE)



