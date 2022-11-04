cmake_minimum_required(VERSION 3.10)
project(SimpleDijkstra)

set(CMAKE_CXX_STANDARD 14)

add_executable(SimpleDijkstra main.cpp Graph/Graph.cpp Graph/Graph.h Graph/Edge.cpp Graph/Edge.h Graph/Node.cpp Graph/Node.h)
