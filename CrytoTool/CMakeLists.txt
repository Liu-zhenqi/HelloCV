cmake_minimum_required(VERSION 3.10)
project(CryptoTool)

set(CMAKE_CXX_STANDARD 17)

add_executable(CryptoTool src/main.cpp src/Crypto.cpp src/FileHandler.cpp src/Menu.cpp)
