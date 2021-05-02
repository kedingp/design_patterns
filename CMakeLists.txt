cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# The project name
project(hello_cmake)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(thirdparty/catch)
add_subdirectory(thirdparty/googletest)
add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(test)
