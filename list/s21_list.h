#ifndef S21_LIST_H
#define S21_LIST_H

#include <iostream>

namespace s21 {
template <typename T>
class list {
 private:
  class Node;
  class ListIterator;
  class ListConstIterator;

 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;
  using size_type = size_t;

 private:
  class Node  // вложенный класс
  {
   public:
    Node* next_node_;
    Node* previous_node_;
    value_type node_value_;
    Node(value_type value = value_type(), Node* next_node = nullptr,
         Node* previous_node = nullptr);
    Node(const Node& other);
    Node(Node&& other);
    ~Node();
  };

  class ListIterator  // вложенный класс
  {
   public:
    Node* node_pointer_;

    // public:
    ListIterator();
    ListIterator(Node* node_pointer);
    ListIterator(const ListIterator& other);
    ListIterator(ListIterator&& other);
    ~ListIterator();
    iterator& operator=(ListIterator&& other);

    iterator& operator++();
    iterator& operator++(int);
    iterator& operator--();
    iterator& operator--(int);
    reference operator*();
    bool operator==(const iterator& other);
    bool operator!=(const iterator& other);
  };

  class ListConstIterator  // вложенный класс
  {
   public:
    const Node* node_pointer_;

    ListConstIterator();
    ListConstIterator(Node* node_pointer);
    ListConstIterator(const ListConstIterator& other);
    ListConstIterator(ListConstIterator&& other);
    ListConstIterator(const ListIterator& other);
    ListConstIterator(ListIterator&& other);
    ~ListConstIterator();
    const_iterator& operator=(ListConstIterator&& other);
    const_iterator& operator=(ListIterator&& other);

    const_iterator& operator++();
    const_iterator& operator++(int);
    const_iterator& operator--();
    const_iterator& operator--(int);
    const_reference operator*();
    bool operator==(const const_iterator& other);
    bool operator!=(const const_iterator& other);
  };

  // Вспомогательные функции класса
  void add_fake_node();
  void enter_node(iterator pos, Node* new_node);
  void qsortRecursive(iterator start, iterator end, int count_elements);

  // Параметры класса
  Node* start_list_;
  Node* end_list_;
  size_type list_size_;

 public:
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l);
  ~list();
  list<T>& operator=(list&& l);

  const_reference front();
  const_reference back();

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list& other);
  void merge(list& other);
  void splice(const_iterator pos, list& other);
  void reverse();
  void unique();
  void sort();

  template <class... Args>
  iterator insert_many(const_iterator pos, Args&&... args);
  template <class... Args>
  void insert_many_back(Args&&... args);
  template <class... Args>
  void insert_many_front(Args&&... args);
};
#include "s21_list.tpp"
}  // namespace s21

#endif
