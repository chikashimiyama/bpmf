
add_library(bpmf_mocks INTERFACE)

add_library(bpmf::bpmf_mocks ALIAS bpmf_mocks)

target_link_libraries(bpmf_mocks INTERFACE gmock)

target_include_directories(bpmf_mocks INTERFACE include)

