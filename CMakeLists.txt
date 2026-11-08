cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS " -Wall -Wextra -Wpedantic")
set(SANITIZER_FLAGS "")


set(MOD_NAME "nudny-util")
set(APP_NAME "nudny-util-app")
set(MOD_DESCRIPTION "Utility module")
set(MOD_VERSION 0.0.1)
set(MOD_DIR "nudny/util")
set(MOD_ALIAS "nudny::util")

option(RELEASE "Relese" OFF)
option(ENABLE_VALGRIND "Enable Valgrind" OFF)
option(ENABLE_SANITIZERS "Enable ASan + UBSan" OFF)
option(ENABLE_COVERAGE "Enable coverage" OFF)
option(ENABLE_CLANG_TIDY "Enable clang-tidy" OFF)

project(${MOD_NAME} VERSION ${MOD_VERSION} DESCRIPTION ${MOD_DESCRIPTION} LANGUAGES CXX)

add_custom_target(${MOD_NAME}_coverage
	COMMAND ${CMAKE_CTEST_COMMAND} -V --preset coverage
	COMMAND ${CMAKE_SOURCE_DIR}/scripts/gencov.sh ${CMAKE_BINARY_DIR}
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
	COMMENT "Running tests and generating coverage raport"
)

include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_library(${MOD_NAME}
	src/${MOD_DIR}/util.cpp
)

add_executable(${APP_NAME} 
	src/${MOD_DIR}/util.cpp
	src/main.cpp
)

target_include_directories(${MOD_NAME}
	PUBLIC
	include
)

target_include_directories(${APP_NAME}
	PUBLIC
	include
)

if(ENABLE_CLANG_TIDY)
	set_property(TARGET ${MOD_NAME} PROPERTY CXX_CLANG_TIDY clang-tidy)
	set_property(TARGET App PROPERTY CXX_CLANG_TIDY clang-tidy)
endif()

if(RELEASE)
	message(STATUS "==== Build release version ====")
	add_compile_options(-g -O3 -DNDEBUG)
endif()

if(ENABLE_COVERAGE)
	message(STATUS "Coverage enabled")
	add_compile_options(--coverage -O0 -g)
	add_link_options(--coverage)
endif()

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
