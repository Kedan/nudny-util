#include <conversions_test.hpp>

TEST(NudnyUtil, StrToOptNumTest) {
	std::optional<float> r(12.35f);
	std::string number = "12.35";
	std::string not_number = "lorem upsum";

	std::optional<float> n = nd::util::strtoptnum<float>(number);
	std::optional<float> nn = nd::util::strtoptnum<float>(not_number);

	EXPECT_EQ(n, r);
	EXPECT_NE(nn, r);
	EXPECT_EQ(nn, std::nullopt);
}

TEST(NudnyUtil, StrToNumTest_Valid) {
	float r{12.35f};
	std::string number = "12.35";
	std::string not_number = "lorem upsum";
	float n = nd::util::strtonum<float>(number);
	EXPECT_EQ(n, r);
	EXPECT_THROW(nd::util::strtonum<float>(not_number), std::invalid_argument);
}

