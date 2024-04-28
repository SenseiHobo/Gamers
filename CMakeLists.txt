# CMake minimum version and project information
cmake_minimum_required(VERSION 3.1...3.28)
project(ModernCMakeExample VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find required packages
find_package(Qt5 COMPONENTS Core Sql REQUIRED)

# Define the executable and list all the source files
add_executable(MainTest main.cpp menu.cpp fight.cpp game.cpp enemy.cpp Cave.cpp database.cpp hero.cpp Tool.cpp)

# Link the executable with the required Qt modules
target_link_libraries(MainTest Qt5::Core Qt5::Sql)
