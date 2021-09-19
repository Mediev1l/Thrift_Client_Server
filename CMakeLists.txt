project(Thrift_Client_Server)

cmake_minimum_required(VERSION 3.16)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_subdirectory(gen-cpp)
add_subdirectory(Implementation)

set (MessengerLibraries GeneratedInterface MessangerLib)

add_executable(Client Client.cpp)
target_link_libraries(Client PRIVATE ${MessengerLibraries})

add_executable(Server Server.cpp)
target_link_libraries(Server PRIVATE ${MessengerLibraries})
