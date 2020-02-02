cmake_minimum_required(VERSION 3.14)
project(csky)

set(CMAKE_CXX_STANDARD 14)

add_executable(csky g.tree/binary/c.avltree.cpp g.tree/binary/b.avltree.cpp m.graph/a.graph.cpp)