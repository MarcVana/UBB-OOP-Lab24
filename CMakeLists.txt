cmake_minimum_required(VERSION 3.27)
project(LAB2_4 C)

set(CMAKE_C_STANDARD 17)

add_executable(LAB2_4 main.c
        car.c
        car.h
        repo.c
        repo.h
        service.c
        service.h
        tests.c
        tests.h)
