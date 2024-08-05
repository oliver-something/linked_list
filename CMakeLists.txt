cmake_minimum_required(VERSION 3.28)
project(second_project)

set(CMAKE_CXX_STANDARD 23)

add_executable(second_project main.cpp
        linked_list.hpp
        linked_list.tpp
)
