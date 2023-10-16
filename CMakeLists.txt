cmake_minimum_required(VERSION 3.26)
project(SinglyLinkedListString)

set(CMAKE_CXX_STANDARD 17)

add_executable(SinglyLinkedListString main.cpp
        SLLString.cpp
        Node.h)
