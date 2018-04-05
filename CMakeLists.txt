cmake_minimum_required(VERSION 3.5)
project(calculator)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

include_directories(
    Exceptions
    Rpn
    ShuntingYard
    Tokens
    TokensParser
    TokensStream
)

file(
    GLOB SOURCES 
    "Exceptions/*.cpp"
    "Rpn/*.cpp"
    "ShuntingYard/*.cpp"
    "Tokens/*.cpp"
    "TokensParser/*.cpp"
    "TokensStream/*.cpp"
    main.cpp
)

add_executable(calculator ${SOURCES})