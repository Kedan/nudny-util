#include <callback_queue_test.hpp>

using Queue = nd::util::CallbackQueue<Foo,float,float>;

TEST_F(CallbackQueue_Test, execute_CallbackPointerIsEmpty_ThrowRuntimeError ) {
	Queue q;
	EXPECT_THROW(q.execute(a,b), std::runtime_error);
}

TEST_F(CallbackQueue_Test, execute_CallbackQueueIsEmpty_ReturnFalse) {
	Queue q(&Foo::foo);
	EXPECT_FALSE(q.execute(a,b));
}

TEST_F(CallbackQueue_Test, execute_QueueCorrect_ReturnTrue) {
	std::shared_ptr<Foo> f1 = std::make_shared<Foo>(1.f);
	std::shared_ptr<Foo> f2 = std::make_shared<Foo>(2.f);
	Queue q(&Foo::foo);

	q.push(f1);
	q.push(f2);
	
	EXPECT_EQ(f1->getr(), 0.0f);
	EXPECT_EQ(f2->getr(), 0.0f);

	bool result = q.execute(a, b);
	EXPECT_TRUE(result);

	EXPECT_EQ(f1->getr(), 4.0f);
	EXPECT_EQ(f2->getr(), 8.0f);

}
