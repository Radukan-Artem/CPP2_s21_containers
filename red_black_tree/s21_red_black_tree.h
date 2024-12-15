#ifndef S21_RED_BLACK_TREE_H
#define S21_RED_BLACK_TREE_H

#include <iostream>

namespace s21 {
template <typename T>
class red_black_tree {
 protected:
  class Node;

  class TreeIterator;
  class TreeConstIterator;

 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = TreeIterator;
  using const_iterator = TreeConstIterator;
  using size_type = size_t;

 private:
  // Вспомогательные функции класса
  red_black_tree<T>& move(red_black_tree&& m);
  void balancing(Node* father);
  void rotate_tree(Node* father, Node* grandfather, Node* son);
  void replace_father_grandfather(Node* father, Node* grandfather,
                                  bool father_is_left);
  void delete_red_node_with_0_children(iterator pos);
  void delete_node_with_2_children(iterator pos);
  void delete_black_node_with_1_children(iterator pos);
  void delete_black_node_with_0_children(iterator pos);
  void balancing_after_removal(Node* parent, Node* brother);
  void balancing_after_removal_black_brother_no_child(Node* parent,
                                                      Node* brother);
  void balancing_after_removal_black_brother_one_sided_child_not_affect_height(
      Node* parent, Node* brother, Node* left_child, Node* right_child,
      bool brother_is_left);
  void
  balancing_after_removal_black_brother_another_sided_child_not_affect_height(
      Node* parent, Node* brother, Node* left_child, Node* right_child,
      bool brother_is_left);
  void balancing_after_removal_black_brother_child_affect_height(Node* parent,
                                                                 Node* brother);

 public:
  red_black_tree();
  red_black_tree(std::initializer_list<value_type> const& items);
  red_black_tree(const red_black_tree& m);
  red_black_tree(red_black_tree&& m);
  ~red_black_tree();
  red_black_tree<T>& operator=(red_black_tree&& m);

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert_or_assign(const value_type& value);
  void erase(iterator pos);
  void swap(red_black_tree& other);
  void merge(red_black_tree& other);
  bool contains(const value_type& key);

 protected:
  // Параметры класса
  Node* start_tree_;
  Node* end_tree_;
  Node* root_tree_;
  size_type tree_size_;

  void add_fake_node();
  std::pair<Node*, bool> find_place_to_insert(const value_type& value);
  std::pair<Node*, bool> find_element(const value_type& value);
  void enter_node(Node* root, Node* new_node, bool is_left);
  iterator get_root();
  class Node {
   public:
    Node* root_;
    Node* left_;
    Node* right_;
    value_type node_value_;
    bool is_red_;

    Node(value_type value = value_type(), Node* root = nullptr,
         Node* left = nullptr, Node* right = nullptr, bool is_red = true);
    Node(const Node& other);
    Node(Node&& other);
    ~Node();
  };
  class TreeIterator  // вложенный класс
  {
   public:
    Node* node_pointer_;

    TreeIterator();
    TreeIterator(Node* node_pointer);
    TreeIterator(const TreeIterator& other);
    TreeIterator(TreeIterator&& other);
    ~TreeIterator();
    iterator& operator=(iterator&& m);

    iterator& operator++();
    iterator& operator++(int);
    iterator& plus_plus();
    iterator& operator--();
    iterator& operator--(int);
    iterator& minus_minus();
    reference operator*();
    bool operator==(const iterator& other);
    bool operator==(const Node* other);
    bool operator!=(const iterator& other);
  };

  class TreeConstIterator  // вложенный класс
  {
   public:
    const Node* node_pointer_;

    TreeConstIterator();
    TreeConstIterator(Node* node_pointer);
    TreeConstIterator(const TreeConstIterator& other);
    TreeConstIterator(TreeConstIterator&& other);
    TreeConstIterator(const TreeIterator& other);
    TreeConstIterator(TreeIterator&& other);
    ~TreeConstIterator();

    const_iterator& operator++();
    const_iterator& operator++(int);
    const_iterator& plus_plus();
    const_iterator& operator--();
    const_iterator& operator--(int);
    const_iterator& minus_minus();
    const_reference operator*();
    bool operator==(const const_iterator& other);
    bool operator!=(const const_iterator& other);
  };
};
#include "s21_red_black_tree.tpp"
}  // namespace s21

#endif
