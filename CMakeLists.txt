cmake_minimum_required(VERSION 3.16)
project(mathematical_portfolio)

# Set C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Eigen3 (optional)
find_package(Eigen3 QUIET)

# Create a simple example numerical methods library
add_library(numerical_methods INTERFACE)
target_include_directories(numerical_methods INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(Eigen3_FOUND)
    target_link_libraries(numerical_methods INTERFACE Eigen3::Eigen)
    message(STATUS "Eigen3 found and linked")
else()
    message(STATUS "Eigen3 not found - numerical examples will use basic implementations")
endif()

# Add example executable
add_executable(euler_methods examples/euler_methods_demo.cpp)
target_link_libraries(euler_methods numerical_methods)

# Add basic header directory
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/examples)

# Print build information
message(STATUS "Building Mathematical Portfolio C++ Examples")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")