cmake_minimum_required(VERSION 3.8)

project(caker VERSION 1.0)

add_executable(
	caker
	main.cpp
)

target_link_libraries(caker PRIVATE cake)
target_include_directories(caker PUBLIC "${PROJECT_SOURCE_DIR}/include")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/menu.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/cakes.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/pick.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(src/main/cake)