#include "../unit_tests.h"

template <typename T>
void comparison_queue(s21::queue<T> s21_queue, std::queue<T> std_queue) {
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  while (s21_queue.size() != 0) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

s21::queue<int> create_s21_queue_1() {
  s21::queue<int> s21_queue{1, 2, 4, 5};
  return s21_queue;
}

std::queue<int> create_std_queue_1() {
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(4);
  std_queue.push(5);
  return std_queue;
}

s21::queue<char> create_s21_queue_2() {
  s21::queue<char> s21_queue{'1', '2', '4', '5'};
  return s21_queue;
}

std::queue<char> create_std_queue_2() {
  std::queue<char> std_queue;
  std_queue.push('1');
  std_queue.push('2');
  std_queue.push('4');
  std_queue.push('5');
  return std_queue;
}

TEST(TestQueueCreate, Test_create_0) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  comparison_queue(s21_queue, std_queue);
}

TEST(TestQueueCreate, Test_create_1) {
  s21::queue<char> s21_queue;
  std::queue<char> std_queue;
  comparison_queue(s21_queue, std_queue);
}

TEST(TestQueueCreate, Test_create_2) {
  s21::queue<int> s21_queue = create_s21_queue_1();
  std::queue<int> std_queue = create_std_queue_1();
  comparison_queue(s21_queue, std_queue);
}

TEST(TestQueueCreate, Test_create_3) {
  s21::queue<char> s21_queue = create_s21_queue_2();
  std::queue<char> std_queue = create_std_queue_2();
  comparison_queue(s21_queue, std_queue);
}

TEST(TestQueueCreate, Test_create_4) {
  s21::queue<int> s21_queue = create_s21_queue_1();
  std::queue<int> std_queue = create_std_queue_1();
  s21::queue<int> s21_copy_queue(s21_queue);
  std::queue<int> std_copy_queue(std_queue);
  comparison_queue(s21_queue, std_queue);
  comparison_queue(s21_copy_queue, std_copy_queue);
}

TEST(TestQueueCreate, Test_create_5) {
  s21::queue<char> s21_queue = create_s21_queue_2();
  std::queue<char> std_queue = create_std_queue_2();
  s21::queue<char> s21_copy_queue(s21_queue);
  std::queue<char> std_copy_queue(std_queue);
  comparison_queue(s21_queue, std_queue);
  comparison_queue(s21_copy_queue, std_copy_queue);
}

TEST(TestQueueCreate, Test_create_6) {
  s21::queue<int> s21_queue = create_s21_queue_1();
  std::queue<int> std_queue = create_std_queue_1();
  s21::queue<int> s21_copy_queue = s21_queue;
  std::queue<int> std_copy_queue = std_queue;
  comparison_queue(s21_queue, std_queue);
  comparison_queue(s21_copy_queue, std_copy_queue);
}

TEST(TestQueueCreate, Test_create_7) {
  s21::queue<char> s21_queue = create_s21_queue_2();
  std::queue<char> std_queue = create_std_queue_2();
  s21::queue<char> s21_copy_queue(s21_queue);
  std::queue<char> std_copy_queue(std_queue);
  comparison_queue(s21_queue, std_queue);
  comparison_queue(s21_copy_queue, std_copy_queue);
}

// _____________________________________________________________________

TEST(TestQueueElement, Test_element_4) {
  s21::queue<int> s21_queue = create_s21_queue_1();
  std::queue<int> std_queue = create_std_queue_1();
  EXPECT_EQ(s21_queue.front(), std_queue.front());
}

TEST(TestQueueElement, Test_element_5) {
  s21::queue<char> s21_queue = create_s21_queue_2();
  std::queue<char> std_queue = create_std_queue_2();
  EXPECT_EQ(s21_queue.front(), std_queue.front());
}

TEST(TestQueueElement, Test_element_6) {
  s21::queue<int> s21_queue = create_s21_queue_1();
  std::queue<int> std_queue = create_std_queue_1();
  EXPECT_EQ(s21_queue.back(), std_queue.back());
}

TEST(TestQueueElement, Test_element_7) {
  s21::queue<char> s21_queue = create_s21_queue_2();
  std::queue<char> std_queue = create_std_queue_2();
  EXPECT_EQ(s21_queue.back(), std_queue.back());
}

// _____________________________________________________________________

TEST(TestQueueCapacity, Test_capacity_0) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(TestQueueCapacity, Test_capacity_1) {
  s21::queue<char> s21_queue;
  std::queue<char> std_queue;
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(TestQueueCapacity, Test_capacity_2) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(s21_queue.size(), std_queue.size());
}

TEST(TestQueueCapacity, Test_capacity_3) {
  s21::queue<char> s21_queue;
  std::queue<char> std_queue;
  EXPECT_EQ(s21_queue.size(), std_queue.size());
}

TEST(TestQueueCapacity, Test_capacity_4) {
  s21::queue<int> s21_queue = create_s21_queue_1();
  std::queue<int> std_queue = create_std_queue_1();
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(TestQueueCapacity, Test_capacity_5) {
  s21::queue<char> s21_queue = create_s21_queue_2();
  std::queue<char> std_queue = create_std_queue_2();
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(TestQueueCapacity, Test_capacity_6) {
  s21::queue<int> s21_queue = create_s21_queue_1();
  std::queue<int> std_queue = create_std_queue_1();
  EXPECT_EQ(s21_queue.size(), std_queue.size());
}

TEST(TestQueueCapacity, Test_capacity_7) {
  s21::queue<char> s21_queue = create_s21_queue_2();
  std::queue<char> std_queue = create_std_queue_2();
  EXPECT_EQ(s21_queue.size(), std_queue.size());
}

// _____________________________________________________________________

TEST(TestQueueModifiers, Test_push_0) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  s21_queue.push(15);
  std_queue.push(15);
  comparison_queue(s21_queue, std_queue);
}

TEST(TestQueueModifiers, Test_push_1) {
  s21::queue<int> s21_queue = create_s21_queue_1();
  std::queue<int> std_queue = create_std_queue_1();
  s21_queue.push(15);
  std_queue.push(15);
  comparison_queue(s21_queue, std_queue);
}

TEST(TestQueueModifiers, Test_push_2) {
  s21::queue<int> s21_queue = create_s21_queue_1();
  std::queue<int> std_queue = create_std_queue_1();
  s21_queue.push(15);
  std_queue.push(15);
  s21_queue.push(15);
  std_queue.push(15);

  comparison_queue(s21_queue, std_queue);
}

// _____________________________________________________________________

TEST(TestQueueModifiers, Test_pop_1) {
  s21::queue<int> s21_queue = create_s21_queue_1();
  std::queue<int> std_queue = create_std_queue_1();
  s21_queue.pop();
  std_queue.pop();
  comparison_queue(s21_queue, std_queue);
}

TEST(TestQueueModifiers, Test_pop_2) {
  s21::queue<int> s21_queue = create_s21_queue_1();
  std::queue<int> std_queue = create_std_queue_1();
  s21_queue.pop();
  std_queue.pop();
  s21_queue.pop();
  std_queue.pop();

  comparison_queue(s21_queue, std_queue);
}

// _____________________________________________________________________

TEST(TestQueueModifiers, Test_swap_0) {
  s21::queue<int> s21_queue;
  s21::queue<int> s21_queue1;
  std::queue<int> std_queue;
  std::queue<int> std_queue1;
  s21_queue.swap(s21_queue1);
  std_queue.swap(std_queue1);
  comparison_queue(s21_queue, std_queue);
  comparison_queue(s21_queue1, std_queue1);
}

TEST(TestQueueModifiers, Test_swap_1) {
  s21::queue<int> s21_queue = create_s21_queue_1();
  s21::queue<int> s21_queue1{8, 13};
  std::queue<int> std_queue = create_std_queue_1();
  std::queue<int> std_queue1;
  std_queue1.push(8);
  std_queue1.push(13);
  s21_queue.swap(s21_queue1);
  std_queue.swap(std_queue1);
  comparison_queue(s21_queue, std_queue);
  comparison_queue(s21_queue1, std_queue1);
}

TEST(TestQueueModifiers, Test_swap_2) {
  s21::queue<int> s21_queue = create_s21_queue_1();
  s21::queue<int> s21_queue1{9, 18, 3, 5};
  std::queue<int> std_queue = create_std_queue_1();
  std::queue<int> std_queue1;
  std_queue1.push(9);
  std_queue1.push(18);
  std_queue1.push(3);
  std_queue1.push(5);
  s21_queue.swap(s21_queue1);
  std_queue.swap(std_queue1);
  comparison_queue(s21_queue, std_queue);
  comparison_queue(s21_queue1, std_queue1);
}

TEST(TestQueueModifiers, Test_insert_many_back_0) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  s21_queue.insert_many_back(15);
  std_queue.push(15);
  comparison_queue(s21_queue, std_queue);
}

TEST(TestQueueModifiers, Test_insert_many_back_1) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue = create_std_queue_1();
  s21_queue.insert_many_back(1, 2, 4, 5, 15);
  std_queue.push(15);
  comparison_queue(s21_queue, std_queue);
}

TEST(TestQueueModifiers, Test_insert_many_back_2) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue = create_std_queue_1();
  s21_queue.insert_many_back(1, 2, 4, 5);
  std_queue.push(15);
  s21_queue.insert_many_back(15, 15);
  std_queue.push(15);

  comparison_queue(s21_queue, std_queue);
}