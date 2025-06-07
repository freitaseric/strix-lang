cmake_minimum_required(VERSION 3.10)

project(strix VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(PkgConfig REQUIRED)

pkg_check_modules(PC_LIBEDIT REQUIRED IMPORTED_TARGET libedit)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Internal library
file(GLOB_RECURSE LIB_SOURCES "${SOURCE_DIR}/lib/*.cpp")

add_library(strix_library ${LIB_SOURCES})

target_include_directories(strix_library PUBLIC ${SOURCE_DIR}/lib)

# CLI binary
file(GLOB_RECURSE CLI_SOURCES "${SOURCE_DIR}/cli/*.cpp")

add_executable(${PROJECT_NAME} ${CLI_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE strix_library)
target_link_libraries(${PROJECT_NAME} PRIVATE PkgConfig::PC_LIBEDIT)

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})