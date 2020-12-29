#include "queue.h"

#include <gtest.h>

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> q(5));
}

TEST(TQueue, throws_when_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(-5));
}

TEST(TQueue, cant_create_too_large_queue)
{
	ASSERT_ANY_THROW(TQueue<int> q(MaxQueueSize + 1));
}

TEST(TQueue, cant_push_if_queue_is_full)
{
	TQueue<int> temp(5);
	for (int i = 0; i < 5; i++)
		temp.push(i);
	ASSERT_ANY_THROW(temp.push(5));
}

TEST(TQueue, can_push_if_other_end_is_free)
{
	TQueue<int> temp(5);
	for (int i = 0; i < 5; i++)
		temp.push(i);
	temp.pop();
	ASSERT_NO_THROW(temp.push(5));
}

TEST(TQueue, cant_pop_if_queue_empty)
{
	TQueue<int> temp(5);
	ASSERT_ANY_THROW(temp.pop());
}

TEST(TQueue, can_pop_and_push_element)
{
	TQueue<int> temp(5);
	temp.push(5);
	temp.push(4);
	EXPECT_EQ(temp.pop(), 5);
	EXPECT_EQ(temp.pop(), 4);
}

TEST(TQueue, count_queue_is_correct)
{
	TQueue<int> temp(5);
	temp.push(5);
	temp.push(4);
	temp.push(3);
	EXPECT_EQ(temp.countQueue(), 3);
	temp.pop();
	EXPECT_EQ(temp.countQueue(), 2);
}

TEST(TQueue, get_bottom_is_correct)
{
	TQueue<int> temp(5);
	temp.push(5);
	temp.push(4);
	EXPECT_EQ(temp.getBottom(), 5);
	EXPECT_EQ(temp.countQueue(), 2);
}

TEST(TQueue, function_full_is_correct)
{
	TQueue<int> temp(2);
	EXPECT_EQ(temp.empty(), true);
	temp.push(1);
	EXPECT_EQ(temp.empty(), false);
}

TEST(TQueue, function_empty_is_correct)
{
	TQueue<int> temp(2);
	temp.push(1);
	temp.push(0);
	EXPECT_EQ(temp.full(), true);
	temp.pop();
	EXPECT_EQ(temp.full(), false);
}