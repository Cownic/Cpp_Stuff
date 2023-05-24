# Define the minimum version of cmake that it can work in
# It is backwards compatible
cmake_minimum_required(VERSION 3.26.3)

# Set the name of the project and store in PROJECT_NAME variable
project(TEST_1)

# Generates executable from the source file that we wants
add_executable(${PROJECT_NAME} main.cpp)


# Reference to the sub directory CMakeFile
add_subdirectory(Adder)

# when we include the header in our main program, there is no need for use to use the complete path
target_include_directories(${PROJECT_NAME} PUBLIC Adder)

# Add Link directories to the target
target_link_directories(${PROJECT_NAME} PRIVATE Adder/)

# Link the subdirectionary library to the main
# library here needs to be the same as the one defined in the subdirectory one
target_link_libraries(${PROJECT_NAME} adder)

