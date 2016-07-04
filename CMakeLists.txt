# CMake version
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# Include cmake modules

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Meta information about the project
set(META_PROJECT_NAME        "CookieQuestCpp")

# Declare project
project(${META_PROJECT_NAME} C CXX)

if(NOT MSVC)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)
endif()

add_subdirectory(src)
