cmake_minimum_required(VERSION 3.24)
project(2_PROGR_DeepMiner)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(2_PROGR_DeepMiner
        globals.h
        init.cpp
        init.h miner.cpp miner.h display.cpp display.h main.cpp manager.cpp manager.h computer.cpp computer.h)
