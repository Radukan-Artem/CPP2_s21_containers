#ifndef S21_PAIR_H
#define S21_PAIR_H

#include <iostream>

namespace s21 {
template <typename Key, typename T>
class pair {
 public:
  Key first;
  T second;

  pair(Key first = Key(), T second = T());
  pair(const pair& p) = default;
  pair(pair&& p) = default;
  ~pair();
  pair<Key, T>& operator=(pair& m);
  pair<Key, T>& operator=(pair&& m);

  bool operator<(const pair& other);
  bool operator<=(const pair& other);
  bool operator>(const pair& other);
  bool operator>=(const pair& other);
  bool operator==(const pair& other);
  bool operator!=(const pair& other);
};
#include "s21_pair.tpp"
}  // namespace s21

#endif
