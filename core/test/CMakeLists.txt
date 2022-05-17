
add_executable(bpmfTestHost
        source/TaskTestCase.cpp
        source/MainTestCase.cpp
        )

target_link_libraries(
        bpmfTestHost
        PRIVATE
        bpmf::core
        gmock
        gmock_main)

target_compile_features(bpmfTestHost PRIVATE cxx_std_17)
