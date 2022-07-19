cmake_minimum_required(VERSION 3.22)
project(SimpleDijkstra)

set(CMAKE_CXX_STANDARD 14)

add_executable(SimpleDijkstra main.cpp Graph/Graph.cpp Graph/Graph.h)
