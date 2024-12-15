#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <iostream>

namespace s21 {
template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

 private:
  size_t size_;
  size_t capacity_;
  T *array_values_;

  void change_size_array(size_type size);

 public:
  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();
  vector<T> &operator=(vector &&v);

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front() noexcept;
  const_reference back() noexcept;
  T *data();

  iterator begin() noexcept;
  iterator end() noexcept;

  bool empty();
  size_type size();
  size_type max_size();
  void reserve(size_type size);
  size_type capacity();
  void shrink_to_fit();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <class... Args>
  void insert_many_back(Args &&...args);
};
#include "s21_vector.tpp"
}  // namespace s21

#endif
