cmake_minimum_required(VERSION 3.10)

project(strix VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS OFF) # Optional: disable GNU extensions

set(CMAKE_C_COMPILER clang)

find_package(PkgConfig REQUIRED)

pkg_check_modules(PC_LIBEDIT REQUIRED IMPORTED_TARGET libedit)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin) # For older CMake versions

file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.c")

file(GLOB_RECURSE HEADERS "${SOURCE_DIR}/*.h")

add_library(strix_tokenizer src/token.cpp src/strix_tokenizer_api.cpp)
target_include_directories(strix_tokenizer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE strix_tokenizer)
target_link_libraries(${PROJECT_NAME} PRIVATE PkgConfig::PC_LIBEDIT)

message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "C Standard: ${CMAKE_C_STANDARD}")
message(STATUS "Source Files: ${SOURCES}")
message(STATUS "Binary Directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

