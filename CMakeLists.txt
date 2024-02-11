# Set minimum CMake standart 
cmake_minimum_required(VERSION 3.14)

# Set project settings
project(common-algorithms VERSION 0.1.0 LANGUAGES CXX)

# Set CPP and C standarts
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(GTEST_ENABLED "Enable Google Test framework" ON)
option(LOG_ENABLED "Enable spdlog library" OFF)

if(GTEST_ENABLED)
    include(FetchContent)
    FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    # Add subdirectories which contains test codes
    # TODO(MBM): Option for enable/disable each subdirectory will be added.
    add_subdirectory(${CMAKE_SOURCE_DIR}/Sorting)
    enable_testing()
endif()

if(LOG_ENABLED)
    # Set cmake directories for dependencies
    set(spdlog_DIR ${CMAKE_SOURCE_DIR}/deps/spdlog/cmake)
    # Load dependencies
    if(NOT TARGET spdlog)
        # Stand-alone build
        find_package(spdlog REQUIRED)
    endif()
endif()