
add_subdirectory(test)

add_library(bpmfcore STATIC
        source/Application.cpp
        source/Parser.cpp
        source/Utils.cpp
        )

add_library(bpmf::core ALIAS bpmfcore)

target_include_directories(bpmfcore
        PUBLIC include
        PRIVATE include/bpmfcore)

target_compile_features(bpmfcore PRIVATE cxx_std_17)
