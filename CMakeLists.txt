# Set minimum CMake standart 
cmake_minimum_required(VERSION 3.14)

# Set project settings
project(common-algorithms VERSION 0.1.0 LANGUAGES CXX)

# Set CPP and C standarts
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# TODO(MBM): Google Test integration, uncomment and refactor later.
# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)

# Set cmake directories for dependencies
set(spdlog_DIR ${CMAKE_SOURCE_DIR}/deps/spdlog/cmake)

# Load dependencies
if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/Sorting)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/*.cpp ${CMAKE_SOURCE_DIR}/Sorting/*.hpp)

# Create test executable
add_executable(common-algorithms ${SOURCES})

# Integrate dependencies for test executable
target_link_libraries(common-algorithms PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)

# TODO(MBM): Google Test integration, uncomment and refactor later.
# enable_testing()

# add_executable(hello_test hello_test.cc)
# target_link_libraries(hello_test GTest::gtest_main)

# include(GoogleTest)
# gtest_discover_tests(hello_test)