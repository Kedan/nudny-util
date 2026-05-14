#pragma once

#include <nudny/util/quasi_singleton.hpp>
#include <gtest/gtest.h>

class QSinTest 
	: public ::nd::util::QuasiSingleton<float>
	, public ::testing::Test {
	public:
		float getVal();
	protected:
		float value{5.29f}

}
