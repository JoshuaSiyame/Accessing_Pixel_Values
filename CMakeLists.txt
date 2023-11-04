cmake_minimum_required(VERSION 3.28.0)
project(accessing_pixel_values VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()


find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)

add_executable(accessing_pixel_values main.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
