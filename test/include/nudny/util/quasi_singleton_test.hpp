#pragma once

#include <nudny/util/quasi_singleton.hpp>
#include <gtest/gtest.h>

class Bar {
	public:
		float getVal();
	protected:
		float val{5.29f};
};

class QuasiSingleton_Test 
	: public ::nd::util::QuasiSingleton<float>
	, public ::testing::Test {
	public:
		float getVal();
	protected:
		float value{5.29f};

};
