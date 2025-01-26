cmake_minimum_required(VERSION 3.10)

# Set the project name
project(XmlParser)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Add the executable
add_executable(XmlParser 
    parser.cpp 
    tinyxml2.cpp 
    TreeNode.cpp 
    XmlTreeBuilder.cpp
)

# If you need to link any libraries, uncomment and specify them here
# target_link_libraries(XmlParser <LIBRARY_NAME>)

# Include directories for header files if needed (e.g., for tinyxml2)
# include_directories(/path/to/include)

# If using any external libraries or dependencies, you can also find and link them:
# find_package(SomeLibrary REQUIRED)
# target_link_libraries(XmlParser SomeLibrary)
