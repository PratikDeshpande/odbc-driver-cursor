cmake_minimum_required(VERSION 3.10)
project(MyODBCDriver VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(ODBC REQUIRED)

# Add source files
set(SOURCES
    src/driver.cpp
    src/connection.cpp
    src/statement.cpp
    src/error.cpp
)

# Create the driver library
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${ODBC_INCLUDE_DIRS}
)

# Link against ODBC
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${ODBC_LIBRARIES}
)

# Install the driver
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
) 