cmake_minimum_required(VERSION 3.5)
project(calculator)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

include_directories(
    Exceptions
    GrammarParser
    Parser
    Tokens
)

file(
    GLOB SOURCES 
    "Exceptions/*.cpp"
    "GrammarParser/*.cpp"
    "Parser/*.cpp"
    "Tokens/*.cpp"
    main.cpp
)

add_executable(calculator ${SOURCES})
