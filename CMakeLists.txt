cmake_minimum_required(VERSION 3.23)
project(SaberInteractive)

set(CMAKE_CXX_STANDARD 23)

add_executable(SaberInteractive
        src/main.cpp
        src/types/ListNode.cpp
        src/types/ListNode.h
        src/types/ListRand.cpp
        src/types/ListRand.h)
