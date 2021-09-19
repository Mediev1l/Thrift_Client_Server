add_library(MessangerLib STATIC
    ClientImpl.hpp
    ClientImpl.cpp
    ServerImpl.hpp
    ServerImpl.cpp
)

target_include_directories(MessangerLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )
target_link_libraries(MessangerLib PUBLIC GeneratedInterface)

