cmake_minimum_required(VERSION 3.10)

project( "test_boost" )

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set( user_sources 
    "boost_nested_exception.cpp")

# find Threads
find_package(Threads REQUIRED)

# find Boost
find_package(Boost 1.71.0 REQUIRED COMPONENTS thread chrono)

add_executable( ${PROJECT_NAME} ${user_sources})

# add Boost::thread and Boost::chrono as dependencies
target_link_libraries(
        ${PROJECT_NAME}
        PUBLIC Threads::Threads Boost::boost Boost::thread Boost::chrono
)

# set the Boost thread version
target_compile_definitions(
        ${PROJECT_NAME}
        PUBLIC BOOST_THREAD_VERSION=5
)

# library requires c++11
target_compile_features(
        ${PROJECT_NAME}
        PUBLIC cxx_std_11
)


