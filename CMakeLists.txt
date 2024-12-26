cmake_minimum_required(VERSION 3.31)

project(lagrange)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES src/*.cppm)
add_library(${PROJECT_NAME} STATIC SHARED)
target_sources(${PROJECT_NAME} PUBLIC FILE_SET CXX_MODULES FILES ${SOURCES})

find_package(stdexec REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE STDEXEC::stdexec)

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)

find_package(cryptopp REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE cryptopp::cryptopp)

add_subdirectory(test)