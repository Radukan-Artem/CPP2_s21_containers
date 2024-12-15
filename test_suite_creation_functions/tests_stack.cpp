#include "../unit_tests.h"

template <typename T>
void comparison_stack(s21::stack<T> s21_stack, std::stack<T> std_stack) {
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  while (s21_stack.size() != 0) {
    EXPECT_EQ(s21_stack.top(), std_stack.top());
    s21_stack.pop();
    std_stack.pop();
  }
}

s21::stack<int> create_s21_stack_1() {
  s21::stack<int> s21_stack{1, 2, 4, 5};
  return s21_stack;
}

std::stack<int> create_std_stack_1() {
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(4);
  std_stack.push(5);
  return std_stack;
}

s21::stack<char> create_s21_stack_2() {
  s21::stack<char> s21_stack{'1', '2', '4', '5'};
  return s21_stack;
}

std::stack<char> create_std_stack_2() {
  std::stack<char> std_stack;
  std_stack.push('1');
  std_stack.push('2');
  std_stack.push('4');
  std_stack.push('5');
  return std_stack;
}

TEST(TestStackCreate, Test_create_0) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  comparison_stack(s21_stack, std_stack);
}

TEST(TestStackCreate, Test_create_1) {
  s21::stack<char> s21_stack;
  std::stack<char> std_stack;
  comparison_stack(s21_stack, std_stack);
}

TEST(TestStackCreate, Test_create_2) {
  s21::stack<int> s21_stack = create_s21_stack_1();
  std::stack<int> std_stack = create_std_stack_1();
  comparison_stack(s21_stack, std_stack);
}

TEST(TestStackCreate, Test_create_3) {
  s21::stack<char> s21_stack = create_s21_stack_2();
  std::stack<char> std_stack = create_std_stack_2();
  comparison_stack(s21_stack, std_stack);
}

TEST(TestStackCreate, Test_create_4) {
  s21::stack<int> s21_stack = create_s21_stack_1();
  std::stack<int> std_stack = create_std_stack_1();
  s21::stack<int> s21_copy_stack(s21_stack);
  std::stack<int> std_copy_stack(std_stack);
  comparison_stack(s21_stack, std_stack);
  comparison_stack(s21_copy_stack, std_copy_stack);
}

TEST(TestStackCreate, Test_create_5) {
  s21::stack<char> s21_stack = create_s21_stack_2();
  std::stack<char> std_stack = create_std_stack_2();
  s21::stack<char> s21_copy_stack(s21_stack);
  std::stack<char> std_copy_stack(std_stack);
  comparison_stack(s21_stack, std_stack);
  comparison_stack(s21_copy_stack, std_copy_stack);
}

TEST(TestStackCreate, Test_create_6) {
  s21::stack<int> s21_stack = create_s21_stack_1();
  std::stack<int> std_stack = create_std_stack_1();
  s21::stack<int> s21_copy_stack = s21_stack;
  std::stack<int> std_copy_stack = std_stack;
  comparison_stack(s21_stack, std_stack);
  comparison_stack(s21_copy_stack, std_copy_stack);
}

TEST(TestStackCreate, Test_create_7) {
  s21::stack<char> s21_stack = create_s21_stack_2();
  std::stack<char> std_stack = create_std_stack_2();
  s21::stack<char> s21_copy_stack(s21_stack);
  std::stack<char> std_copy_stack(std_stack);
  comparison_stack(s21_stack, std_stack);
  comparison_stack(s21_copy_stack, std_copy_stack);
}

// _____________________________________________________________________

TEST(TestStackElement, Test_element_2) {
  s21::stack<int> s21_stack = create_s21_stack_1();
  std::stack<int> std_stack = create_std_stack_1();
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(TestStackElement, Test_element_3) {
  s21::stack<char> s21_stack = create_s21_stack_2();
  std::stack<char> std_stack = create_std_stack_2();
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

// // _____________________________________________________________________

TEST(TestStackCapacity, Test_capacity_0) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(TestStackCapacity, Test_capacity_1) {
  s21::stack<char> s21_stack;
  std::stack<char> std_stack;
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(TestStackCapacity, Test_capacity_2) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(TestStackCapacity, Test_capacity_3) {
  s21::stack<char> s21_stack;
  std::stack<char> std_stack;
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(TestStackCapacity, Test_capacity_4) {
  s21::stack<int> s21_stack = create_s21_stack_1();
  std::stack<int> std_stack = create_std_stack_1();
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(TestStackCapacity, Test_capacity_5) {
  s21::stack<char> s21_stack = create_s21_stack_2();
  std::stack<char> std_stack = create_std_stack_2();
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(TestStackCapacity, Test_capacity_6) {
  s21::stack<int> s21_stack = create_s21_stack_1();
  std::stack<int> std_stack = create_std_stack_1();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(TestStackCapacity, Test_capacity_7) {
  s21::stack<char> s21_stack = create_s21_stack_2();
  std::stack<char> std_stack = create_std_stack_2();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

// _____________________________________________________________________

TEST(TestStackModifiers, Test_push_0) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  s21_stack.push(15);
  std_stack.push(15);
  comparison_stack(s21_stack, std_stack);
}

TEST(TestStackModifiers, Test_push_1) {
  s21::stack<int> s21_stack = create_s21_stack_1();
  std::stack<int> std_stack = create_std_stack_1();
  s21_stack.push(15);
  std_stack.push(15);
  comparison_stack(s21_stack, std_stack);
}

TEST(TestStackModifiers, Test_push_2) {
  s21::stack<int> s21_stack = create_s21_stack_1();
  std::stack<int> std_stack = create_std_stack_1();
  s21_stack.push(15);
  std_stack.push(15);
  s21_stack.push(15);
  std_stack.push(15);

  comparison_stack(s21_stack, std_stack);
}

// _____________________________________________________________________

TEST(TestStackModifiers, Test_pop_1) {
  s21::stack<int> s21_stack = create_s21_stack_1();
  std::stack<int> std_stack = create_std_stack_1();
  s21_stack.pop();
  std_stack.pop();
  comparison_stack(s21_stack, std_stack);
}

TEST(TestStackModifiers, Test_pop_2) {
  s21::stack<int> s21_stack = create_s21_stack_1();
  std::stack<int> std_stack = create_std_stack_1();
  s21_stack.pop();
  std_stack.pop();
  s21_stack.pop();
  std_stack.pop();

  comparison_stack(s21_stack, std_stack);
}

// _____________________________________________________________________

TEST(TestStackModifiers, Test_swap_0) {
  s21::stack<int> s21_stack;
  s21::stack<int> s21_stack1;
  std::stack<int> std_stack;
  std::stack<int> std_stack1;
  s21_stack.swap(s21_stack1);
  std_stack.swap(std_stack1);
  comparison_stack(s21_stack, std_stack);
  comparison_stack(s21_stack1, std_stack1);
}

TEST(TestStackModifiers, Test_swap_1) {
  s21::stack<int> s21_stack = create_s21_stack_1();
  s21::stack<int> s21_stack1{8, 13};
  std::stack<int> std_stack = create_std_stack_1();
  std::stack<int> std_stack1;
  std_stack1.push(8);
  std_stack1.push(13);
  s21_stack.swap(s21_stack1);
  std_stack.swap(std_stack1);
  comparison_stack(s21_stack, std_stack);
  comparison_stack(s21_stack1, std_stack1);
}

TEST(TestStackModifiers, Test_swap_2) {
  s21::stack<int> s21_stack = create_s21_stack_1();
  s21::stack<int> s21_stack1{9, 18, 3, 5};
  std::stack<int> std_stack = create_std_stack_1();
  std::stack<int> std_stack1;
  std_stack1.push(9);
  std_stack1.push(18);
  std_stack1.push(3);
  std_stack1.push(5);
  s21_stack.swap(s21_stack1);
  std_stack.swap(std_stack1);
  comparison_stack(s21_stack, std_stack);
  comparison_stack(s21_stack1, std_stack1);
}

// _____________________________________________________________________

TEST(TestStackModifiers, Test_insert_many_front_0) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  s21_stack.insert_many_front(15);
  std_stack.push(15);
  comparison_stack(s21_stack, std_stack);
}

TEST(TestStackModifiers, Test_insert_many_front_1) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack = create_std_stack_1();
  s21_stack.insert_many_front(2, 4, 5);
  s21_stack.insert_many_front(1);
  comparison_stack(s21_stack, std_stack);
}

TEST(TestStackModifiers, Test_insert_many_front_2) {
  s21::stack<int> s21_stack{4, 5};
  std::stack<int> std_stack = create_std_stack_1();
  ;
  s21_stack.insert_many_front(1, 2);

  comparison_stack(s21_stack, std_stack);
}