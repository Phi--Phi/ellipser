cmake_minimum_required(VERSION 3.10)
project(Ellipser VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EllipserSource
source/private/main.cpp
source/private/Ellipse.cpp
)

add_executable(${PROJECT_NAME} ${EllipserSource})
target_include_directories(${PROJECT_NAME} PRIVATE source/public)
add_compile_options(-Werror -Wall -Wextra)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
