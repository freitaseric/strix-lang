cmake_minimum_required(VERSION 3.10)

project(strix VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_COMPILER clang++)

find_package(PkgConfig REQUIRED)

pkg_check_modules(PC_LIBEDIT REQUIRED IMPORTED_TARGET libedit)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

file(GLOB_RECURSE MAIN_SOURCES "${SOURCE_DIR}/*.cpp")

add_executable(${PROJECT_NAME} ${MAIN_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE PkgConfig::PC_LIBEDIT)

message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Source Files: ${MAIN_SOURCES}")
message(STATUS "Binary Directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")