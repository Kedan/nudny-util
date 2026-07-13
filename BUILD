
cc_library(
	name = "nudny-util",
	srcs = [
		"src/nudny/util/util.cpp",
	],
	hdrs = [
		"include/nudny/util.hpp",
		"include/nudny/util/callback_queue.hpp",
		"include/nudny/util/conversions.hpp",
		"include/nudny/util/quasi_singleton.hpp",
	],
	includes = [
		"include",
	],
	visibility = [
		"//visibility:public",
	],
	deps = [ 
		"@nlohmann_json//:json",
	],
)

cc_test(
	name = "nudny-util-test",
	includes = ["test/include"],
	srcs = glob([
		"test/include/nudny/util/callback_queue_test.hpp",
		"test/include/nudny/util/conversions_test.hpp",
		"test/include/nudny/util/quasi_singleton_test.hpp",
		"test/src/nudny/util/callback_queue_test.cpp",
		"test/src/nudny/util/conversions_test.cpp",
		"test/src/nudny/util/quasi_singleton_test.cpp",
	]),
	copts = [
		"-Wall",
		"-Wextra",
		"-Wpedantic",
	],
	deps = [
		":nudny-util",
		"@googletest//:gtest_main",
		"@nlohmann_json//:json",
	],
)

cc_binary(
	name = "app",
	srcs = [ "src/main.cpp"	],
	deps = [ 
		":nudny-util",
		"@nlohmann_json//:json"
	],
)
