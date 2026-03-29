cmake_minimum_required(VERSION 3.28)

project(bagel)

add_executable(bagel)

target_include_directories(bagel
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_sources(bagel
    PRIVATE
        src/main.cpp
        src/scanner.cpp
)