cmake_minimum_required(VERSION 3.15)

project(bpmf)
find_package(Boost COMPONENTS program_options REQUIRED)


add_subdirectory(dependencies)
add_subdirectory(core)

add_executable(bpmf
        source/main.cpp
        source/Analyzer.cpp
        source/Factory.cpp
        source/Track.cpp)

target_include_directories(bpmf PRIVATE include)

target_link_libraries(bpmf PRIVATE
        bpmf::core
        minibpm::minibpm
        dr_libs::dr_libs)

target_compile_features(bpmf PRIVATE cxx_std_17)

