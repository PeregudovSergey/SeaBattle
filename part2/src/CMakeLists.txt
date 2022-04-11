cmake_minimum_required(VERSION 3.0)

project(add_lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_library(ship SHARED ship.cpp)

add_library(field SHARED field.cpp)
target_link_libraries(field PUBLIC ship)

add_library(builder SHARED buildField.cpp)
target_link_libraries(builder PUBLIC ship field)

add_library(client SHARED client.cpp)
target_link_libraries(client PUBLIC builder ship field)

add_library(bot SHARED bot.cpp)
target_link_libraries(bot PUBLIC builder ship field)
