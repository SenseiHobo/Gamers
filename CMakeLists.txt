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
add_executable(MainTest Cave.cpp database.cpp Intro.cpp element.cpp enemy.cpp fight.cpp game.cpp hero.cpp main.cpp menu.cpp shop.cpp spell.cpp Tool.cpp)

# Link the executable with the required Qt modules
target_link_libraries(MainTest Qt5::Core Qt5::Sql)
