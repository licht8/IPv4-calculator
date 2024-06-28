cmake_minimum_required(VERSION 3.10)

project(IPv4-Calculator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/headers)

set(HEADER_FILES
    headers/IPAddress.h
    headers/SubnetCalculator.h
)

set(SOURCE_FILES
    IPv4_Calculator.cpp
    IPAddress.cpp
    SubnetCalculator.cpp
)

add_executable(IPv4-Calculator ${SOURCE_FILES} ${HEADER_FILES})

# target_link_libraries(... ...)