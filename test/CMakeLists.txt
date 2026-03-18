cmake_minimum_required(VERSION 3.23)

add_executable(${MOD_NAME}_UT
	src/nudny/core/arg/Parser_test.cpp
)

target_link_libraries(
	${MOD_NAME}_UT
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${MOD_NAME}_UT)
