cmake_minimum_required(VERSION 3.28)

project(Point_Refs)

set(CMAKE_CXX_STANDARD 23)

set (
    SOURCE
    "src/main.cpp"
    "src/ptrClass.cpp"
)

add_executable(Point_Refs ${SOURCE})