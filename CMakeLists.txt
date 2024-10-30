cmake_minimum_required(VERSION 3.29)
project(assignment2_code)

set(CMAKE_CXX_STANDARD 14)

include_directories(assignment2_code)
include_directories(assignment2_code/LinkedBagDS)

add_executable(assignment2_code
    assignment2_code/LinkedBagDS/BagInterface.h
        assignment2_code/LinkedBagDS/LinkedBag.h
        assignment2_code/LinkedBagDS/Node.h
    assignment2_code/Instagram340.cpp
    assignment2_code/Instagram340.h
    assignment2_code/InstagramMain.cpp
    assignment2_code/Post.cpp
    assignment2_code/Post.h
    assignment2_code/User.cpp
    assignment2_code/User.h
        assignment2_code/Reel.cpp
        assignment2_code/Reel.h
        assignment2_code/Story.cpp
        assignment2_code/Story.h)
