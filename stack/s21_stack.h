#ifndef S21_STACK_H
#define S21_STACK_H

#include <iostream>

namespace s21 {
template <typename T>
class stack {
 private:
  class Node;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 private:
  class Node  // вложенный класс
  {
   public:
    Node *previous_node_;
    value_type node_value_;
    Node(value_type value = value_type(), Node *previous_node = nullptr);
    Node(const Node &other);
    Node(Node &&other);
    ~Node();
  };

  // Вспомогательные функции класса
  void clear();

  // Параметры класса
  Node *start_stack_;
  Node *end_stack_;
  size_type stack_size_;

 public:
  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s);
  ~stack();
  stack<T> &operator=(stack &&s);

  const_reference top();

  bool empty();
  size_type size();

  void push(const_reference value);
  void pop();
  void swap(stack &other);

  template <class... Args>
  void insert_many_front(Args &&...args);
};
#include "s21_stack.tpp"
}  // namespace s21

#endif
