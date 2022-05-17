add_subdirectory(test)

add_library(bpmfcore STATIC
        source/Task.cpp
        source/Main.cpp
        source/FilePathValidator.cpp
        source/VerbosePrinter.cpp
        )

add_library(bpmf::core ALIAS bpmfcore)

target_include_directories(bpmfcore
        PUBLIC include
        PRIVATE include/bpmfcore)

target_compile_features(bpmfcore PRIVATE cxx_std_17)

target_link_libraries(bpmfcore
        PRIVATE Boost::program_options
        -pthread)