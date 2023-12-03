#include "../tStack/TStack.h"

#include "gtest.h"

TEST(TStack, can_create_int_stack_with_positive_size)
{
	ASSERT_NO_THROW(TStack<int> s(3));
}

TEST(TStack, can_create_double_stack_with_positive_size)
{
	ASSERT_NO_THROW(TStack<double> s(3));
}

TEST(TStack, stack_with_negative_size_throws_exception)
{
	ASSERT_ANY_THROW(TStack<int> s(-3));
}

TEST(TStack, can_create_stack_by_copy)
{
	TStack<int> s1(3);
	for (int i = 5; i < 8; i++) s1.Push(i);
	TStack<int> s2(s1);
	int flag = 0;
	for (int i = 0; i < s2.size(); i++) flag += s2.Pop() * (pow(10, i));		//sostavlyaet chyslo is togo, chto est in stack. 
																				//snachala ideut edinitsy, potom desyatki i tak dalee
	EXPECT_EQ(567, flag);
}

TEST(TStack, can_get_max_size)
{
	TStack<int> s(3);

	EXPECT_EQ(3, s.size());
}

TEST(TStack, can_get_current_index)
{
	TStack<int> s(3);
	s.Push(10);

	EXPECT_EQ(0, s.idx());
}

TEST(TStack, new_stack_is_empty)
{
	TStack<int> s(10);
	bool res;
	res = s.empty();

	EXPECT_EQ(true, s.empty());
}

TEST(TStack, operation_push_work_correctly)
{
	TStack<int> s(3);
	int flag = 0;
	int op = 0;
	s.Push(flag++);
	op = s.Pop();
	if ((s.idx() == 0) && (op == 1)) flag = 1;

	EXPECT_EQ(1, flag);
}

TEST(TStack, throws_when_stack_is_overflow)
{
	TStack<int> s(1);
	s.Push(1);

	ASSERT_ANY_THROW(s.Push(2));
}

TEST(TStack, operation_pop_work_correctly)
{
	TStack<int> s(3);
	int flag = 0;
	int op = 30;
	s.Push(op);
	flag = s.Pop();
	EXPECT_EQ(op, flag);
}

TEST(TStack, throws_when_try_to_pop_from_empty_stack)
{
	TStack<int> s(1);

	ASSERT_ANY_THROW(s.Pop());
}

TEST(TStack, operation_is_full_work_correctly)
{
	TStack<int> s(10);

	EXPECT_EQ(false, s.full());
}

TEST(TStack, operation_is_empty_work_correctly)
{
	TStack<int> s(5);
	for (int i = 0; i < 5; i++) s.Push(1);
	bool res = s.empty();

	EXPECT_EQ(false, s.empty());
}

TEST(TStack, operation_clear_work_correctly)
{
	TStack<int> s(10);
	for (int i = 0; i < 3; i++) s.Push(i);
	s.Clear(); 

	ASSERT_ANY_THROW(s.Pop());
}