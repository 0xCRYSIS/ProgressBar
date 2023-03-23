cmake_minimum_required(VERSION 3.0.2)
project(progress_bar)

find_package(catkin REQUIRED roscpp )

catkin_package()

include_directories(
${catkin_INCLUDE_DIRS}
)

add_executable(progress_bar src/progress_bar.cpp)
target_link_libraries(progress_bar ${catkin_LIBRARIES} )