#include "../unit_tests.h"

template <typename T, std::size_t N>
void comparison_array(s21::array<T, N> s21_array, std::array<T, N> std_array) {
  EXPECT_EQ(s21_array.size(), std_array.size());
  auto s21_iter = s21_array.begin();
  auto std_iter = std_array.begin();
  for (; s21_iter != s21_array.end() && std_iter != std_array.end();
       s21_iter++, std_iter++) {
    EXPECT_EQ(*s21_iter, *std_iter);
  }
}

s21::array<int, 4> create_s21_array_1() {
  s21::array<int, 4> s21_array{1, 2, 4, 5};
  return s21_array;
}

std::array<int, 4> create_std_array_1() {
  std::array<int, 4> std_array{1, 2, 4, 5};
  return std_array;
}

s21::array<char, 4> create_s21_array_2() {
  s21::array<char, 4> s21_array{'1', '2', '4', '5'};
  return s21_array;
}

std::array<char, 4> create_std_array_2() {
  std::array<char, 4> std_array{'1', '2', '4', '5'};
  return std_array;
}

TEST(TestarrayCreate, Test_create_0) {
  s21::array<int, 4> s21_array;
  std::array<int, 4> std_array;
  EXPECT_EQ(s21_array.size(), std_array.size());
}

TEST(TestarrayCreate, Test_create_1) {
  s21::array<char, 4> s21_array;
  std::array<char, 4> std_array;
  EXPECT_EQ(s21_array.size(), std_array.size());
}

TEST(TestarrayCreate, Test_create_2) {
  s21::array<int, 4> s21_array = create_s21_array_1();
  std::array<int, 4> std_array = create_std_array_1();
  comparison_array(s21_array, std_array);
}

TEST(TestarrayCreate, Test_create_3) {
  s21::array<char, 4> s21_array = create_s21_array_2();
  std::array<char, 4> std_array = create_std_array_2();
  comparison_array(s21_array, std_array);
}

TEST(TestarrayCreate, Test_create_4) {
  s21::array<int, 4> s21_array = create_s21_array_1();
  std::array<int, 4> std_array = create_std_array_1();
  s21::array<int, 4> s21_copy_array(s21_array);
  std::array<int, 4> std_copy_array(std_array);
  comparison_array(s21_array, std_array);
  comparison_array(s21_copy_array, std_copy_array);
}

TEST(TestarrayCreate, Test_create_5) {
  s21::array<char, 4> s21_array = create_s21_array_2();
  std::array<char, 4> std_array = create_std_array_2();
  s21::array<char, 4> s21_copy_array(s21_array);
  std::array<char, 4> std_copy_array(std_array);
  comparison_array(s21_array, std_array);
  comparison_array(s21_copy_array, std_copy_array);
}

TEST(TestarrayCreate, Test_create_6) {
  s21::array<int, 4> s21_array = create_s21_array_1();
  std::array<int, 4> std_array = create_std_array_1();
  s21::array<int, 4> s21_copy_array = s21_array;
  std::array<int, 4> std_copy_array = std_array;
  comparison_array(s21_array, std_array);
  comparison_array(s21_copy_array, std_copy_array);
}

TEST(TestarrayCreate, Test_create_7) {
  s21::array<char, 4> s21_array = create_s21_array_2();
  std::array<char, 4> std_array = create_std_array_2();
  s21::array<char, 4> s21_copy_array(s21_array);
  std::array<char, 4> std_copy_array(std_array);
  comparison_array(s21_array, std_array);
  comparison_array(s21_copy_array, std_copy_array);
}

// // // _____________________________________________________________________

TEST(TestarrayElement, Test_element_0) {
  s21::array<int, 4> s21_array = create_s21_array_1();
  std::array<int, 4> std_array = create_std_array_1();
  EXPECT_EQ(s21_array.front(), std_array.front());
}

TEST(TestarrayElement, Test_element_1) {
  s21::array<char, 4> s21_array = create_s21_array_2();
  std::array<char, 4> std_array = create_std_array_2();
  EXPECT_EQ(s21_array.front(), std_array.front());
}

TEST(TestarrayElement, Test_element_2) {
  s21::array<int, 4> s21_array = create_s21_array_1();
  std::array<int, 4> std_array = create_std_array_1();
  EXPECT_EQ(s21_array.back(), std_array.back());
}

TEST(TestarrayElement, Test_element_3) {
  s21::array<char, 4> s21_array = create_s21_array_2();
  std::array<char, 4> std_array = create_std_array_2();
  EXPECT_EQ(s21_array.back(), std_array.back());
}

TEST(TestarrayElement, Test_element_4) {
  s21::array<int, 4> s21_array = create_s21_array_1();
  std::array<int, 4> std_array = create_std_array_1();
  EXPECT_EQ(s21_array.at(1), std_array.at(1));
}

TEST(TestarrayElement, Test_element_5) {
  s21::array<char, 4> s21_array = create_s21_array_2();
  std::array<char, 4> std_array = create_std_array_2();
  EXPECT_EQ(s21_array.at(1), std_array.at(1));
}

TEST(TestarrayElement, Test_element_6) {
  s21::array<int, 4> s21_array = create_s21_array_1();
  std::array<int, 4> std_array = create_std_array_1();
  EXPECT_EQ(s21_array[1], std_array[1]);
}

TEST(TestarrayElement, Test_element_7) {
  s21::array<char, 4> s21_array = create_s21_array_2();
  std::array<char, 4> std_array = create_std_array_2();
  EXPECT_EQ(s21_array[1], std_array[1]);
}

TEST(TestarrayElement, Test_element_8) {
  s21::array<int, 4> s21_array = create_s21_array_1();
  std::array<int, 4> std_array = create_std_array_1();

  EXPECT_EQ(s21_array.size(), std_array.size());
  int* s21_data = s21_array.data();
  int* std_data = std_array.data();
  for (size_t i = 0; i < s21_array.size(); i++) {
    EXPECT_EQ(s21_data[i], std_data[i]);
  }
}

TEST(TestarrayElement, Test_element_9) {
  s21::array<char, 4> s21_array = create_s21_array_2();
  std::array<char, 4> std_array = create_std_array_2();

  EXPECT_EQ(s21_array.size(), std_array.size());
  char* s21_data = s21_array.data();
  char* std_data = std_array.data();
  for (size_t i = 0; i < s21_array.size(); i++) {
    EXPECT_EQ(s21_data[i], std_data[i]);
  }
}

// // // _____________________________________________________________________

TEST(TestarrayIterator, Test_iterator_0) {
  s21::array<int, 4> s21_array = create_s21_array_1();
  std::array<int, 4> std_array = create_std_array_1();
  EXPECT_EQ(*(s21_array.begin()), *(std_array.begin()));
}

TEST(TestarrayIterator, Test_iterator_1) {
  s21::array<char, 4> s21_array = create_s21_array_2();
  std::array<char, 4> std_array = create_std_array_2();
  EXPECT_EQ(*(s21_array.begin()), *(std_array.begin()));
}

// // // _____________________________________________________________________

TEST(TestarrayCapacity, Test_capacity_0) {
  s21::array<int, 4> s21_array;
  std::array<int, 4> std_array;
  EXPECT_EQ(s21_array.empty(), std_array.empty());
}

TEST(TestarrayCapacity, Test_capacity_1) {
  s21::array<char, 4> s21_array;
  std::array<char, 4> std_array;
  EXPECT_EQ(s21_array.empty(), std_array.empty());
}

TEST(TestarrayCapacity, Test_capacity_2) {
  s21::array<int, 4> s21_array;
  std::array<int, 4> std_array;
  EXPECT_EQ(s21_array.size(), std_array.size());
}

TEST(TestarrayCapacity, Test_capacity_3) {
  s21::array<char, 4> s21_array;
  std::array<char, 4> std_array;
  EXPECT_EQ(s21_array.size(), std_array.size());
}

TEST(TestarrayCapacity, Test_capacity_4) {
  s21::array<int, 4> s21_array = create_s21_array_1();
  std::array<int, 4> std_array = create_std_array_1();
  EXPECT_EQ(s21_array.empty(), std_array.empty());
}

TEST(TestarrayCapacity, Test_capacity_5) {
  s21::array<char, 4> s21_array = create_s21_array_2();
  std::array<char, 4> std_array = create_std_array_2();
  EXPECT_EQ(s21_array.empty(), std_array.empty());
}

TEST(TestarrayCapacity, Test_capacity_6) {
  s21::array<int, 4> s21_array = create_s21_array_1();
  std::array<int, 4> std_array = create_std_array_1();
  EXPECT_EQ(s21_array.size(), std_array.size());
}

TEST(TestarrayCapacity, Test_capacity_7) {
  s21::array<char, 4> s21_array = create_s21_array_2();
  std::array<char, 4> std_array = create_std_array_2();
  EXPECT_EQ(s21_array.size(), std_array.size());
}

// // // _____________________________________________________________________

TEST(TestarrayModifiers, Test_swap_0) {
  s21::array<int, 4> s21_array = create_s21_array_1();
  s21::array<int, 4> s21_array1{8, 13};
  std::array<int, 4> std_array = create_std_array_1();
  std::array<int, 4> std_array1{8, 13};
  s21_array.swap(s21_array1);
  std_array.swap(std_array1);
  comparison_array(s21_array, std_array);
  comparison_array(s21_array1, std_array1);
}

TEST(TestarrayModifiers, Test_swap_1) {
  s21::array<int, 4> s21_array = create_s21_array_1();
  s21::array<int, 4> s21_array1{9, 18, 3, 5};
  std::array<int, 4> std_array = create_std_array_1();
  std::array<int, 4> std_array1{9, 18, 3, 5};
  s21_array.swap(s21_array1);
  std_array.swap(std_array1);
  comparison_array(s21_array, std_array);
  comparison_array(s21_array1, std_array1);
}

TEST(TestarrayModifiers, Test_fill_0) {
  s21::array<int, 4> s21_array = create_s21_array_1();
  std::array<int, 4> std_array = create_std_array_1();
  s21_array.fill(555);
  std_array.fill(555);
  comparison_array(s21_array, std_array);
}

TEST(TestarrayModifiers, Test_fill_1) {
  s21::array<char, 4> s21_array = create_s21_array_2();
  std::array<char, 4> std_array = create_std_array_2();
  s21_array.fill('a');
  std_array.fill('a');
  comparison_array(s21_array, std_array);
}
