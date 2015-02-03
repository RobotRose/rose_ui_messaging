cmake_minimum_required(VERSION 2.8.3)
project(operator_messaging)

find_package(catkin REQUIRED
    COMPONENTS
        ui_messaging_base
        rose_common
)

set(CMAKE_CXX_FLAGS "-std=c++0x -fPIC -g")

catkin_package(
    INCLUDE_DIRS 
        include
    LIBRARIES 
        operator_messaging
)

include_directories(
    ${catkin_INCLUDE_DIRS}
    include 
)

add_library(operator_messaging 
    SHARED
    src/operator_messaging.cpp
)

target_link_libraries(operator_messaging ${catkin_LIBRARIES})
add_dependencies(operator_messaging ${PROJECT_NAME}_generate_messages_cpp)

install(DIRECTORY include/${PROJECT_NAME}/
    DESTINATION include/${CATKIN_PACKAGE_INCLUDE_DESTINATION}
    PATTERN ".svn" EXCLUDE
)