cmake_minimum_required(VERSION 3.10)

project(GraphSh)

set(CMAKE_CXX_STANDARD 17)

add_executable(GraphSh 
src/main.cpp
src/Color.cpp
src/Canvas.cpp
)

target_include_directories(GraphSh PRIVATE include)

# cmake -S . -B build -D CMAKE_CXX_COMPILER=g++ (or any other compiler you want to use)
# cmake --build build
# To run the executable, navigate to the build directory and execute;