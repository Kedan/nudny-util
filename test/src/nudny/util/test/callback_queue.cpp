#include <nudny/util/test/callback_queue.hpp>

namespace nd::util::test {
	TEST_F(CallbackQueue_Test, execute_CallbackPointerIsEmpty_ThrowRuntimeError ) {
		cq->execute();
		EXPECT_THROW("Callback is null in execution queue!",std::runtime_error);
	}

	TEST_F(CallbackQueue_Test, execute_CallbackQueueIsEmpty_ReturnFalse) {
		cq = std::make_unique<::nd::util::callback_queue>(Foo::foo(float,float));
		EXPECT_FALSE(cq->execute());

	}
}; //nd::util::test
