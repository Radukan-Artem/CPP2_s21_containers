#include "../unit_tests.h"

template <typename T>
void comparison_multiset(s21::multiset<T> s21_multiset,
                         std::multiset<T> std_multiset) {
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  auto s21_iter = s21_multiset.begin();
  auto std_iter = std_multiset.begin();
  for (; s21_iter != s21_multiset.end() && std_iter != std_multiset.end();
       s21_iter++, std_iter++) {
    EXPECT_EQ(*s21_iter, *std_iter);
  }
}

s21::multiset<int> create_s21_multiset_1() {
  s21::multiset<int> s21_multiset{5, 78, 564, 1, 2, 78, 65};
  return s21_multiset;
}

std::multiset<int> create_std_multiset_1() {
  std::multiset<int> std_multiset{5, 78, 564, 1, 2, 78, 65};
  return std_multiset;
}

s21::multiset<char> create_s21_multiset_2() {
  s21::multiset<char> s21_multiset{'a', 'f', 'b', 'a', 'q', 'w'};
  return s21_multiset;
}

std::multiset<char> create_std_multiset_2() {
  std::multiset<char> std_multiset{'a', 'f', 'b', 'a', 'q', 'w'};
  return std_multiset;
}

s21::multiset<int> create_s21_multiset_3() {
  s21::multiset<int> s21_multiset{5, 456, 545};
  return s21_multiset;
}

std::multiset<int> create_std_multiset_3() {
  std::multiset<int> std_multiset{5, 456, 545};
  return std_multiset;
}

TEST(TestMultiSetCreate, Test_create_0) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;
  comparison_multiset(s21_multiset, std_multiset);
}

TEST(TestMultiSetCreate, Test_create_1) {
  s21::multiset<char> s21_multiset;
  std::multiset<char> std_multiset;
  comparison_multiset(s21_multiset, std_multiset);
}

TEST(TestMultiSetCreate, Test_create_2) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  comparison_multiset(s21_multiset, std_multiset);
}

TEST(TestMultiSetCreate, Test_create_3) {
  s21::multiset<char> s21_multiset = create_s21_multiset_2();
  std::multiset<char> std_multiset = create_std_multiset_2();
  comparison_multiset(s21_multiset, std_multiset);
}

TEST(TestMultiSetCreate, Test_create_4) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  s21::multiset<int> s21_copy_multiset(s21_multiset);
  std::multiset<int> std_copy_multiset(std_multiset);
  comparison_multiset(s21_multiset, std_multiset);
  comparison_multiset(s21_copy_multiset, std_copy_multiset);
}

TEST(TestMultiSetCreate, Test_create_5) {
  s21::multiset<char> s21_multiset = create_s21_multiset_2();
  std::multiset<char> std_multiset = create_std_multiset_2();
  s21::multiset<char> s21_copy_multiset(s21_multiset);
  std::multiset<char> std_copy_multiset(std_multiset);
  comparison_multiset(s21_multiset, std_multiset);
  comparison_multiset(s21_copy_multiset, std_copy_multiset);
}

TEST(TestMultiSetCreate, Test_create_6) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  s21::multiset<int> s21_copy_multiset = s21_multiset;
  std::multiset<int> std_copy_multiset = std_multiset;
  comparison_multiset(s21_multiset, std_multiset);
  comparison_multiset(s21_copy_multiset, std_copy_multiset);
}

TEST(TestMultiSetCreate, Test_create_7) {
  s21::multiset<char> s21_multiset = create_s21_multiset_2();
  std::multiset<char> std_multiset = create_std_multiset_2();
  s21::multiset<char> s21_copy_multiset = s21_multiset;
  std::multiset<char> std_copy_multiset = std_multiset;
  comparison_multiset(s21_multiset, std_multiset);
  comparison_multiset(s21_copy_multiset, std_copy_multiset);
}

// _____________________________________________________________________

TEST(TestMultiSetIterator, Test_iterator_4) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  auto s21_iter = s21_multiset.begin();
  auto std_iter = std_multiset.begin();
  EXPECT_EQ(*s21_iter, *std_iter);
}

TEST(TestMultiSetIterator, Test_iterator_5) {
  s21::multiset<char> s21_multiset = create_s21_multiset_2();
  std::multiset<char> std_multiset = create_std_multiset_2();
  auto s21_iter = s21_multiset.begin();
  auto std_iter = std_multiset.begin();
  EXPECT_EQ(*s21_iter, *std_iter);
}

TEST(TestMultiSetIterator, Test_iterator_6) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  auto s21_iter = s21_multiset.end();
  auto std_iter = std_multiset.end();
  s21_iter--;
  std_iter--;
  EXPECT_EQ(*s21_iter, *std_iter);
}

TEST(TestMultiSetIterator, Test_iterator_7) {
  s21::multiset<char> s21_multiset = create_s21_multiset_2();
  std::multiset<char> std_multiset = create_std_multiset_2();
  auto s21_iter = s21_multiset.end();
  auto std_iter = std_multiset.end();
  s21_iter--;
  std_iter--;
  EXPECT_EQ(*s21_iter, *std_iter);
}

// _____________________________________________________________________

TEST(TestMultiSetCapacity, Test_capacity_0) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
}

TEST(TestMultiSetCapacity, Test_capacity_1) {
  s21::multiset<char> s21_multiset;
  std::multiset<char> std_multiset;
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
}

TEST(TestMultiSetCapacity, Test_capacity_2) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(TestMultiSetCapacity, Test_capacity_3) {
  s21::multiset<char> s21_multiset;
  std::multiset<char> std_multiset;
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(TestMultiSetCapacity, Test_capacity_6) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
}

TEST(TestMultiSetCapacity, Test_capacity_7) {
  s21::multiset<char> s21_multiset = create_s21_multiset_2();
  std::multiset<char> std_multiset = create_std_multiset_2();
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
}

TEST(TestMultiSetCapacity, Test_capacity_8) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(TestMultiSetCapacity, Test_capacity_9) {
  s21::multiset<char> s21_multiset = create_s21_multiset_2();
  std::multiset<char> std_multiset = create_std_multiset_2();
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

// _____________________________________________________________________

TEST(TestMultiSetModifiers, Test_clear_0) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;
  s21_multiset.clear();
  std_multiset.clear();
  comparison_multiset(s21_multiset, std_multiset);
}

TEST(TestMultiSetModifiers, Test_clear_1) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  s21_multiset.clear();
  std_multiset.clear();
  comparison_multiset(s21_multiset, std_multiset);
}

// _____________________________________________________________________

TEST(TestMultiSetModifiers, Test_insert_0) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;

  s21_multiset.insert(5);
  std_multiset.insert(5);
  comparison_multiset(s21_multiset, std_multiset);
}

TEST(TestMultiSetModifiers, Test_insert_1) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;

  s21_multiset.insert(999);
  std_multiset.insert(999);
  comparison_multiset(s21_multiset, std_multiset);
}

TEST(TestMultiSetModifiers, Test_insert_2) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();

  s21_multiset.insert(5);
  std_multiset.insert(5);
  comparison_multiset(s21_multiset, std_multiset);
}

TEST(TestMultiSetModifiers, Test_insert_3) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();

  s21_multiset.insert(999);
  std_multiset.insert(999);
  comparison_multiset(s21_multiset, std_multiset);
}

// _____________________________________________________________________

TEST(TestMultiSetModifiers, Test_erase_1) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  s21_multiset.erase(s21_multiset.begin());
  std_multiset.erase(std_multiset.begin());
  comparison_multiset(s21_multiset, std_multiset);
}

TEST(TestMultiSetModifiers, Test_erase_2) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();

  auto s21_iter = s21_multiset.begin();
  auto std_iter = std_multiset.begin();
  s21_iter++;
  std_iter++;

  s21_multiset.erase(s21_iter);
  std_multiset.erase(std_iter);

  comparison_multiset(s21_multiset, std_multiset);
}

// _____________________________________________________________________

TEST(TestMultiSetModifiers, Test_swap_0) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;
  s21::multiset<int> s21_multiset1;
  std::multiset<int> std_multiset1;
  s21_multiset.swap(s21_multiset1);
  std_multiset.swap(std_multiset1);
  comparison_multiset(s21_multiset, std_multiset);
  comparison_multiset(s21_multiset1, std_multiset1);
}

TEST(TestMultiSetModifiers, Test_swap_1) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  s21::multiset<int> s21_multiset1 = create_s21_multiset_3();
  std::multiset<int> std_multiset1 = create_std_multiset_3();
  s21_multiset.swap(s21_multiset1);
  std_multiset.swap(std_multiset1);
  comparison_multiset(s21_multiset, std_multiset);
  comparison_multiset(s21_multiset1, std_multiset1);
}

// _____________________________________________________________________

TEST(TestMultiSetModifiers, Test_merge_0) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;
  s21::multiset<int> s21_multiset1;
  std::multiset<int> std_multiset1;
  s21_multiset.merge(s21_multiset1);
  std_multiset.merge(std_multiset1);
  comparison_multiset(s21_multiset, std_multiset);
  comparison_multiset(s21_multiset1, std_multiset1);
}

TEST(TestMultiSetModifiers, Test_merge_1) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  s21::multiset<int> s21_multiset1 = create_s21_multiset_3();
  std::multiset<int> std_multiset1 = create_std_multiset_3();
  s21_multiset.merge(s21_multiset1);
  std_multiset.merge(std_multiset1);
  comparison_multiset(s21_multiset, std_multiset);
  comparison_multiset(s21_multiset1, std_multiset1);
}

// _____________________________________________________________________

TEST(TestMultiSetLookup, Test_count_0) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;
  EXPECT_EQ(s21_multiset.count(999), s21_multiset.count(999));
}

TEST(TestMultiSetLookup, Test_count_1) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  s21::multiset<int> s21_multiset1 = create_s21_multiset_3();
  std::multiset<int> std_multiset1 = create_std_multiset_3();
  s21_multiset.merge(s21_multiset1);
  std_multiset.merge(std_multiset1);
  EXPECT_EQ(s21_multiset.count(999), s21_multiset.count(999));
}

TEST(TestMultiSetLookup, Test_count_2) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  s21::multiset<int> s21_multiset1 = create_s21_multiset_3();
  std::multiset<int> std_multiset1 = create_std_multiset_3();
  s21_multiset.merge(s21_multiset1);
  std_multiset.merge(std_multiset1);
  EXPECT_EQ(s21_multiset.count(5), s21_multiset.count(5));
}

TEST(TestMultiSetLookup, Test_count_3) {
  s21::multiset<int> s21_multiset{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  std::multiset<int> std_multiset{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(s21_multiset.count(1), s21_multiset.count(1));
}

TEST(TestMultiSetLookup, Test_find_2) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  auto s21_iter = s21_multiset.find(5);
  auto std_iter = std_multiset.find(5);
  EXPECT_EQ(*s21_iter, *std_iter);
}

TEST(TestMultiSetLookup, Test_contains_0) {
  s21::multiset<int> s21_multiset;
  EXPECT_EQ(s21_multiset.contains(15), false);
}

TEST(TestMultiSetLookup, Test_contains_1) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  EXPECT_EQ(s21_multiset.contains(15), false);
}

TEST(TestMultiSetLookup, Test_contains_2) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  EXPECT_EQ(s21_multiset.contains(65), true);
}

TEST(TestMultiSetLookup, Test_equal_range_1) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  s21::multiset<int> s21_multiset1 = create_s21_multiset_3();
  std::multiset<int> std_multiset1 = create_std_multiset_3();
  s21_multiset.merge(s21_multiset1);
  std_multiset.merge(std_multiset1);

  auto pair_s21_iter = s21_multiset.equal_range(100);
  auto pair_std_iter = std_multiset.equal_range(100);
  int size_range_s21 = 0, size_range_std = 0;

  EXPECT_EQ(*pair_s21_iter.first, *pair_std_iter.first);
  EXPECT_EQ(*pair_s21_iter.second, *pair_std_iter.second);

  while (pair_s21_iter.first != pair_s21_iter.second) {
    pair_s21_iter.first++;
    size_range_s21++;
  }

  while (pair_std_iter.first != pair_std_iter.second) {
    pair_std_iter.first++;
    size_range_std++;
  }

  EXPECT_EQ(size_range_s21, size_range_std);
}

TEST(TestMultiSetLookup, Test_equal_range_2) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  s21::multiset<int> s21_multiset1 = create_s21_multiset_3();
  std::multiset<int> std_multiset1 = create_std_multiset_3();
  s21_multiset.merge(s21_multiset1);
  std_multiset.merge(std_multiset1);

  auto pair_s21_iter = s21_multiset.equal_range(5);
  auto pair_std_iter = std_multiset.equal_range(5);
  int size_range_s21 = 0, size_range_std = 0;

  EXPECT_EQ(*pair_s21_iter.first, *pair_std_iter.first);
  EXPECT_EQ(*pair_s21_iter.second, *pair_std_iter.second);

  while (pair_s21_iter.first != pair_s21_iter.second) {
    pair_s21_iter.first++;
    size_range_s21++;
  }

  while (pair_std_iter.first != pair_std_iter.second) {
    pair_std_iter.first++;
    size_range_std++;
  }

  EXPECT_EQ(size_range_s21, size_range_std);
}

TEST(TestMultiSetLookup, Test_lower_bound_2) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  auto s21_iter = s21_multiset.lower_bound(5);
  auto std_iter = std_multiset.lower_bound(5);
  EXPECT_EQ(*s21_iter, *std_iter);
}

TEST(TestMultiSetLookup, Test_lower_bound_3) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  auto s21_iter = s21_multiset.lower_bound(3);
  auto std_iter = std_multiset.lower_bound(3);
  EXPECT_EQ(*s21_iter, *std_iter);
}

TEST(TestMultiSetLookup, Test_upper_bound_2) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  auto s21_iter = s21_multiset.upper_bound(5);
  auto std_iter = std_multiset.upper_bound(5);
  EXPECT_EQ(*s21_iter, *std_iter);
}

TEST(TestMultiSetLookup, Test_upper_bound_3) {
  s21::multiset<int> s21_multiset = create_s21_multiset_1();
  std::multiset<int> std_multiset = create_std_multiset_1();
  auto s21_iter = s21_multiset.upper_bound(3);
  auto std_iter = std_multiset.upper_bound(3);
  EXPECT_EQ(*s21_iter, *std_iter);
}

// _____________________________________________________________________

TEST(TestMultiSetModifiers, Test_insert_many_0) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;

  s21_multiset.insert_many(5);
  std_multiset.insert(5);
  comparison_multiset(s21_multiset, std_multiset);
}

TEST(TestMultiSetModifiers, Test_insert_many_2) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset = create_std_multiset_1();

  s21_multiset.insert_many(5, 78, 564, 1, 2, 78, 65, 5);
  std_multiset.insert(5);
  comparison_multiset(s21_multiset, std_multiset);
}

TEST(TestMultiSetModifiers, Test_insert_many_3) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset = create_std_multiset_1();

  s21_multiset.insert_many(5, 78, 564, 1, 2, 78, 65, 999);
  std_multiset.insert(999);
  comparison_multiset(s21_multiset, std_multiset);
}
