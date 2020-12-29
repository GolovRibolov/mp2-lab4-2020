#include "cluster.h"

#include <gtest.h>

TEST(statistics, can_add_performed_tasks)
{
	statistics st;
	ASSERT_NO_THROW(st.addPerformed(5));
}

TEST(statistics, cant_add_negative_performed_tasks)
{
	statistics st;
	ASSERT_ANY_THROW(st.addPerformed(-5));
}

TEST(statistics, can_add_count_in_queue)
{
	statistics st;
	ASSERT_NO_THROW(st.inQueue(5));
}

TEST(statistics, cant_add_negative_count_in_queue)
{
	statistics st;
	ASSERT_ANY_THROW(st.inQueue(-5));
}

TEST(statistics, can_add_congestion)
{
	statistics st;
	ASSERT_NO_THROW(st.congestion(5));
}

TEST(statistics, cant_add_negative_congestion)
{
	statistics st;
	ASSERT_ANY_THROW(st.congestion(-5));
}

TEST(cluster, can_create_cluster)
{
	ASSERT_NO_THROW(cluster c(10));
}

TEST(cluster, cant_create_cluster_with_negative_count_of_processors)
{
	ASSERT_ANY_THROW(cluster c(-10));
}

TEST(cluster, can_do_possitive_tacts)
{
	cluster c(10);
	ASSERT_NO_THROW(c.doTacts(10));
}

TEST(cluster, cant_do_negative_tacts)
{
	cluster c(10);
	ASSERT_ANY_THROW(c.doTacts(-10));
}
