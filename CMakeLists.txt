cmake_minimum_required(VERSION 3.28)
project(liblagrange)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

file(GLOB_RECURSE LIBRARY_SOURCE src/*.cppm)
add_library(${PROJECT_NAME} STATIC ${LIBRARY_SOURCE})
target_sources(${PROJECT_NAME}
        PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES
        FILES ${LIBRARY_SOURCE}
)

find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} Boost::boost Boost::system)

find_package(cryptopp CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} cryptopp::cryptopp)

file(GLOB_RECURSE TEST_SOURCE test/*.cpp)
add_executable(unit_test ${TEST_SOURCE})
target_link_libraries(unit_test ${PROJECT_NAME})

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
target_link_libraries(unit_test Boost::unit_test_framework)
enable_testing()