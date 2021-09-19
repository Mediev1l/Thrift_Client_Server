include(FindPkgConfig)

find_package(PkgConfig REQUIRED)

pkg_check_modules(ThriftLib REQUIRED thrift)

add_library(GeneratedInterface STATIC
    include/Messenger.h
    Messenger.cpp
)

target_include_directories(GeneratedInterface PUBLIC ${ThriftLib_INCLUDE_DIRS} include)
target_link_libraries(GeneratedInterface PUBLIC ${ThriftLib_LIBRARIES})
