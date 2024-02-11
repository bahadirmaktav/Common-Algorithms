# Set minimum CMAKE standart 
cmake_minimum_required(VERSION 3.11)

# Set CPP and C standarts
set(CMAKE_CXX_STANDARD 11)

# Set cmake directories for dependencies
set(spdlog_DIR ${CMAKE_SOURCE_DIR}/deps/spdlog/cmake)

# Set project settings
project(common-algorithms VERSION 0.1.0 LANGUAGES CXX)

# Load dependencies
if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

# Create test executable
add_executable(common-algorithms main.cpp)

# Integrate dependencies for test executable
target_link_libraries(common-algorithms PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)