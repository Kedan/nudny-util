#include <nudny/util/quasi_singleton_test.hpp>

float Bar::getVal() {
	return val;
}

TEST_F(QuasiSingleton_Test, getVal) {
	float f = 6.29f;
	EXPECT_EQ(QuasiSingleton<Bar>::getInstance().getVal(), f-1);	
}

