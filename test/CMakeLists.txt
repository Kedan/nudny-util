cmake_minimum_required(VERSION 3.23)

add_executable(${MOD_NAME}_UT
	src/callback_queue.cpp
	src/conversions.cpp
)

target_include_directories(${MOD_NAME}_UT
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/${INC_DIR}
		${ROOT_DIR}/${TEST_DIR}/include/
)

target_link_libraries(
	${MOD_NAME}_UT
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${MOD_NAME}_UT)
