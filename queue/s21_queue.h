#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include <iostream>

namespace s21 {
template <typename T>
class queue {
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
    Node *next_node_;
    value_type node_value_;
    Node(value_type value = value_type(), Node *next_node = nullptr);
    Node(const Node &other);
    Node(Node &&other);
    ~Node();
  };

  // Вспомогательные функции класса
  void clear();

  // Параметры класса
  Node *start_queue_;
  Node *end_queue_;
  size_type queue_size_;

 public:
  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);
  ~queue();
  queue<T> &operator=(queue &&q);

  const_reference front();
  const_reference back();

  bool empty();
  size_type size();

  void push(const_reference value);
  void pop();
  void swap(queue &other);

  template <class... Args>
  void insert_many_back(Args &&...args);
};
#include "s21_queue.tpp"
}  // namespace s21

#endif
