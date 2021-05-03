project(Hello_prog)

# The main program
add_executable(prog main.cpp)
target_link_libraries(prog PRIVATE hello_lib)

add_executable(command_app command_app.cpp)
target_link_libraries(command_app PRIVATE hello_lib)

