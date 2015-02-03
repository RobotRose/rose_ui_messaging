cmake_minimum_required(VERSION 2.8.3)
project(ui_messaging_base)

find_package(catkin REQUIRED
)

set(CMAKE_CXX_FLAGS "-std=c++0x -fPIC -g")

catkin_package(
    INCLUDE_DIRS 
      include
    LIBRARIES 
      ui_messaging_base
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  include 
)

add_library(ui_messaging_base 
  SHARED
  src/ui_messaging_base.cpp
)

target_link_libraries(ui_messaging_base ${catkin_LIBRARIES})
add_dependencies(ui_messaging_base ${PROJECT_NAME}_generate_messages_cpp)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION include/${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  PATTERN ".svn" EXCLUDE
)