#pragma once

#include <memory>
#include <nudny/util/callback_queue.hpp>
#include <gtest/gtest.h>



class Foo {
	public:
		Foo() = default;
		Foo(float f) : m_f{f}, m_r{0.0f} {}
		~Foo() = default;

		void foo(float a, float b) {
			m_r = a * b * m_f;
		}

		float getr() { return m_r;}
	protected:
		float m_f{0.f};
		float m_r{0.f};
}; // class Foo

class CallbackQueue_Test : public ::testing::Test {
	protected:
		float a = 1.0f;
		float b = 4.0f;
	public:
		CallbackQueue_Test() = default;
		~CallbackQueue_Test() = default;
		void execute_CallbackPointerIsEmpty_ThrowRuntimeError();
		void execute_CallbackQueueIsEmpty_ReturnFalse();
		void execute_QueueCorrect_ReturnTrue();
		
}; // class CallbackQueue_Test

