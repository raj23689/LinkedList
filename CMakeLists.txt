cmake_minimum_required(VERSION 3.10)
project(LinkedList)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set Clang++ as the compiler
set(CMAKE_CXX_COMPILER "clang++")

# Add executable target with both main.cpp and other.cpp
file(GLOB SOURCES "src/*.cpp")
add_executable(linkedlist ${SOURCES})

# Include the directory where square.hpp is located
target_include_directories(linkedlist PRIVATE src/lib)

# Set compiler flags
target_compile_options(linkedlist PRIVATE
    -Wall # Enable all warnings
    -Wextra # Enable extra warnings
    -pedantic # Enforce strict adherence to the C++ standard
    -Werror # Treat warnings as errors
)
