#ifndef S21_ARRAY_H
#define S21_ARRAY_H

#include <iostream>

namespace s21 {
template <typename T, std::size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

 private:
  size_t size_ = N;
  T *array_values_;

 public:
  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a);
  ~array() = default;
  array<T, N> &operator=(array &&a);

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front() noexcept;
  const_reference back() noexcept;
  iterator data();

  iterator begin() noexcept;
  iterator end() noexcept;

  bool empty();
  size_type size();
  size_type max_size();

  void swap(array &other);
  void fill(const_reference value);
};
#include "s21_array.tpp"
}  // namespace s21

#endif
