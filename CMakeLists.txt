cmake_minimum_required(VERSION 3.28)

project(bagel)

add_executable(bagel)

target_sources(bagel
    PRIVATE
        src/main.cpp
)