
add_executable(bpmfcoreTestHost
        source/FilePathValidatorTestCase.cpp
        source/ParseTestCase.cpp
        source/PrinterTestCase.cpp
        source/TaskTestCase.cpp
        )

target_link_libraries(
        bpmfcoreTestHost
        PRIVATE
        bpmf::core
        bpmf::bpmf_mocks
        gmock
        gmock_main)

target_compile_features(bpmfcoreTestHost PRIVATE cxx_std_17)
