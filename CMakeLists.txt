cmake_minimum_required(VERSION 3.3)

SET(CMAKE_BUILD_TYPE Debug)

project (WordChecker)

file(GLOB sources ./src/*.cpp ./src/*.h ./main.cpp)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set(server_STAT_SRCS
  ${sources}
)

message(status " This is the server_share srcs:" ${server_STAT_SRCS})

add_executable(${PROJECT_NAME} ${server_STAT_SRCS})
