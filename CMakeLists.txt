cmake_minimum_required(VERSION 3.23)



set(MOD_NAME "nudny-util")
set(MOD_DESC "Utility classes")
set(MOD_ALIAS "nudny::util")

set(TESTS_DIR "test")
set(INC_DIR "include")
set(SRC_DIR "src/util")


project(${MOD_NAME} VERSION 0.1.0 DESCRIPTION ${MOD_DESC})
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS, " -Wall -Wextra -Wpedantic")


set(SANITIZER_FLAGS, "")
add_custom_target(coverage
	COMMAND ${CMAKE_CTEST_COMMAND} -V --preset coverage
	COMMAND ${CMAKE_SOURCE_DIR}/scripts/gencov.sh ${CMAKE_BINARY_DIR}
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
	COMMENT "Running test and generating coverage raport"
)
include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()
add_library(${MOD_NAME}
	${SRC_DIR}/util.cpp
)
target_include_directories(${MOD_NAME}
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/submodule
	${CMAKE_CURRENT_SOURCE_DIR}/${INC_DIR}
)
option(RELEASE "Relese" OFF)
if(RELEASE)
	message(STATUS "==== Build release version ====")
	add_compile_options(-g -O3 -DNDEBIG)
endif()
option(ENABLE_COVERAGE "Enable coverage" OFF)
if(ENABLE_COVERAGE)
	message(STATUS "Coverage enabled")
	add_compile_options(--coverage -O0 -g)
	add_link_options(--coverage)
endif()
option(ENABLE_VALGRIND "Enable Valgrind" OFF)
option(ENABLE_SANITIZERS "Enable ASan + UBSan" OFF)
if(ENABLE_SANITIZERS)
	message("Sanitazers ENABLED")
	set(SANITAZER_FLAG
		-fsanitize=address,undefined
		-fno-omit-frame-pointer
		-g
	)
	add_compile_options(${SANITAZER_FLAGS} -D_GLIBCXX_ASSERTIONS)
	add_link_options(${SANITAZER_FLAGS})
endif()

add_subdirectory(test)
add_library(${MOD_ALIAS} ALIAS ${MOD_NAME})
