cmake_minimum_required(VERSION 3.22)
project(convolutional C)

set(CMAKE_C_STANDARD 99)

FILE(COPY kernels images DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

add_executable(convolutional main.c)
