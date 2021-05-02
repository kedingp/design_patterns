project(Hello_lib)

# All sources that also need to be tested in unit tests go into a static library
add_library(hello_lib STATIC hello.cpp state.cpp)
target_include_directories(hello_lib PUBLIC ../include)
target_compile_features(hello_lib PUBLIC cxx_std_17)