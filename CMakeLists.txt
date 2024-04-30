cmake_minimum_required(VERSION 3.10)
project(LinkedList)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add executable target with source files
file(GLOB SOURCES "src/*.cpp")
add_executable(linkedlist ${SOURCES})

# Include the directory where headerfiles are located
target_include_directories(linkedlist PRIVATE src/lib)

# Set compiler flags
if(MSVC)
  # MSVC compiler options
  target_compile_options(
    linkedlist PRIVATE /W4 # Warning level 4 (highest)
                       /WX # Treat warnings as errors
  )
else()
  # GCC/Clang compiler options
  target_compile_options(
    linkedlist
    PRIVATE -Wall # Enable all warnings
            -Wextra # Enable extra warnings
            -pedantic # Enforce strict adherence to the C++ standard
            -Werror # Treat warnings as errors
  )
endif()
