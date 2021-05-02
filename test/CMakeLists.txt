project(hello_tests)

# The test program
add_executable(tests testmain.cpp)
target_link_libraries(tests PRIVATE hello_lib catch)
target_compile_definitions(tests PRIVATE CATCH_CONFIG_CONSOLE_WIDTH=60)

add_executable(template_gtest template_gtest.cpp)
target_link_libraries(template_gtest PRIVATE hello_lib GTest::gtest_main)

add_executable(test_state test_state.cpp)
target_link_libraries(test_state PRIVATE hello_lib GTest::gtest_main)