#include "tasks.h"

#include <gtest.h>

TEST(Task, can_create_task)
{
	ASSERT_NO_THROW(Task t);
}

TEST(Task, can_set_positive_interval_for_count_of_processors)
{
	Task t;
	ASSERT_NO_THROW(t.setProcessors(10));
}

TEST(Task, cant_set_negative_interval_for_count_of_processors)
{
	Task t;
	ASSERT_ANY_THROW(t.setProcessors(-5));
}

TEST(Task, cant_set_zero_interval_for_count_of_processors)
{
	Task t;
	ASSERT_ANY_THROW(t.setProcessors(0));
}

TEST(Task, count_processors_in_allowable_interval)
{
	Task t;
	t.setProcessors(10);
	bool temp = t.countProcessors() < 11;
	EXPECT_EQ(temp, true);
	temp = t.countProcessors() > 0;
	EXPECT_EQ(temp, true);
}

TEST(Task, operation_compare_is_correct)
{
	Task t1;
	Task t2;
	while (!t2.isPerformed())
		t2.performeTact();
	bool temp = t2 < t1;
	EXPECT_EQ(temp, true);
}

TEST(listTask, can_add_new_task_in_list)
{
	listTask l;
	Task temp;
	ASSERT_NO_THROW(l.AddNewTask(temp));
}

TEST(listTask, can_create_list)
{
	ASSERT_NO_THROW(listTask l);
}

TEST(listTask, add_new_task_increse_count_tasks)
{
	listTask l;
	Task temp;
	int size = l.countTasks();
	l.AddNewTask(temp);
	EXPECT_EQ(size + 1, l.countTasks());
}

TEST(listTask, delete_performed_tasks_is_correct)
{
	listTask l;
	for (int i = 0; i < 20; i++)
	{
		Task temp;
		l.AddNewTask(temp);
	}
	for (int i = 0; i < 20; i++)
		l.performe();
	l.DeletePerformedTask();
	EXPECT_EQ(l.countTasks(),0);
}