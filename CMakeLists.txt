cmake_minimum_required(VERSION 4.2)

file(GLOB_RECURSE ENGINE_SOURCES src/main.cpp)

# language settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

# build and executable settings
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_CACHEFILE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

#  lib configs
set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(BUILD_SHARED_LIBS true)

#  build configs
set(CMAKE_BUILD_TYPE "Debug")

#  project configs
project(snake VERSION 0.1)
add_executable(${PROJECT_NAME} ${ENGINE_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ./src/include)
