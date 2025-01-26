# Minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(IPC_PARSER)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
set(SOURCE_FILES
    parser.cpp 
    tinyxml2.cpp 
    TreeNode.cpp 
    XmlTreeBuilder.cpp
)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Add compile options (if needed)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)

# Optional: Include directories if needed
# target_include_directories(${PROJECT_NAME} PRIVATE include)
