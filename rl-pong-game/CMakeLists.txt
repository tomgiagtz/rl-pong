cmake_minimum_required(VERSION 3.14)

# Get the project name from the current directory name
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set default build type
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type" FORCE)
endif ()

# set OPENGL_VERSION
unset(OPENGL_VERSION CACHE)
set(OPENGL_VERSION "3.3" CACHE STRING "Version of OpenGL to build Raylib against" FORCE)

# Include FetchContent module for downloading external content
include(FetchContent)

# Set Raylib directory
set(raylib_dir "${CMAKE_SOURCE_DIR}/external/raylib-master")

# Download Raylib if it's not already present
if (NOT EXISTS "${raylib_dir}/CMakeLists.txt")
    message(STATUS "Raylib not found, downloading from GitHub")
    FetchContent_Declare(
            raylib
            GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
            GIT_TAG "master"
            SOURCE_DIR "${raylib_dir}"
    )
    FetchContent_MakeAvailable(raylib)
endif ()

# Set options for Raylib
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build Raylib as a shared library" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "Don't build Raylib examples" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "Don't build Raylib games" FORCE)

# Add Raylib to the project
add_subdirectory("${raylib_dir}" "${CMAKE_CURRENT_BINARY_DIR}/raylib")

# Set output directories
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")
set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")

# Collect source files
file(GLOB_RECURSE PROJECT_HEADERS "${CMAKE_SOURCE_DIR}/include/*.h" "${CMAKE_SOURCE_DIR}/include/*.hpp" "${CMAKE_SOURCE_DIR}/src/*.h" "${CMAKE_SOURCE_DIR}/src/*.hpp")
file(GLOB_RECURSE PROJECT_SOURCES "${CMAKE_SOURCE_DIR}/src/*.c" "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Add executable target
add_executable(${PROJECT_NAME} ${PROJECT_HEADERS} ${PROJECT_SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/src" "${CMAKE_SOURCE_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE
        "${raylib_dir}/src"
        "${raylib_dir}/src/external"
        "${raylib_dir}/src/external/glfw/include"
)

# Link Raylib library
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Platform-specific settings
if (MSVC)
    target_compile_definitions(${PROJECT_NAME} PRIVATE _WINSOCK_DEPRECATED_NO_WARNINGS _CRT_SECURE_NO_WARNINGS)
    target_compile_options(${PROJECT_NAME} PRIVATE /Zc:__cplusplus)
    set_target_properties(${PROJECT_NAME} PROPERTIES CHARACTER_SET "Unicode")
elseif (WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE _WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE winmm gdi32)
elseif (UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE pthread m dl rt X11)
    target_compile_definitions(${PROJECT_NAME} PRIVATE _GLFW_X11 _GNU_SOURCE)
elseif (APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE
            "-framework OpenGL"
            "-framework Cocoa"
            "-framework IOKit"
            "-framework CoreFoundation"
            "-framework CoreAudio"
            "-framework CoreVideo"
            "-framework AudioToolbox"
    )
    add_compile_options(-Wno-deprecated-declarations)
endif ()
