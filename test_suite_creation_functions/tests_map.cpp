#include "../unit_tests.h"

template <typename Key, typename T>
void comparison_map(s21::map<Key, T> s21_map, std::map<Key, T> std_map) {
  EXPECT_EQ(s21_map.size(), std_map.size());
  auto s21_iter = s21_map.begin();
  auto std_iter = std_map.begin();
  for (; s21_iter != s21_map.end() && std_iter != std_map.end();
       s21_iter++, std_iter++) {
    EXPECT_EQ((*s21_iter).first, (*std_iter).first);
    EXPECT_EQ((*s21_iter).second, (*std_iter).second);
  }
}

s21::map<int, int> create_s21_map_1() {
  s21::map<int, int> s21_map{{5, 30}, {1, 80}, {65, 60}, {6, 5},
                             {8, 65}, {2, 0},  {9, 4},   {99, 88}};
  return s21_map;
}

std::map<int, int> create_std_map_1() {
  std::map<int, int> std_map{{5, 30}, {1, 80}, {65, 60}, {6, 5},
                             {8, 65}, {2, 0},  {9, 4},   {99, 88}};
  return std_map;
}

s21::map<std::string, char> create_s21_map_2() {
  s21::map<std::string, char> s21_map{
      {"bread", 'a'}, {"milk", 'c'}, {"apple", 'b'}};
  return s21_map;
}

std::map<std::string, char> create_std_map_2() {
  std::map<std::string, char> std_map{
      {"bread", 'a'}, {"milk", 'c'}, {"apple", 'b'}};
  return std_map;
}

s21::map<int, int> create_s21_map_3() {
  s21::map<int, int> s21_map{{5, 600}, {456, 98}, {545, 11}};
  return s21_map;
}

std::map<int, int> create_std_map_3() {
  std::map<int, int> std_map{{5, 600}, {456, 98}, {545, 11}};
  return std_map;
}

TEST(TestMapCreate, Test_create_0) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;
  comparison_map(s21_map, std_map);
}

TEST(TestMapCreate, Test_create_1) {
  s21::map<std::string, char> s21_map;
  std::map<std::string, char> std_map;
  comparison_map(s21_map, std_map);
}

TEST(TestMapCreate, Test_create_2) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();
  comparison_map(s21_map, std_map);
}

TEST(TestMapCreate, Test_create_3) {
  s21::map<std::string, char> s21_map = create_s21_map_2();
  std::map<std::string, char> std_map = create_std_map_2();
  comparison_map(s21_map, std_map);
}

TEST(TestMapCreate, Test_create_4) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();
  s21::map<int, int> s21_copy_map(s21_map);
  std::map<int, int> std_copy_map(std_map);
  comparison_map(s21_map, std_map);
  comparison_map(s21_copy_map, std_copy_map);
}

TEST(TestMapCreate, Test_create_5) {
  s21::map<std::string, char> s21_map = create_s21_map_2();
  std::map<std::string, char> std_map = create_std_map_2();
  s21::map<std::string, char> s21_copy_map(s21_map);
  std::map<std::string, char> std_copy_map(std_map);
  comparison_map(s21_map, std_map);
  comparison_map(s21_copy_map, std_copy_map);
}

TEST(TestMapCreate, Test_create_6) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();
  s21::map<int, int> s21_copy_map = s21_map;
  std::map<int, int> std_copy_map = std_map;
  comparison_map(s21_map, std_map);
  comparison_map(s21_copy_map, std_copy_map);
}

TEST(TestMapCreate, Test_create_7) {
  s21::map<std::string, char> s21_map = create_s21_map_2();
  std::map<std::string, char> std_map = create_std_map_2();
  s21::map<std::string, char> s21_copy_map = s21_map;
  std::map<std::string, char> std_copy_map = std_map;
  comparison_map(s21_map, std_map);
  comparison_map(s21_copy_map, std_copy_map);
}

// _____________________________________________________________________

TEST(TestMapElement, Test_element_0) {
  s21::map<int, int> s21_map{{5, 0}, {1, 0}, {65, 0}, {6, 0},
                             {8, 0}, {2, 0}, {9, 0},  {99, 0}};
  std::map<int, int> std_map{{5, 0}, {1, 0}, {65, 0}, {6, 0},
                             {8, 0}, {2, 0}, {9, 0},  {99, 0}};

  s21_map.at(5) = 30;
  s21_map.at(1) = 80;
  s21_map.at(65) = 60;
  s21_map.at(6) = 5;
  s21_map.at(8) = 65;
  s21_map.at(2) = 0;
  s21_map.at(9) = 4;
  s21_map.at(99) = 88;

  std_map.at(5) = 30;
  std_map.at(1) = 80;
  std_map.at(65) = 60;
  std_map.at(6) = 5;
  std_map.at(8) = 65;
  std_map.at(2) = 0;
  std_map.at(9) = 4;
  std_map.at(99) = 88;

  comparison_map(s21_map, std_map);
}

TEST(TestMapElement, Test_element_1) {
  s21::map<std::string, char> s21_map{
      {"bread", 'z'}, {"milk", 'z'}, {"apple", 'z'}};
  std::map<std::string, char> std_map{
      {"bread", 'z'}, {"milk", 'z'}, {"apple", 'z'}};

  s21_map.at("bread") = 'a';
  s21_map.at("milk") = 'c';
  s21_map.at("apple") = 'b';

  std_map.at("bread") = 'a';
  std_map.at("milk") = 'c';
  std_map.at("apple") = 'b';

  comparison_map(s21_map, std_map);
}

TEST(TestMapElement, Test_element_2) {
  s21::map<int, int> s21_map{{5, 0}};
  std::map<int, int> std_map{{5, 0}};

  s21_map[5] = 30;
  s21_map[1] = 80;
  s21_map[65] = 60;
  s21_map[6] = 5;
  s21_map[8] = 65;
  s21_map[2] = 0;
  s21_map[9] = 4;
  s21_map[99] = 88;

  std_map[5] = 30;
  std_map[1] = 80;
  std_map[65] = 60;
  std_map[6] = 5;
  std_map[8] = 65;
  std_map[2] = 0;
  std_map[9] = 4;
  std_map[99] = 88;

  comparison_map(s21_map, std_map);
}

TEST(TestMapElement, Test_element_3) {
  s21::map<std::string, char> s21_map{{"bread", 'z'}};
  std::map<std::string, char> std_map{{"bread", 'z'}};

  s21_map["bread"] = 'a';
  s21_map["milk"] = 'c';
  s21_map["apple"] = 'b';

  std_map["bread"] = 'a';
  std_map["milk"] = 'c';
  std_map["apple"] = 'b';

  comparison_map(s21_map, std_map);
}

// _____________________________________________________________________

TEST(TestMapIterator, Test_iterator_4) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();
  auto s21_iter = s21_map.begin();
  auto std_iter = std_map.begin();
  EXPECT_EQ((*s21_iter).first, (*std_iter).first);
  EXPECT_EQ((*s21_iter).second, (*std_iter).second);
}

TEST(TestMapIterator, Test_iterator_5) {
  s21::map<std::string, char> s21_map = create_s21_map_2();
  std::map<std::string, char> std_map = create_std_map_2();
  auto s21_iter = s21_map.begin();
  auto std_iter = std_map.begin();
  EXPECT_EQ((*s21_iter).first, (*std_iter).first);
  EXPECT_EQ((*s21_iter).second, (*std_iter).second);
}

TEST(TestMapIterator, Test_iterator_6) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();
  auto s21_iter = s21_map.end();
  auto std_iter = std_map.end();
  s21_iter--;
  std_iter--;
  EXPECT_EQ((*s21_iter).first, (*std_iter).first);
  EXPECT_EQ((*s21_iter).second, (*std_iter).second);
}

TEST(TestMapIterator, Test_iterator_7) {
  s21::map<std::string, char> s21_map = create_s21_map_2();
  std::map<std::string, char> std_map = create_std_map_2();
  auto s21_iter = s21_map.end();
  auto std_iter = std_map.end();
  s21_iter--;
  std_iter--;
  EXPECT_EQ((*s21_iter).first, (*std_iter).first);
  EXPECT_EQ((*s21_iter).second, (*std_iter).second);
}

// _____________________________________________________________________

TEST(TestMapCapacity, Test_capacity_0) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;
  EXPECT_EQ(s21_map.empty(), std_map.empty());
}

TEST(TestMapCapacity, Test_capacity_1) {
  s21::map<std::string, char> s21_map;
  std::map<std::string, char> std_map;
  EXPECT_EQ(s21_map.empty(), std_map.empty());
}

TEST(TestMapCapacity, Test_capacity_2) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;
  EXPECT_EQ(s21_map.size(), std_map.size());
}

TEST(TestMapCapacity, Test_capacity_3) {
  s21::map<std::string, char> s21_map;
  std::map<std::string, char> std_map;
  EXPECT_EQ(s21_map.size(), std_map.size());
}

TEST(TestMapCapacity, Test_capacity_6) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();
  EXPECT_EQ(s21_map.empty(), std_map.empty());
}

TEST(TestMapCapacity, Test_capacity_7) {
  s21::map<std::string, char> s21_map = create_s21_map_2();
  std::map<std::string, char> std_map = create_std_map_2();
  EXPECT_EQ(s21_map.empty(), std_map.empty());
}

TEST(TestMapCapacity, Test_capacity_8) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();
  EXPECT_EQ(s21_map.size(), std_map.size());
}

TEST(TestMapCapacity, Test_capacity_9) {
  s21::map<std::string, char> s21_map = create_s21_map_2();
  std::map<std::string, char> std_map = create_std_map_2();
  EXPECT_EQ(s21_map.size(), std_map.size());
}

// _____________________________________________________________________

TEST(TestMapModifiers, Test_clear_0) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;
  s21_map.clear();
  std_map.clear();
  comparison_map(s21_map, std_map);
}

TEST(TestMapModifiers, Test_clear_1) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();
  s21_map.clear();
  std_map.clear();
  comparison_map(s21_map, std_map);
}

// _____________________________________________________________________

TEST(TestMapModifiers, Test_insert_0) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;

  s21::pair<int, int> p1(100, 900);
  std::pair<int, int> p2(100, 900);

  s21_map.insert(p1);
  std_map.insert(p2);
  comparison_map(s21_map, std_map);
}

TEST(TestMapModifiers, Test_insert_1) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;

  s21_map.insert(100, 900);
  std::pair<int, int> p2(100, 900);
  std_map.insert(p2);

  comparison_map(s21_map, std_map);
}

TEST(TestMapModifiers, Test_insert_2) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;

  s21_map.insert_or_assign(100, 900);
  std_map.insert_or_assign(100, 900);

  comparison_map(s21_map, std_map);
}

TEST(TestMapModifiers, Test_insert_3) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();

  s21::pair<int, int> p1(100, 900);
  std::pair<int, int> p2(100, 900);

  s21_map.insert(p1);
  std_map.insert(p2);
  comparison_map(s21_map, std_map);
}

TEST(TestMapModifiers, Test_insert_4) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();

  s21_map.insert(100, 900);
  std::pair<int, int> p2(100, 900);
  std_map.insert(p2);

  comparison_map(s21_map, std_map);
}

TEST(TestMapModifiers, Test_insert_5) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();

  s21_map.insert_or_assign(100, 900);
  std_map.insert_or_assign(100, 900);

  comparison_map(s21_map, std_map);
}

TEST(TestMapModifiers, Test_insert_6) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();

  s21::pair<int, int> p1(5, 15);
  std::pair<int, int> p2(5, 15);

  s21_map.insert(p1);
  std_map.insert(p2);
  comparison_map(s21_map, std_map);
}

TEST(TestMapModifiers, Test_insert_7) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();

  s21_map.insert(5, 15);
  std::pair<int, int> p2(5, 15);
  std_map.insert(p2);

  comparison_map(s21_map, std_map);
}

TEST(TestMapModifiers, Test_insert_8) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();

  s21_map.insert_or_assign(5, 15);
  std_map.insert_or_assign(5, 15);

  comparison_map(s21_map, std_map);
}

// _____________________________________________________________________

TEST(TestMapModifiers, Test_erase_1) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();
  s21_map.erase(s21_map.begin());
  std_map.erase(std_map.begin());
  comparison_map(s21_map, std_map);
}

TEST(TestMapModifiers, Test_erase_2) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();

  auto s21_iter = s21_map.begin();
  auto std_iter = std_map.begin();
  s21_iter++;
  std_iter++;

  s21_map.erase(s21_iter);
  std_map.erase(std_iter);

  comparison_map(s21_map, std_map);
}

// _____________________________________________________________________

TEST(TestMapModifiers, Test_swap_0) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;
  s21::map<int, int> s21_map1;
  std::map<int, int> std_map1;
  s21_map.swap(s21_map1);
  std_map.swap(std_map1);
  comparison_map(s21_map, std_map);
  comparison_map(s21_map1, std_map1);
}

TEST(TestMapModifiers, Test_swap_1) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();
  s21::map<int, int> s21_map1 = create_s21_map_3();
  std::map<int, int> std_map1 = create_std_map_3();
  s21_map.swap(s21_map1);
  std_map.swap(std_map1);
  comparison_map(s21_map, std_map);
  comparison_map(s21_map1, std_map1);
}

// _____________________________________________________________________

TEST(TestMapModifiers, Test_merge_0) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;
  s21::map<int, int> s21_map1;
  std::map<int, int> std_map1;
  s21_map.merge(s21_map1);
  std_map.merge(std_map1);
  comparison_map(s21_map, std_map);
  comparison_map(s21_map1, std_map1);
}

TEST(TestMapModifiers, Test_merge_1) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();
  s21::map<int, int> s21_map1 = create_s21_map_3();
  std::map<int, int> std_map1 = create_std_map_3();
  s21_map.merge(s21_map1);
  std_map.merge(std_map1);
  comparison_map(s21_map, std_map);
  comparison_map(s21_map1, std_map1);
}

// _____________________________________________________________________

TEST(TestMapLookup, Test_contains_0) {
  s21::map<int, int> s21_map;
  EXPECT_EQ(s21_map.contains(15), false);
}

TEST(TestMapLookup, Test_contains_1) {
  s21::map<int, int> s21_map = create_s21_map_1();
  EXPECT_EQ(s21_map.contains(15), false);
}

TEST(TestMapLookup, Test_contains_2) {
  s21::map<int, int> s21_map = create_s21_map_1();
  EXPECT_EQ(s21_map.contains(65), true);
}

// _____________________________________________________________________

TEST(TestMapModifiers, Test_insert_many_0) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;

  s21::pair<int, int> p1(100, 900);
  std::pair<int, int> p2(100, 900);

  s21_map.insert_many(p1);
  std_map.insert(p2);
  comparison_map(s21_map, std_map);
}

TEST(TestMapModifiers, Test_insert_many_1) {
  s21::map<int, int> s21_map = create_s21_map_1();
  std::map<int, int> std_map = create_std_map_1();

  s21::pair<int, int> p1(100, 900);
  std::pair<int, int> p2(100, 900);
  s21::pair<int, int> p1_2(90, 15);
  std::pair<int, int> p2_2(90, 15);

  s21_map.insert_many(p1, p1_2);
  std_map.insert(p2);
  std_map.insert(p2_2);
  comparison_map(s21_map, std_map);
}

TEST(TestMapModifiers, Test_insert_many_2) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map = create_std_map_1();

  s21::pair<int, int> p1(5, 30);
  s21::pair<int, int> p2(1, 80);
  s21::pair<int, int> p3(65, 60);
  s21::pair<int, int> p4(6, 5);
  s21::pair<int, int> p5(8, 65);
  s21::pair<int, int> p6(2, 0);
  s21::pair<int, int> p7(9, 4);
  s21::pair<int, int> p8(99, 88);

  s21_map.insert_many(p1, p2, p3, p4, p5, p6, p7, p8);
  comparison_map(s21_map, std_map);
}