cmake_minimum_required(VERSION 3.23)

add_executable(${MOD_NAME}_UNIT_TESTS
	src/nudny/util/callback_queue_test.cpp
	src/nudny/util/conversions_test.cpp
	src/nudny/util/quasi_singleton_test.cpp
)

target_include_directories(${MOD_NAME}_UNIT_TESTS
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
		../include	
)

target_link_libraries(
	${MOD_NAME}_UNIT_TESTS
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${MOD_NAME}_UNIT_TESTS)
