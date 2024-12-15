#include "../unit_tests.h"

template <typename T>
void comparison_list(s21::list<T> s21_list, std::list<T> std_list) {
  EXPECT_EQ(s21_list.size(), std_list.size());
  auto s21_iter = s21_list.begin();
  auto std_iter = std_list.begin();
  for (; s21_iter != s21_list.end() && std_iter != std_list.end();
       s21_iter++, std_iter++) {
    EXPECT_EQ(*s21_iter, *std_iter);
  }
}

s21::list<int> create_s21_list_1() {
  s21::list<int> s21_list{1, 2, 4, 5};
  return s21_list;
}

std::list<int> create_std_list_1() {
  std::list<int> std_list{1, 2, 4, 5};
  return std_list;
}

s21::list<char> create_s21_list_2() {
  s21::list<char> s21_list{'1', '2', '4', '5'};
  return s21_list;
}

std::list<char> create_std_list_2() {
  std::list<char> std_list{'1', '2', '4', '5'};
  return std_list;
}

TEST(TestlistCreate, Test_create_0) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  comparison_list(s21_list, std_list);
}

TEST(TestlistCreate, Test_create_1) {
  s21::list<char> s21_list;
  std::list<char> std_list;
  comparison_list(s21_list, std_list);
}

TEST(TestlistCreate, Test_create_2) {
  s21::list<int> s21_list(3);
  std::list<int> std_list(3);
  comparison_list(s21_list, std_list);
}

TEST(TestlistCreate, Test_create_3) {
  s21::list<char> s21_list(3);
  std::list<char> std_list(3);
  comparison_list(s21_list, std_list);
}

TEST(TestlistCreate, Test_create_4) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  comparison_list(s21_list, std_list);
}

TEST(TestlistCreate, Test_create_5) {
  s21::list<char> s21_list = create_s21_list_2();
  std::list<char> std_list = create_std_list_2();
  comparison_list(s21_list, std_list);
}

TEST(TestlistCreate, Test_create_6) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  s21::list<int> s21_copy_list(s21_list);
  std::list<int> std_copy_list(std_list);
  comparison_list(s21_list, std_list);
  comparison_list(s21_copy_list, std_copy_list);
}

TEST(TestlistCreate, Test_create_7) {
  s21::list<char> s21_list = create_s21_list_2();
  std::list<char> std_list = create_std_list_2();
  s21::list<char> s21_copy_list(s21_list);
  std::list<char> std_copy_list(std_list);
  comparison_list(s21_list, std_list);
  comparison_list(s21_copy_list, std_copy_list);
}

TEST(TestlistCreate, Test_create_8) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  s21::list<int> s21_copy_list = s21_list;
  std::list<int> std_copy_list = std_list;
  comparison_list(s21_list, std_list);
  comparison_list(s21_copy_list, std_copy_list);
}

TEST(TestlistCreate, Test_create_9) {
  s21::list<char> s21_list = create_s21_list_2();
  std::list<char> std_list = create_std_list_2();
  s21::list<char> s21_copy_list(s21_list);
  std::list<char> std_copy_list(std_list);
  comparison_list(s21_list, std_list);
  comparison_list(s21_copy_list, std_copy_list);
}

// _____________________________________________________________________

TEST(TestlistElement, Test_element_0) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  EXPECT_EQ(s21_list.front(), std_list.front());
}

TEST(TestlistElement, Test_element_1) {
  s21::list<char> s21_list;
  std::list<char> std_list;
  EXPECT_EQ(s21_list.front(), std_list.front());
}

TEST(TestlistElement, Test_element_2) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(TestlistElement, Test_element_3) {
  s21::list<char> s21_list;
  std::list<char> std_list;
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(TestlistElement, Test_element_4) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  EXPECT_EQ(s21_list.front(), std_list.front());
}

TEST(TestlistElement, Test_element_5) {
  s21::list<char> s21_list = create_s21_list_2();
  std::list<char> std_list = create_std_list_2();
  EXPECT_EQ(s21_list.front(), std_list.front());
}

TEST(TestlistElement, Test_element_6) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(TestlistElement, Test_element_7) {
  s21::list<char> s21_list = create_s21_list_2();
  std::list<char> std_list = create_std_list_2();
  EXPECT_EQ(s21_list.back(), std_list.back());
}

// _____________________________________________________________________

TEST(TestlistIterator, Test_iterator_0) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  EXPECT_EQ(*(s21_list.begin()), *(std_list.begin()));
}

TEST(TestlistIterator, Test_iterator_1) {
  s21::list<char> s21_list;
  std::list<char> std_list;
  EXPECT_EQ(*(s21_list.begin()), *(std_list.begin()));
}

TEST(TestlistIterator, Test_iterator_4) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  EXPECT_EQ(*(s21_list.begin()), *(std_list.begin()));
}

TEST(TestlistIterator, Test_iterator_5) {
  s21::list<char> s21_list = create_s21_list_2();
  std::list<char> std_list = create_std_list_2();
  EXPECT_EQ(*(s21_list.begin()), *(std_list.begin()));
}

// _____________________________________________________________________

TEST(TestlistCapacity, Test_capacity_0) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(TestlistCapacity, Test_capacity_1) {
  s21::list<char> s21_list;
  std::list<char> std_list;
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(TestlistCapacity, Test_capacity_2) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(TestlistCapacity, Test_capacity_3) {
  s21::list<char> s21_list;
  std::list<char> std_list;
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(TestlistCapacity, Test_capacity_6) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(TestlistCapacity, Test_capacity_7) {
  s21::list<char> s21_list = create_s21_list_2();
  std::list<char> std_list = create_std_list_2();
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(TestlistCapacity, Test_capacity_8) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(TestlistCapacity, Test_capacity_9) {
  s21::list<char> s21_list = create_s21_list_2();
  std::list<char> std_list = create_std_list_2();
  EXPECT_EQ(s21_list.size(), std_list.size());
}

// _____________________________________________________________________

TEST(TestlistModifiers, Test_clear_0) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  s21_list.clear();
  std_list.clear();
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_clear_1) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  s21_list.clear();
  std_list.clear();
  comparison_list(s21_list, std_list);
}

// _____________________________________________________________________

TEST(TestlistModifiers, Test_insert_0) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  s21_list.insert(s21_list.begin(), 15);
  std_list.insert(std_list.begin(), 15);
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_insert_1) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  s21_list.insert(s21_list.begin(), 15);
  std_list.insert(std_list.begin(), 15);
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_insert_2) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  s21_list.insert(s21_list.end(), 15);
  std_list.insert(std_list.end(), 15);
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_insert_3) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();

  auto s21_iter = s21_list.begin();
  auto std_iter = std_list.begin();

  s21_iter = s21_list.insert(s21_iter, 15);
  std_iter = std_list.insert(std_iter, 15);
  s21_list.insert(s21_iter, 20);
  std_list.insert(std_iter, 20);

  s21_iter = s21_list.begin();
  std_iter = std_list.begin();
  s21_list.insert(s21_iter, 25);
  std_list.insert(std_iter, 25);

  comparison_list(s21_list, std_list);
}

// _____________________________________________________________________

TEST(TestlistModifiers, Test_erase_1) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  s21_list.erase(s21_list.begin());
  std_list.erase(std_list.begin());
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_erase_2) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();

  auto s21_iter = s21_list.begin();
  auto std_iter = std_list.begin();
  s21_iter++;
  std_iter++;

  s21_list.erase(s21_iter);
  std_list.erase(std_iter);

  comparison_list(s21_list, std_list);
}

// _____________________________________________________________________

TEST(TestlistModifiers, Test_push_back_0) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  s21_list.push_back(15);
  std_list.push_back(15);
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_push_back_1) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  s21_list.push_back(15);
  std_list.push_back(15);
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_push_back_2) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  s21_list.push_back(15);
  std_list.push_back(15);
  s21_list.push_back(15);
  std_list.push_back(15);

  comparison_list(s21_list, std_list);
}

// _____________________________________________________________________

TEST(TestlistModifiers, Test_pop_back_1) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  s21_list.pop_back();
  std_list.pop_back();
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_pop_back_2) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  s21_list.pop_back();
  std_list.pop_back();
  s21_list.pop_back();
  std_list.pop_back();

  comparison_list(s21_list, std_list);
}

// _____________________________________________________________________

TEST(TestlistModifiers, Test_push_front_0) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  s21_list.push_front(15);
  std_list.push_front(15);
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_push_front_1) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  s21_list.push_front(15);
  std_list.push_front(15);
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_push_front_2) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  s21_list.push_front(15);
  std_list.push_front(15);
  s21_list.push_front(15);
  std_list.push_front(15);

  comparison_list(s21_list, std_list);
}

// _____________________________________________________________________

TEST(TestlistModifiers, Test_pop_front_1) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  s21_list.pop_front();
  std_list.pop_front();
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_pop_front_2) {
  s21::list<int> s21_list = create_s21_list_1();
  std::list<int> std_list = create_std_list_1();
  s21_list.pop_front();
  std_list.pop_front();
  s21_list.pop_front();
  std_list.pop_front();

  comparison_list(s21_list, std_list);
}

// _____________________________________________________________________

TEST(TestlistModifiers, Test_swap_0) {
  s21::list<int> s21_list;
  s21::list<int> s21_list1;
  std::list<int> std_list;
  std::list<int> std_list1;
  s21_list.swap(s21_list1);
  std_list.swap(std_list1);
  comparison_list(s21_list, std_list);
  comparison_list(s21_list1, std_list1);
}

TEST(TestlistModifiers, Test_swap_1) {
  s21::list<int> s21_list = create_s21_list_1();
  s21::list<int> s21_list1{8, 13};
  std::list<int> std_list = create_std_list_1();
  std::list<int> std_list1{8, 13};
  s21_list.swap(s21_list1);
  std_list.swap(std_list1);
  comparison_list(s21_list, std_list);
  comparison_list(s21_list1, std_list1);
}

TEST(TestlistModifiers, Test_swap_2) {
  s21::list<int> s21_list = create_s21_list_1();
  s21::list<int> s21_list1{9, 18, 3, 5};
  std::list<int> std_list = create_std_list_1();
  std::list<int> std_list1{9, 18, 3, 5};
  s21_list.swap(s21_list1);
  std_list.swap(std_list1);
  comparison_list(s21_list, std_list);
  comparison_list(s21_list1, std_list1);
}

// _____________________________________________________________________

TEST(TestlistModifiers, Test_merge_0) {
  s21::list<int> s21_list;
  s21::list<int> s21_list1;
  std::list<int> std_list;
  std::list<int> std_list1;
  s21_list.merge(s21_list1);
  std_list.merge(std_list1);
  comparison_list(s21_list, std_list);
  comparison_list(s21_list1, std_list1);
}

TEST(TestlistModifiers, Test_merge_1) {
  s21::list<int> s21_list = create_s21_list_1();
  s21::list<int> s21_list1{8, 13};
  std::list<int> std_list = create_std_list_1();
  std::list<int> std_list1{8, 13};
  s21_list.merge(s21_list1);
  std_list.merge(std_list1);
  comparison_list(s21_list, std_list);
  comparison_list(s21_list1, std_list1);
}

TEST(TestlistModifiers, Test_merge_2) {
  s21::list<int> s21_list = create_s21_list_1();
  s21::list<int> s21_list1{9, 18, 3, 5};
  std::list<int> std_list = create_std_list_1();
  std::list<int> std_list1{9, 18, 3, 5};
  s21_list.merge(s21_list1);
  std_list.merge(std_list1);
  comparison_list(s21_list, std_list);
  comparison_list(s21_list1, std_list1);
}

// _____________________________________________________________________

TEST(TestlistModifiers, Test_splice_0) {
  s21::list<int> s21_list;
  s21::list<int> s21_list1;
  std::list<int> std_list;
  std::list<int> std_list1;
  s21_list.splice(s21_list.begin(), s21_list1);
  std_list.splice(std_list.begin(), std_list1);
  comparison_list(s21_list, std_list);
  comparison_list(s21_list1, std_list1);
}

TEST(TestlistModifiers, Test_splice_1) {
  s21::list<int> s21_list = create_s21_list_1();
  s21::list<int> s21_list1{8, 13};
  std::list<int> std_list = create_std_list_1();
  std::list<int> std_list1{8, 13};

  auto s21_iter = s21_list.begin();
  auto std_iter = std_list.begin();
  s21_iter++;
  std_iter++;

  s21_list.splice(s21_iter, s21_list1);
  std_list.splice(std_iter, std_list1);
  comparison_list(s21_list, std_list);
  comparison_list(s21_list1, std_list1);
}

TEST(TestlistModifiers, Test_splice_2) {
  s21::list<int> s21_list = create_s21_list_1();
  s21::list<int> s21_list1{9, 18, 3, 5};
  std::list<int> std_list = create_std_list_1();
  std::list<int> std_list1{9, 18, 3, 5};

  auto s21_iter = s21_list.begin();
  auto std_iter = std_list.begin();
  s21_iter++;
  std_iter++;

  s21_list.splice(s21_iter, s21_list1);
  std_list.splice(std_iter, std_list1);
  comparison_list(s21_list, std_list);
  comparison_list(s21_list1, std_list1);
}

// _____________________________________________________________________

TEST(TestlistModifiers, Test_reverse_0) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  s21_list.reverse();
  std_list.reverse();
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_reverse_1) {
  s21::list<int> s21_list{1, 2, 4, 5, 8, 13};
  std::list<int> std_list{1, 2, 4, 5, 8, 13};
  s21_list.reverse();
  std_list.reverse();
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_reverse_2) {
  s21::list<int> s21_list{1, 2, 4, 5, 9, 18, 3, 5};
  std::list<int> std_list{1, 2, 4, 5, 9, 18, 3, 5};

  s21_list.reverse();
  std_list.reverse();
  comparison_list(s21_list, std_list);
}

// _____________________________________________________________________

TEST(TestlistModifiers, Test_unique_0) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  s21_list.unique();
  std_list.unique();
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_unique_1) {
  s21::list<int> s21_list{1, 2, 4, 5, 8, 13};
  std::list<int> std_list{1, 2, 4, 5, 8, 13};
  s21_list.unique();
  std_list.unique();
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_unique_2) {
  s21::list<int> s21_list{1, 2, 4, 5, 9, 18, 3, 5};
  std::list<int> std_list{1, 2, 4, 5, 9, 18, 3, 5};

  s21_list.unique();
  std_list.unique();
  comparison_list(s21_list, std_list);
}

// _____________________________________________________________________

TEST(TestlistModifiers, Test_sort_0) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  s21_list.sort();
  std_list.sort();
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_sort_1) {
  s21::list<int> s21_list{1, 2, 4, 5, 8, 13};
  std::list<int> std_list{1, 2, 4, 5, 8, 13};
  s21_list.sort();
  std_list.sort();
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_sort_2) {
  s21::list<int> s21_list{3, 2, 1, 5, 9, 18, 3, 5};
  std::list<int> std_list{3, 2, 1, 5, 9, 18, 3, 5};

  s21_list.sort();
  std_list.sort();
  comparison_list(s21_list, std_list);
}

// _____________________________________________________________________

TEST(TestlistModifiers, Test_insert_many_0) {
  s21::list<int> s21_list;
  std::list<int> std_list{1, 2, 4, 5, 8, 13};
  s21_list.insert_many(s21_list.begin(), 1, 2, 4, 5, 8, 13);
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_insert_many_1) {
  s21::list<int> s21_list{1, 2, 13};
  std::list<int> std_list{1, 2, 4, 5, 8, 13};
  auto iter = s21_list.begin();
  iter++;
  iter++;
  s21_list.insert_many(iter, 4, 5, 8);
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_insert_many_back_0) {
  s21::list<int> s21_list;
  std::list<int> std_list{1, 2, 4, 5, 8, 13};
  s21_list.insert_many_back(1, 2, 4, 5, 8, 13);
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_insert_many_back_1) {
  s21::list<int> s21_list{1, 2};
  std::list<int> std_list{1, 2, 4, 5, 8, 13};
  s21_list.insert_many_back(4, 5, 8, 13);
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_insert_many_front_0) {
  s21::list<int> s21_list;
  std::list<int> std_list{1, 2, 4, 5, 8, 13};
  s21_list.insert_many_front(1, 2, 4, 5, 8, 13);
  comparison_list(s21_list, std_list);
}

TEST(TestlistModifiers, Test_insert_many_front_1) {
  s21::list<int> s21_list{4, 5, 8, 13};
  std::list<int> std_list{1, 2, 4, 5, 8, 13};
  s21_list.insert_many_front(1, 2);
  comparison_list(s21_list, std_list);
}