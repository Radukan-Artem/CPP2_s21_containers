#ifndef S21_MULTISET_H
#define S21_MULTISET_H

#include <iostream>

#include "../red_black_tree/s21_red_black_tree.h"

namespace s21 {
template <typename Key>
class multiset : public red_black_tree<Key> {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = typename red_black_tree<value_type>::iterator;
  using const_iterator = typename red_black_tree<value_type>::const_iterator;
  using size_type = size_t;

  multiset();
  multiset(std::initializer_list<value_type> const& items);
  multiset(const multiset& m);
  multiset(multiset&& m);
  ~multiset();
  multiset<Key>& operator=(multiset&& m);

  typename s21::red_black_tree<Key>::iterator insert(const value_type& value);
  void merge(multiset& other);

  size_type count(const Key& key);
  iterator find(const Key& key);
  std::pair<iterator, iterator> equal_range(const Key& key);
  iterator lower_bound(const Key& key);
  iterator upper_bound(const Key& key);

  template <class... Args>
  std::vector<std::pair<typename s21::red_black_tree<Key>::iterator, bool>>
  insert_many(Args&&... args);

 private:
  std::pair<iterator, bool> insert_or_assign(const value_type& value);
};
#include "s21_multiset.tpp"
}  // namespace s21

#endif
