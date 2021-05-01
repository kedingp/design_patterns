project(Hello_prog)

# The main program
add_executable(prog main.cpp)
target_link_libraries(prog PRIVATE hello_lib)

