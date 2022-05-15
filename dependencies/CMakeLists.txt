add_subdirectory(googletest)

add_library(minibpm STATIC
        minibpm/src/MiniBpm.cpp)

add_library(minibpm::minibpm ALIAS minibpm)

target_include_directories(minibpm PUBLIC minibpm/src)

add_library(dr_libs INTERFACE)

add_library(dr_libs::dr_libs ALIAS dr_libs)

target_include_directories(dr_libs INTERFACE dr_libs)

target_compile_definitions(dr_libs INTERFACE DR_MP3_IMPLEMENTATION)
