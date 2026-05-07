#pragma once

#include <nudny/util/callback_queue.hpp>
#include <gtest/gtest.hpp>

namespace nd::util::test {
	
	final class Foo {
		public:
			Foo() = default;
			~Foo() = default;

			void foo(float a, float b) {
				float c = a * b;
				std::cout << std::to_string(c) << "\n";
			}
	}; // class Foo

	final class Bar() {
		public:
			Bar() = default;
			~Bar() = default;

			void boo(float a, float b) {
				float c = a * b;
				std::cout << std::to_string(c) << "\n";
			}
	}; // class bar

	final class CallbackQueue_Test : public ::testing::Test {
		std::unique_ptr<::nd::util::CallbackQueue> cq;
		public:
			CallbackQueue_Test() = default;
			~CallbackQueue_Test() = default;
	//		void execute_CallbackPointerIsEmpty_ThrowRuntimeError() {};
	//		void execute_CallbackQueueIsEmpty_ReturnFalse();
	//		void execute_QueueCorrect_ReturnTrue();
			
	 }; // class CallbackQueue_Test

}; // namespace nd::util::test
