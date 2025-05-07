cmake_minimum_required(VERSION 3.27)

project(retinify-viewer LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release)

include(FetchContent)
FetchContent_Declare(rerun_sdk URL https://github.com/rerun-io/rerun/releases/download/0.22.1/rerun_cpp_sdk.zip)
FetchContent_MakeAvailable(rerun_sdk)

find_package(OpenCV REQUIRED)

add_library(${PROJECT_NAME}
    ./src/viewer.cpp
    ./include/retinify/viewer.hpp
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        rerun_sdk ${OpenCV_LIBS}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_subdirectory(sample)