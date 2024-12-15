#include "../unit_tests.h"

template <typename T>
void comparison_set(s21::set<T> s21_set, std::set<T> std_set) {
  EXPECT_EQ(s21_set.size(), std_set.size());
  auto s21_iter = s21_set.begin();
  auto std_iter = std_set.begin();
  for (; s21_iter != s21_set.end() && std_iter != std_set.end();
       s21_iter++, std_iter++) {
    EXPECT_EQ(*s21_iter, *std_iter);
  }
}

s21::set<int> create_s21_set_1() {
  s21::set<int> s21_set{5, 78, 564, 1, 2, 78, 65};
  return s21_set;
}

std::set<int> create_std_set_1() {
  std::set<int> std_set{5, 78, 564, 1, 2, 78, 65};
  return std_set;
}

s21::set<char> create_s21_set_2() {
  s21::set<char> s21_set{'a', 'f', 'b', 'a', 'q', 'w'};
  return s21_set;
}

std::set<char> create_std_set_2() {
  std::set<char> std_set{'a', 'f', 'b', 'a', 'q', 'w'};
  return std_set;
}

s21::set<int> create_s21_set_3() {
  s21::set<int> s21_set{5, 456, 545};
  return s21_set;
}

std::set<int> create_std_set_3() {
  std::set<int> std_set{5, 456, 545};
  return std_set;
}

TEST(TestSetCreate, Test_create_0) {
  s21::set<int> s21_set;
  std::set<int> std_set;
  comparison_set(s21_set, std_set);
}

TEST(TestSetCreate, Test_create_1) {
  s21::set<char> s21_set;
  std::set<char> std_set;
  comparison_set(s21_set, std_set);
}

TEST(TestSetCreate, Test_create_2) {
  s21::set<int> s21_set = create_s21_set_1();
  std::set<int> std_set = create_std_set_1();
  comparison_set(s21_set, std_set);
}

TEST(TestSetCreate, Test_create_3) {
  s21::set<char> s21_set = create_s21_set_2();
  std::set<char> std_set = create_std_set_2();
  comparison_set(s21_set, std_set);
}

TEST(TestSetCreate, Test_create_4) {
  s21::set<int> s21_set = create_s21_set_1();
  std::set<int> std_set = create_std_set_1();
  s21::set<int> s21_copy_set(s21_set);
  std::set<int> std_copy_set(std_set);
  comparison_set(s21_set, std_set);
  comparison_set(s21_copy_set, std_copy_set);
}

TEST(TestSetCreate, Test_create_5) {
  s21::set<char> s21_set = create_s21_set_2();
  std::set<char> std_set = create_std_set_2();
  s21::set<char> s21_copy_set(s21_set);
  std::set<char> std_copy_set(std_set);
  comparison_set(s21_set, std_set);
  comparison_set(s21_copy_set, std_copy_set);
}

TEST(TestSetCreate, Test_create_6) {
  s21::set<int> s21_set = create_s21_set_1();
  std::set<int> std_set = create_std_set_1();
  s21::set<int> s21_copy_set = s21_set;
  std::set<int> std_copy_set = std_set;
  comparison_set(s21_set, std_set);
  comparison_set(s21_copy_set, std_copy_set);
}

TEST(TestSetCreate, Test_create_7) {
  s21::set<char> s21_set = create_s21_set_2();
  std::set<char> std_set = create_std_set_2();
  s21::set<char> s21_copy_set = s21_set;
  std::set<char> std_copy_set = std_set;
  comparison_set(s21_set, std_set);
  comparison_set(s21_copy_set, std_copy_set);
}

// _____________________________________________________________________

TEST(TestSetIterator, Test_iterator_4) {
  s21::set<int> s21_set = create_s21_set_1();
  std::set<int> std_set = create_std_set_1();
  auto s21_iter = s21_set.begin();
  auto std_iter = std_set.begin();
  EXPECT_EQ(*s21_iter, *std_iter);
}

TEST(TestSetIterator, Test_iterator_5) {
  s21::set<char> s21_set = create_s21_set_2();
  std::set<char> std_set = create_std_set_2();
  auto s21_iter = s21_set.begin();
  auto std_iter = std_set.begin();
  EXPECT_EQ(*s21_iter, *std_iter);
}

TEST(TestSetIterator, Test_iterator_6) {
  s21::set<int> s21_set = create_s21_set_1();
  std::set<int> std_set = create_std_set_1();
  auto s21_iter = s21_set.end();
  auto std_iter = std_set.end();
  s21_iter--;
  std_iter--;
  EXPECT_EQ(*s21_iter, *std_iter);
}

TEST(TestSetIterator, Test_iterator_7) {
  s21::set<char> s21_set = create_s21_set_2();
  std::set<char> std_set = create_std_set_2();
  auto s21_iter = s21_set.end();
  auto std_iter = std_set.end();
  s21_iter--;
  std_iter--;
  EXPECT_EQ(*s21_iter, *std_iter);
}

// // _____________________________________________________________________

TEST(TestSetCapacity, Test_capacity_0) {
  s21::set<int> s21_set;
  std::set<int> std_set;
  EXPECT_EQ(s21_set.empty(), std_set.empty());
}

TEST(TestSetCapacity, Test_capacity_1) {
  s21::set<char> s21_set;
  std::set<char> std_set;
  EXPECT_EQ(s21_set.empty(), std_set.empty());
}

TEST(TestSetCapacity, Test_capacity_2) {
  s21::set<int> s21_set;
  std::set<int> std_set;
  EXPECT_EQ(s21_set.size(), std_set.size());
}

TEST(TestSetCapacity, Test_capacity_3) {
  s21::set<char> s21_set;
  std::set<char> std_set;
  EXPECT_EQ(s21_set.size(), std_set.size());
}

TEST(TestSetCapacity, Test_capacity_6) {
  s21::set<int> s21_set = create_s21_set_1();
  std::set<int> std_set = create_std_set_1();
  EXPECT_EQ(s21_set.empty(), std_set.empty());
}

TEST(TestSetCapacity, Test_capacity_7) {
  s21::set<char> s21_set = create_s21_set_2();
  std::set<char> std_set = create_std_set_2();
  EXPECT_EQ(s21_set.empty(), std_set.empty());
}

TEST(TestSetCapacity, Test_capacity_8) {
  s21::set<int> s21_set = create_s21_set_1();
  std::set<int> std_set = create_std_set_1();
  EXPECT_EQ(s21_set.size(), std_set.size());
}

TEST(TestSetCapacity, Test_capacity_9) {
  s21::set<char> s21_set = create_s21_set_2();
  std::set<char> std_set = create_std_set_2();
  EXPECT_EQ(s21_set.size(), std_set.size());
}

// _____________________________________________________________________

TEST(TestSetModifiers, Test_clear_0) {
  s21::set<int> s21_set;
  std::set<int> std_set;
  s21_set.clear();
  std_set.clear();
  comparison_set(s21_set, std_set);
}

TEST(TestSetModifiers, Test_clear_1) {
  s21::set<int> s21_set = create_s21_set_1();
  std::set<int> std_set = create_std_set_1();
  s21_set.clear();
  std_set.clear();
  comparison_set(s21_set, std_set);
}

// _____________________________________________________________________

TEST(TestSetModifiers, Test_insert_0) {
  s21::set<int> s21_set;
  std::set<int> std_set;

  s21_set.insert(5);
  std_set.insert(5);
  comparison_set(s21_set, std_set);
}

TEST(TestSetModifiers, Test_insert_1) {
  s21::set<int> s21_set;
  std::set<int> std_set;

  s21_set.insert(999);
  std_set.insert(999);
  comparison_set(s21_set, std_set);
}

TEST(TestSetModifiers, Test_insert_2) {
  s21::set<int> s21_set = create_s21_set_1();
  std::set<int> std_set = create_std_set_1();

  s21_set.insert(5);
  std_set.insert(5);
  comparison_set(s21_set, std_set);
}

TEST(TestSetModifiers, Test_insert_3) {
  s21::set<int> s21_set = create_s21_set_1();
  std::set<int> std_set = create_std_set_1();

  s21_set.insert(999);
  std_set.insert(999);
  comparison_set(s21_set, std_set);
}

// // _____________________________________________________________________

TEST(TestSetModifiers, Test_erase_1) {
  s21::set<int> s21_set = create_s21_set_1();
  std::set<int> std_set = create_std_set_1();
  s21_set.erase(s21_set.begin());
  std_set.erase(std_set.begin());
  comparison_set(s21_set, std_set);
}

TEST(TestSetModifiers, Test_erase_2) {
  s21::set<int> s21_set = create_s21_set_1();
  std::set<int> std_set = create_std_set_1();

  auto s21_iter = s21_set.begin();
  auto std_iter = std_set.begin();
  s21_iter++;
  std_iter++;

  s21_set.erase(s21_iter);
  std_set.erase(std_iter);

  comparison_set(s21_set, std_set);
}

// _____________________________________________________________________

TEST(TestSetModifiers, Test_swap_0) {
  s21::set<int> s21_set;
  std::set<int> std_set;
  s21::set<int> s21_set1;
  std::set<int> std_set1;
  s21_set.swap(s21_set1);
  std_set.swap(std_set1);
  comparison_set(s21_set, std_set);
  comparison_set(s21_set1, std_set1);
}

TEST(TestSetModifiers, Test_swap_1) {
  s21::set<int> s21_set = create_s21_set_1();
  std::set<int> std_set = create_std_set_1();
  s21::set<int> s21_set1 = create_s21_set_3();
  std::set<int> std_set1 = create_std_set_3();
  s21_set.swap(s21_set1);
  std_set.swap(std_set1);
  comparison_set(s21_set, std_set);
  comparison_set(s21_set1, std_set1);
}

// _____________________________________________________________________

TEST(TestSetModifiers, Test_merge_0) {
  s21::set<int> s21_set;
  std::set<int> std_set;
  s21::set<int> s21_set1;
  std::set<int> std_set1;
  s21_set.merge(s21_set1);
  std_set.merge(std_set1);
  comparison_set(s21_set, std_set);
  comparison_set(s21_set1, std_set1);
}

TEST(TestSetModifiers, Test_merge_1) {
  s21::set<int> s21_set = create_s21_set_1();
  std::set<int> std_set = create_std_set_1();
  s21::set<int> s21_set1 = create_s21_set_3();
  std::set<int> std_set1 = create_std_set_3();
  s21_set.merge(s21_set1);
  std_set.merge(std_set1);
  comparison_set(s21_set, std_set);
  comparison_set(s21_set1, std_set1);
}

// _____________________________________________________________________

TEST(TestSetLookup, Test_find_2) {
  s21::set<int> s21_set = create_s21_set_1();
  std::set<int> std_set = create_std_set_1();
  auto s21_iter = s21_set.find(5);
  auto std_iter = std_set.find(5);
  EXPECT_EQ(*s21_iter, *std_iter);
}

TEST(TestSetLookup, Test_contains_0) {
  s21::set<int> s21_set;
  EXPECT_EQ(s21_set.contains(15), false);
}

TEST(TestSetLookup, Test_contains_1) {
  s21::set<int> s21_set = create_s21_set_1();
  EXPECT_EQ(s21_set.contains(15), false);
}

TEST(TestSetLookup, Test_contains_2) {
  s21::set<int> s21_set = create_s21_set_1();
  EXPECT_EQ(s21_set.contains(65), true);
}

// _____________________________________________________________________

TEST(TestSetModifiers, Test_insert_many_0) {
  s21::set<int> s21_set;
  std::set<int> std_set;

  s21_set.insert_many(5);
  std_set.insert(5);
  comparison_set(s21_set, std_set);
}

TEST(TestSetModifiers, Test_insert_many_1) {
  s21::set<int> s21_set;
  std::set<int> std_set = create_std_set_1();

  s21_set.insert_many(5, 78, 564, 1, 2, 78, 65, 5);
  std_set.insert(5);
  comparison_set(s21_set, std_set);
}

TEST(TestSetModifiers, Test_insert_many_2) {
  s21::set<int> s21_set;
  std::set<int> std_set = create_std_set_1();

  s21_set.insert_many(5, 78, 564, 1, 2, 78, 65, 999);
  std_set.insert(999);
  comparison_set(s21_set, std_set);
}