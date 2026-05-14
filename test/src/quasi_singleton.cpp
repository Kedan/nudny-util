#include <quasi_singleton_test.hpp>

TEST_F(NudnyUtil_QuasiSingleton, getVal) {
	float f = 6.29f;
	EXPECT_EQ(QSinTest::getInstance().getVal(), f -1);	
}

