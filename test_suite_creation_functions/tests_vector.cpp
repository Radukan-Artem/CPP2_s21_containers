#include "../unit_tests.h"

template <typename T>
void comparison_vector(s21::vector<T> s21_vector, std::vector<T> std_vector) {
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  auto s21_iter = s21_vector.begin();
  auto std_iter = std_vector.begin();
  for (; s21_iter != s21_vector.end() && std_iter != std_vector.end();
       s21_iter++, std_iter++) {
    EXPECT_EQ(*s21_iter, *std_iter);
  }
}

s21::vector<int> create_s21_vector_1() {
  s21::vector<int> s21_vector{1, 2, 4, 5};
  return s21_vector;
}

std::vector<int> create_std_vector_1() {
  std::vector<int> std_vector{1, 2, 4, 5};
  return std_vector;
}

s21::vector<char> create_s21_vector_2() {
  s21::vector<char> s21_vector{'1', '2', '4', '5'};
  return s21_vector;
}

std::vector<char> create_std_vector_2() {
  std::vector<char> std_vector{'1', '2', '4', '5'};
  return std_vector;
}

TEST(TestvectorCreate, Test_create_0) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorCreate, Test_create_1) {
  s21::vector<char> s21_vector;
  std::vector<char> std_vector;
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorCreate, Test_create_2) {
  s21::vector<int> s21_vector(3);
  std::vector<int> std_vector(3);
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorCreate, Test_create_3) {
  s21::vector<char> s21_vector(3);
  std::vector<char> std_vector(3);
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorCreate, Test_create_4) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorCreate, Test_create_5) {
  s21::vector<char> s21_vector = create_s21_vector_2();
  std::vector<char> std_vector = create_std_vector_2();
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorCreate, Test_create_6) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  s21::vector<int> s21_copy_vector(s21_vector);
  std::vector<int> std_copy_vector(std_vector);
  comparison_vector(s21_vector, std_vector);
  comparison_vector(s21_copy_vector, std_copy_vector);
}

TEST(TestvectorCreate, Test_create_7) {
  s21::vector<char> s21_vector = create_s21_vector_2();
  std::vector<char> std_vector = create_std_vector_2();
  s21::vector<char> s21_copy_vector(s21_vector);
  std::vector<char> std_copy_vector(std_vector);
  comparison_vector(s21_vector, std_vector);
  comparison_vector(s21_copy_vector, std_copy_vector);
}

TEST(TestvectorCreate, Test_create_8) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  s21::vector<int> s21_copy_vector = s21_vector;
  std::vector<int> std_copy_vector = std_vector;
  comparison_vector(s21_vector, std_vector);
  comparison_vector(s21_copy_vector, std_copy_vector);
}

TEST(TestvectorCreate, Test_create_9) {
  s21::vector<char> s21_vector = create_s21_vector_2();
  std::vector<char> std_vector = create_std_vector_2();
  s21::vector<char> s21_copy_vector(s21_vector);
  std::vector<char> std_copy_vector(std_vector);
  comparison_vector(s21_vector, std_vector);
  comparison_vector(s21_copy_vector, std_copy_vector);
}

// // _____________________________________________________________________

TEST(TestvectorElement, Test_element_0) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  EXPECT_EQ(s21_vector.front(), std_vector.front());
}

TEST(TestvectorElement, Test_element_1) {
  s21::vector<char> s21_vector = create_s21_vector_2();
  std::vector<char> std_vector = create_std_vector_2();
  EXPECT_EQ(s21_vector.front(), std_vector.front());
}

TEST(TestvectorElement, Test_element_2) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  EXPECT_EQ(s21_vector.back(), std_vector.back());
}

TEST(TestvectorElement, Test_element_3) {
  s21::vector<char> s21_vector = create_s21_vector_2();
  std::vector<char> std_vector = create_std_vector_2();
  EXPECT_EQ(s21_vector.back(), std_vector.back());
}

TEST(TestvectorElement, Test_element_4) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
}

TEST(TestvectorElement, Test_element_5) {
  s21::vector<char> s21_vector = create_s21_vector_2();
  std::vector<char> std_vector = create_std_vector_2();
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
}

TEST(TestvectorElement, Test_element_6) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  EXPECT_EQ(s21_vector[1], std_vector[1]);
}

TEST(TestvectorElement, Test_element_7) {
  s21::vector<char> s21_vector = create_s21_vector_2();
  std::vector<char> std_vector = create_std_vector_2();
  EXPECT_EQ(s21_vector[1], std_vector[1]);
}

TEST(TestvectorElement, Test_element_8) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();

  EXPECT_EQ(s21_vector.size(), std_vector.size());
  int* s21_data = s21_vector.data();
  int* std_data = std_vector.data();
  for (size_t i = 0; i < s21_vector.size(); i++) {
    EXPECT_EQ(s21_data[i], std_data[i]);
  }
}

TEST(TestvectorElement, Test_element_9) {
  s21::vector<char> s21_vector = create_s21_vector_2();
  std::vector<char> std_vector = create_std_vector_2();

  EXPECT_EQ(s21_vector.size(), std_vector.size());
  char* s21_data = s21_vector.data();
  char* std_data = std_vector.data();
  for (size_t i = 0; i < s21_vector.size(); i++) {
    EXPECT_EQ(s21_data[i], std_data[i]);
  }
}

// // _____________________________________________________________________

TEST(TestvectorIterator, Test_iterator_0) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  EXPECT_EQ(*(s21_vector.begin()), *(std_vector.begin()));
}

TEST(TestvectorIterator, Test_iterator_1) {
  s21::vector<char> s21_vector = create_s21_vector_2();
  std::vector<char> std_vector = create_std_vector_2();
  EXPECT_EQ(*(s21_vector.begin()), *(std_vector.begin()));
}

// // _____________________________________________________________________

TEST(TestvectorCapacity, Test_capacity_0) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(TestvectorCapacity, Test_capacity_1) {
  s21::vector<char> s21_vector;
  std::vector<char> std_vector;
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(TestvectorCapacity, Test_capacity_2) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(TestvectorCapacity, Test_capacity_3) {
  s21::vector<char> s21_vector;
  std::vector<char> std_vector;
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(TestvectorCapacity, Test_capacity_4) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(TestvectorCapacity, Test_capacity_5) {
  s21::vector<char> s21_vector = create_s21_vector_2();
  std::vector<char> std_vector = create_std_vector_2();
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(TestvectorCapacity, Test_capacity_6) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(TestvectorCapacity, Test_capacity_7) {
  s21::vector<char> s21_vector = create_s21_vector_2();
  std::vector<char> std_vector = create_std_vector_2();
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(TestvectorCapacity, Test_capacity_8) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  s21_vector.reserve(50);
  std_vector.reserve(50);
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorCapacity, Test_capacity_9) {
  s21::vector<char> s21_vector = create_s21_vector_2();
  std::vector<char> std_vector = create_std_vector_2();
  s21_vector.reserve(50);
  std_vector.reserve(50);
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorCapacity, Test_capacity_10) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  s21_vector.reserve(50);
  std_vector.reserve(50);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorCapacity, Test_capacity_11) {
  s21::vector<char> s21_vector = create_s21_vector_2();
  std::vector<char> std_vector = create_std_vector_2();
  s21_vector.reserve(50);
  std_vector.reserve(50);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  comparison_vector(s21_vector, std_vector);
}

// // _____________________________________________________________________

TEST(TestvectorModifiers, Test_clear_0) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  s21_vector.clear();
  std_vector.clear();
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorModifiers, Test_clear_1) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  s21_vector.clear();
  std_vector.clear();
  comparison_vector(s21_vector, std_vector);
}

// // _____________________________________________________________________

TEST(TestvectorModifiers, Test_insert_0) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  s21_vector.insert(s21_vector.begin(), 15);
  std_vector.insert(std_vector.begin(), 15);
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorModifiers, Test_insert_1) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  s21_vector.insert(s21_vector.begin(), 15);
  std_vector.insert(std_vector.begin(), 15);
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorModifiers, Test_insert_2) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  s21_vector.insert(s21_vector.end(), 15);
  std_vector.insert(std_vector.end(), 15);
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorModifiers, Test_insert_3) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();

  auto s21_iter = s21_vector.begin();
  auto std_iter = std_vector.begin();

  s21_iter = s21_vector.insert(s21_iter, 15);
  std_iter = std_vector.insert(std_iter, 15);
  s21_vector.insert(s21_iter, 20);
  std_vector.insert(std_iter, 20);

  s21_iter = s21_vector.begin();
  std_iter = std_vector.begin();
  s21_vector.insert(s21_iter, 25);
  std_vector.insert(std_iter, 25);

  comparison_vector(s21_vector, std_vector);
}

// // _____________________________________________________________________

TEST(TestvectorModifiers, Test_erase_1) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  s21_vector.erase(s21_vector.begin());
  std_vector.erase(std_vector.begin());
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorModifiers, Test_erase_2) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();

  auto s21_iter = s21_vector.begin();
  auto std_iter = std_vector.begin();
  s21_iter++;
  std_iter++;

  s21_vector.erase(s21_iter);
  std_vector.erase(std_iter);

  comparison_vector(s21_vector, std_vector);
}

// // _____________________________________________________________________

TEST(TestvectorModifiers, Test_push_back_0) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  s21_vector.push_back(15);
  std_vector.push_back(15);
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorModifiers, Test_push_back_1) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  s21_vector.push_back(15);
  std_vector.push_back(15);
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorModifiers, Test_push_back_2) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  s21_vector.push_back(15);
  std_vector.push_back(15);
  s21_vector.push_back(15);
  std_vector.push_back(15);

  comparison_vector(s21_vector, std_vector);
}

// // _____________________________________________________________________

TEST(TestvectorModifiers, Test_pop_back_1) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  s21_vector.pop_back();
  std_vector.pop_back();
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorModifiers, Test_pop_back_2) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  std::vector<int> std_vector = create_std_vector_1();
  s21_vector.pop_back();
  std_vector.pop_back();
  s21_vector.pop_back();
  std_vector.pop_back();

  comparison_vector(s21_vector, std_vector);
}

// // _____________________________________________________________________

TEST(TestvectorModifiers, Test_swap_0) {
  s21::vector<int> s21_vector;
  s21::vector<int> s21_vector1;
  std::vector<int> std_vector;
  std::vector<int> std_vector1;
  s21_vector.swap(s21_vector1);
  std_vector.swap(std_vector1);
  comparison_vector(s21_vector, std_vector);
  comparison_vector(s21_vector1, std_vector1);
}

TEST(TestvectorModifiers, Test_swap_1) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  s21::vector<int> s21_vector1{8, 13};
  std::vector<int> std_vector = create_std_vector_1();
  std::vector<int> std_vector1{8, 13};
  s21_vector.swap(s21_vector1);
  std_vector.swap(std_vector1);
  comparison_vector(s21_vector, std_vector);
  comparison_vector(s21_vector1, std_vector1);
}

TEST(TestvectorModifiers, Test_swap_2) {
  s21::vector<int> s21_vector = create_s21_vector_1();
  s21::vector<int> s21_vector1{9, 18, 3, 5};
  std::vector<int> std_vector = create_std_vector_1();
  std::vector<int> std_vector1{9, 18, 3, 5};
  s21_vector.swap(s21_vector1);
  std_vector.swap(std_vector1);
  comparison_vector(s21_vector, std_vector);
  comparison_vector(s21_vector1, std_vector1);
}
// // _____________________________________________________________________

TEST(TestvectorModifiers, Test_insert_many_0) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector{1, 2, 4, 5, 8, 13};
  s21_vector.insert_many(s21_vector.begin(), 1, 2, 4, 5, 8, 13);
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorModifiers, Test_insert_many_1) {
  s21::vector<int> s21_vector{1, 2, 13};
  std::vector<int> std_vector{1, 2, 4, 5, 8, 13};
  auto iter = s21_vector.begin();
  iter++;
  iter++;
  s21_vector.insert_many(iter, 4, 5, 8);
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorModifiers, Test_insert_many_back_0) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector{1, 2, 4, 5, 8, 13};
  s21_vector.insert_many_back(1, 2, 4, 5, 8, 13);
  comparison_vector(s21_vector, std_vector);
}

TEST(TestvectorModifiers, Test_insert_many_back_1) {
  s21::vector<int> s21_vector{1, 2};
  std::vector<int> std_vector{1, 2, 4, 5, 8, 13};
  s21_vector.insert_many_back(4, 5, 8, 13);
  comparison_vector(s21_vector, std_vector);
}