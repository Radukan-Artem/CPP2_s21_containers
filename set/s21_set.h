#ifndef S21_SET_H
#define S21_SET_H

#include <iostream>

#include "../red_black_tree/s21_red_black_tree.h"

namespace s21 {
template <typename Key>
class set : public red_black_tree<Key> {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename red_black_tree<value_type>::iterator;
  using const_iterator = typename red_black_tree<value_type>::const_iterator;
  using size_type = size_t;

  set();
  set(std::initializer_list<value_type> const &items);
  set(const set &m);
  set(set &&m);
  ~set();
  set<Key> &operator=(set &&m);

  iterator find(const Key &key);

  template <class... Args>
  std::vector<std::pair<typename s21::red_black_tree<Key>::iterator, bool>>
  insert_many(Args &&...args);

 private:
  std::pair<iterator, bool> insert_or_assign(const value_type &value);
};
#include "s21_set.tpp"
}  // namespace s21

#endif
