#ifndef S21_MAP_H
#define S21_MAP_H

#include <iostream>

#include "../red_black_tree/s21_red_black_tree.h"
#include "s21_pair.h"

namespace s21 {
template <typename Key, typename T>
class map : public red_black_tree<s21::pair<Key, T>> {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = s21::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = typename red_black_tree<value_type>::iterator;
  using const_iterator = typename red_black_tree<value_type>::const_iterator;
  using size_type = size_t;

  map();
  map(std::initializer_list<value_type> const& items);
  map(const map& m);
  map(map&& m);
  ~map();
  map<Key, T>& operator=(map&& m);

  T& at(const Key& key);
  T& operator[](const Key& key);

  std::pair<typename s21::red_black_tree<s21::pair<Key, T>>::iterator, bool>
  insert(const s21::pair<key_type, mapped_type>& value);
  std::pair<typename s21::red_black_tree<s21::pair<Key, T>>::iterator, bool>
  insert(const Key& key, const T& obj);
  std::pair<typename s21::red_black_tree<s21::pair<Key, T>>::iterator, bool>
  insert_or_assign(const Key& key, const T& obj);

  template <class... Args>
  std::vector<std::pair<
      typename s21::red_black_tree<s21::pair<Key, T>>::iterator, bool>>
  insert_many(Args&&... args);
};
#include "s21_map.tpp"
}  // namespace s21

#endif
