// ________________________________________________________
// Node

template <typename T>
s21::red_black_tree<T>::Node::Node(value_type value, Node* root, Node* left,
                                   Node* right, bool is_red) {
  root_ = root;
  left_ = left;
  right_ = right;
  node_value_ = value;
  is_red_ = is_red;
}

template <typename T>
s21::red_black_tree<T>::Node::Node(const Node& other)
    : root_(other.root_),
      left_(other.left_),
      right_(other.right_),
      node_value_(other.node_value_),
      is_red_(other.is_red_) {}

template <typename T>
s21::red_black_tree<T>::Node::Node(Node&& other)
    : root_(other.root_),
      left_(other.left_),
      right_(other.right_),
      node_value_(other.node_value_),
      is_red_(other.is_red_) {
  other.root_ = nullptr;
  other.left_ = nullptr;
  other.right_ = nullptr;
}

template <typename T>
s21::red_black_tree<T>::Node::~Node() {}

// ________________________________________________________
// Iterator

template <typename T>
s21::red_black_tree<T>::TreeIterator::TreeIterator() : node_pointer_(nullptr) {}

template <typename T>
s21::red_black_tree<T>::TreeIterator::TreeIterator(Node* node_pointer)
    : node_pointer_(node_pointer) {}

template <typename T>
s21::red_black_tree<T>::TreeIterator::TreeIterator(const TreeIterator& other)
    : node_pointer_(other.node_pointer_) {}

template <typename T>
s21::red_black_tree<T>::TreeIterator::TreeIterator(TreeIterator&& other)
    : node_pointer_(other.node_pointer_) {
  other.node_pointer_ = nullptr;
}

template <typename T>
s21::red_black_tree<T>::TreeIterator::~TreeIterator() {}

template <typename T>
typename s21::red_black_tree<T>::iterator&
s21::red_black_tree<T>::TreeIterator::operator=(iterator&& m) {
  if (this != &m) {
    node_pointer_ = m.node_pointer_;
    m.node_pointer_ = nullptr;
  }
  return *this;
}

template <typename T>
typename s21::red_black_tree<T>::iterator&
s21::red_black_tree<T>::TreeIterator::operator++() {
  return plus_plus();
}

template <typename T>
typename s21::red_black_tree<T>::iterator&
s21::red_black_tree<T>::TreeIterator::operator++(int) {
  return plus_plus();
}

template <typename T>
typename s21::red_black_tree<T>::iterator&
s21::red_black_tree<T>::TreeIterator::plus_plus() {
  if (node_pointer_->right_ != nullptr) {
    node_pointer_ = node_pointer_->right_;
    while (node_pointer_->left_ != nullptr) {
      node_pointer_ = node_pointer_->left_;
    }
  } else {
    Node* last_node = node_pointer_;
    node_pointer_ = node_pointer_->root_;
    while (node_pointer_ != nullptr && node_pointer_->left_ != last_node) {
      last_node = node_pointer_;
      node_pointer_ = node_pointer_->root_;
    }
  }
  return *this;
}

template <typename T>
typename s21::red_black_tree<T>::iterator&
s21::red_black_tree<T>::TreeIterator::operator--() {
  return minus_minus();
}

template <typename T>
typename s21::red_black_tree<T>::iterator&
s21::red_black_tree<T>::TreeIterator::operator--(int) {
  return minus_minus();
}

template <typename T>
typename s21::red_black_tree<T>::iterator&
s21::red_black_tree<T>::TreeIterator::minus_minus() {
  if (node_pointer_->left_ != nullptr) {
    node_pointer_ = node_pointer_->left_;
    while (node_pointer_->right_ != nullptr) {
      node_pointer_ = node_pointer_->right_;
    }
  } else {
    Node* last_node = node_pointer_;
    node_pointer_ = node_pointer_->root_;
    while (node_pointer_ != nullptr && node_pointer_->right_ != last_node) {
      last_node = node_pointer_;
      node_pointer_ = node_pointer_->root_;
    }
  }
  return *this;
}

template <typename T>
typename s21::red_black_tree<T>::reference
s21::red_black_tree<T>::TreeIterator::operator*() {
  return node_pointer_->node_value_;
}

template <typename T>
bool s21::red_black_tree<T>::TreeIterator::operator==(const iterator& other) {
  return node_pointer_ == other.node_pointer_;
}

template <typename T>
bool s21::red_black_tree<T>::TreeIterator::operator==(const Node* other) {
  return node_pointer_ == other;
}

template <typename T>
bool s21::red_black_tree<T>::TreeIterator::operator!=(const iterator& other) {
  return node_pointer_ != other.node_pointer_;
}

// ________________________________________________________
// ConstIterator

template <typename T>
s21::red_black_tree<T>::TreeConstIterator::TreeConstIterator()
    : node_pointer_(nullptr) {}

template <typename T>
s21::red_black_tree<T>::TreeConstIterator::TreeConstIterator(Node* node_pointer)
    : node_pointer_(node_pointer) {}

template <typename T>
s21::red_black_tree<T>::TreeConstIterator::TreeConstIterator(
    const TreeConstIterator& other)
    : node_pointer_(other.node_pointer_) {}

template <typename T>
s21::red_black_tree<T>::TreeConstIterator::TreeConstIterator(
    TreeConstIterator&& other)
    : node_pointer_(other.node_pointer_) {
  other.node_pointer_ = nullptr;
}

template <typename T>
s21::red_black_tree<T>::TreeConstIterator::TreeConstIterator(
    const TreeIterator& other)
    : node_pointer_(other.node_pointer_) {}

template <typename T>
s21::red_black_tree<T>::TreeConstIterator::TreeConstIterator(
    TreeIterator&& other)
    : node_pointer_(other.node_pointer_) {
  other.node_pointer_ = nullptr;
}

template <typename T>
s21::red_black_tree<T>::TreeConstIterator::~TreeConstIterator() {}

template <typename T>
typename s21::red_black_tree<T>::const_iterator&
s21::red_black_tree<T>::TreeConstIterator::operator++() {
  return plus_plus();
}

template <typename T>
typename s21::red_black_tree<T>::const_iterator&
s21::red_black_tree<T>::TreeConstIterator::operator++(int) {
  return plus_plus();
}

template <typename T>
typename s21::red_black_tree<T>::const_iterator&
s21::red_black_tree<T>::TreeConstIterator::plus_plus() {
  if (node_pointer_->right_ != nullptr) {
    node_pointer_ = node_pointer_->right_;
    while (node_pointer_->left_ != nullptr) {
      node_pointer_ = node_pointer_->left_;
    }
  } else {
    Node* last_node = node_pointer_;
    node_pointer_ = node_pointer_->root_;
    while (node_pointer_ != nullptr && node_pointer_->left_ != last_node) {
      last_node = node_pointer_;
      node_pointer_ = node_pointer_->root_;
    }
  }
  return *this;
}

template <typename T>
typename s21::red_black_tree<T>::const_iterator&
s21::red_black_tree<T>::TreeConstIterator::operator--() {
  return minus_minus();
}

template <typename T>
typename s21::red_black_tree<T>::const_iterator&
s21::red_black_tree<T>::TreeConstIterator::operator--(int) {
  return minus_minus();
}

template <typename T>
typename s21::red_black_tree<T>::const_iterator&
s21::red_black_tree<T>::TreeConstIterator::minus_minus() {
  if (node_pointer_->left_ != nullptr) {
    node_pointer_ = node_pointer_->left_;
    while (node_pointer_->right_ != nullptr) {
      node_pointer_ = node_pointer_->right_;
    }
  } else {
    Node* last_node = node_pointer_;
    node_pointer_ = node_pointer_->root_;
    while (node_pointer_ != nullptr && node_pointer_->right_ != last_node) {
      last_node = node_pointer_;
      node_pointer_ = node_pointer_->root_;
    }
  }
  return *this;
}

template <typename T>
typename s21::red_black_tree<T>::const_reference
s21::red_black_tree<T>::TreeConstIterator::operator*() {
  return node_pointer_->node_value_;
}

template <typename T>
bool s21::red_black_tree<T>::TreeConstIterator::operator==(
    const const_iterator& other) {
  return node_pointer_ == other.node_pointer_;
}

template <typename T>
bool s21::red_black_tree<T>::TreeConstIterator::operator!=(
    const const_iterator& other) {
  return node_pointer_ != other.node_pointer_;
}

// ________________________________________________________
// red_black_tree

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Конструкторы

template <typename T>
s21::red_black_tree<T>::red_black_tree()
    : start_tree_(nullptr),
      end_tree_(nullptr),
      root_tree_(nullptr),
      tree_size_(0) {
  add_fake_node();
}

template <typename T>
s21::red_black_tree<T>::red_black_tree(
    std::initializer_list<value_type> const& items)
    : start_tree_(nullptr),
      end_tree_(nullptr),
      root_tree_(nullptr),
      tree_size_(0) {
  add_fake_node();
  for (auto new_iterator = items.begin(); new_iterator != items.end();
       new_iterator++) {
    insert(*new_iterator);
  }
}

template <typename T>
s21::red_black_tree<T>::red_black_tree(const red_black_tree& l)
    : start_tree_(nullptr),
      end_tree_(nullptr),
      root_tree_(nullptr),
      tree_size_(0) {
  add_fake_node();
  for (s21::red_black_tree<T>::iterator new_iterator = l.start_tree_;
       new_iterator != l.end_tree_; new_iterator++) {
    insert(*new_iterator);
  }
}

template <typename T>
s21::red_black_tree<T>::red_black_tree(red_black_tree&& l)
    : start_tree_(l.start_tree_),
      end_tree_(l.end_tree_),
      root_tree_(l.root_tree_),
      tree_size_(l.tree_size_) {
  l.start_tree_ = nullptr;
  l.end_tree_ = nullptr;
  l.root_tree_ = nullptr;
  l.tree_size_ = 0;
}

template <typename T>
s21::red_black_tree<T>::~red_black_tree() {
  clear();
  delete end_tree_;
}

template <typename T>
typename s21::red_black_tree<T>& s21::red_black_tree<T>::operator=(
    red_black_tree&& m) {
  return move(m);
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Функции

template <typename T>
typename s21::red_black_tree<T>::iterator s21::red_black_tree<T>::begin() {
  return start_tree_;
}

template <typename T>
typename s21::red_black_tree<T>::iterator s21::red_black_tree<T>::end() {
  return end_tree_;
}

template <typename T>
typename s21::red_black_tree<T>::iterator s21::red_black_tree<T>::get_root() {
  return root_tree_;
}

template <typename T>
bool s21::red_black_tree<T>::empty() {
  return tree_size_ == 0;
}

template <typename T>
typename s21::red_black_tree<T>::size_type s21::red_black_tree<T>::size() {
  return tree_size_;
}

template <typename T>
typename s21::red_black_tree<T>::size_type s21::red_black_tree<T>::max_size() {
  return SIZE_MAX / sizeof(Node);
}

template <typename T>
void s21::red_black_tree<T>::clear() {
  Node* this_node = start_tree_;
  while (tree_size_ > 0) {
    if (this_node->left_ != nullptr) {
      this_node = this_node->left_;
    } else if (this_node->right_ != nullptr && this_node->right_ != end_tree_) {
      this_node = this_node->right_;
    } else {
      if (this_node->root_ != nullptr) {
        if (this_node->root_->left_ == this_node) {
          this_node = this_node->root_;
          delete this_node->left_;
          this_node->left_ = nullptr;
        } else {
          this_node = this_node->root_;
          delete this_node->right_;
          this_node->right_ = nullptr;
        }
      } else {
        delete this_node;
      }
      tree_size_--;
    }
  }
  start_tree_ = end_tree_;
  end_tree_->root_ = nullptr;
}

template <typename T>
std::pair<typename s21::red_black_tree<T>::iterator, bool>
s21::red_black_tree<T>::insert(const value_type& value) {
  std::pair<Node*, bool> search_result = find_element(value);
  std::pair<iterator, bool> result;
  if (search_result.second == true) {
    result.first = search_result.first;
    result.second = false;
  } else {
    Node* new_node = new Node(value);
    bool is_left = false;
    if (new_node->node_value_ < search_result.first->node_value_) {
      is_left = true;
    }
    enter_node(search_result.first, new_node, is_left);
    result.first = iterator(new_node);
    result.second = true;
  }
  return result;
}

template <typename T>
std::pair<typename s21::red_black_tree<T>::iterator, bool>
s21::red_black_tree<T>::insert_or_assign(const value_type& value) {
  std::pair<Node*, bool> search_result = find_element(value);
  std::pair<iterator, bool> result;
  result.second = !search_result.second;
  if (search_result.second == true) {
    result.first = search_result.first;
    value_type copy_value(value);
    result.first.node_pointer_->node_value_ = copy_value;
  } else {
    Node* new_node = new Node(value);
    bool is_left = false;
    if (new_node->node_value_ < search_result.first->node_value_) {
      is_left = true;
    }
    enter_node(search_result.first, new_node, is_left);
    result.first = iterator(new_node);
    result.second = true;
  }
  return result;
}

// https://habr.com/ru/articles/573502/
template <typename T>
void s21::red_black_tree<T>::erase(iterator pos) {
  if (pos != end_tree_) {
    int amount_children = (pos.node_pointer_->left_ != nullptr) +
                          (pos.node_pointer_->right_ != nullptr &&
                           pos.node_pointer_->right_ != end_tree_);
    if (pos.node_pointer_->is_red_) {
      if (amount_children == 0) {
        delete_red_node_with_0_children(pos);
      } else {
        delete_node_with_2_children(pos);
      }
    } else {
      switch (amount_children) {
        case 0:
          delete_black_node_with_0_children(pos);
          break;
        case 1:
          delete_black_node_with_1_children(pos);
          break;
        case 2:
          delete_node_with_2_children(pos);
          break;
      }
    }
  }
}

template <typename T>
void s21::red_black_tree<T>::swap(red_black_tree& other) {
  Node* copy_start_tree = start_tree_;
  Node* copy_end_tree = end_tree_;
  Node* copy_root_tree = root_tree_;
  size_type copy_tree_size = tree_size_;

  start_tree_ = other.start_tree_;
  end_tree_ = other.end_tree_;
  root_tree_ = other.root_tree_;
  tree_size_ = other.tree_size_;

  other.start_tree_ = copy_start_tree;
  other.end_tree_ = copy_end_tree;
  other.root_tree_ = copy_root_tree;
  other.tree_size_ = copy_tree_size;
}

template <typename T>
void s21::red_black_tree<T>::merge(red_black_tree& other) {
  for (auto iter = other.begin(); iter != other.end();) {
    std::pair<iterator, bool> result_insert =
        insert(iter.node_pointer_->node_value_);
    if (result_insert.second) {
      other.erase(iter);
      iter = other.begin();
    } else {
      iter++;
    }
  }
}

template <typename T>
bool s21::red_black_tree<T>::contains(const value_type& key) {
  std::pair<Node*, bool> result_search = find_element(key);
  return result_search.second;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Вспомогательные функции

template <typename T>
typename s21::red_black_tree<T>& s21::red_black_tree<T>::move(
    red_black_tree&& m) {
  if (this != &m) {
    clear();
    delete end_tree_;

    start_tree_ = m.start_tree_;
    end_tree_ = m.end_tree_;
    root_tree_ = m.root_tree_;
    tree_size_ = m.tree_size_;

    m.start_tree_ = nullptr;
    m.end_tree_ = nullptr;
    m.root_tree_ = nullptr;
    m.tree_size_ = 0;
  }
  return *this;
}

template <typename T>
void s21::red_black_tree<T>::add_fake_node() {
  Node* new_node = new Node();
  start_tree_ = new_node;
  end_tree_ = new_node;
  root_tree_ = new_node;
}

template <typename T>
std::pair<typename s21::red_black_tree<T>::Node*, bool>
s21::red_black_tree<T>::find_place_to_insert(const value_type& value) {
  std::pair<Node*, bool> result;

  bool search_is_over = false;
  result.first = root_tree_;

  while (!search_is_over) {
    if (value < result.first->node_value_) {
      if (result.first->left_ == nullptr) {
        result.second = true;
        search_is_over = true;
      } else {
        result.first = result.first->left_;
      }
    } else {
      if (result.first->right_ == nullptr || end() == result.first->right_) {
        result.second = false;
        search_is_over = true;
      } else {
        result.first = result.first->right_;
      }
    }
  }

  return result;
}

template <typename T>
std::pair<typename s21::red_black_tree<T>::Node*, bool>
s21::red_black_tree<T>::find_element(const value_type& value) {
  std::pair<Node*, bool> result;

  bool search_is_over = false;
  result.first = root_tree_;

  value_type copy_value(value);

  while (!search_is_over) {
    if (copy_value < result.first->node_value_) {
      if (result.first->left_ == nullptr) {
        search_is_over = true;
      } else {
        result.first = result.first->left_;
      }
    } else if (copy_value > result.first->node_value_) {
      if (result.first->right_ == nullptr || end() == result.first->right_) {
        search_is_over = true;
      } else {
        result.first = result.first->right_;
      }
    } else {
      search_is_over = true;
      result.second = true;
    }
  }

  return result;
}

template <typename T>
void s21::red_black_tree<T>::enter_node(Node* root, Node* new_node,
                                        bool is_left) {
  if (tree_size_ == 0) {
    new_node->is_red_ = false;
    new_node->right_ = end_tree_;
    start_tree_ = new_node;
    root_tree_ = new_node;
    end_tree_->root_ = new_node;
  } else {
    new_node->root_ = root;
    if (is_left) {
      root->left_ = new_node;
      if (new_node->node_value_ < start_tree_->node_value_) {
        start_tree_ = new_node;
      }
    } else {
      if (root->right_ == end_tree_) {
        new_node->right_ = end_tree_;
        end_tree_->root_ = new_node;
      }
      root->right_ = new_node;
    }
    while (root != nullptr) {
      if (root->is_red_ && new_node->is_red_) {
        balancing(root);
      }
      if (root->root_ == new_node) {
        root = new_node->root_;
      } else {
        new_node = new_node->root_;
        root = root->root_;
      }
    }
  }
  tree_size_++;
}

template <typename T>
void s21::red_black_tree<T>::balancing(Node* father) {
  Node* son;
  Node* grandfather = father->root_;
  Node* uncle;
  if (father->left_ != nullptr && father->left_->is_red_) {
    son = father->left_;
  } else {
    son = father->right_;
  }
  if (grandfather->left_ == father) {
    uncle = grandfather->right_;
  } else {
    uncle = grandfather->left_;
  }

  if (uncle != nullptr && uncle != end_tree_ && uncle->is_red_) {
    father->is_red_ = false;
    uncle->is_red_ = false;
    if (grandfather != root_tree_) {
      grandfather->is_red_ = true;
    }
  } else {
    rotate_tree(father, grandfather, son);
  }
}

template <typename T>
void s21::red_black_tree<T>::rotate_tree(Node* father, Node* grandfather,
                                         Node* son) {
  bool father_is_left = (grandfather->left_ == father);
  bool son_is_left = (father->left_ == son);
  if (father_is_left == son_is_left) {
    replace_father_grandfather(father, grandfather, father_is_left);
    father->is_red_ = false;
    grandfather->is_red_ = true;
  } else {
    if (son_is_left) {
      grandfather->right_ = son;
      father->left_ = son->right_;
      if (son->right_ != nullptr) {
        son->right_->root_ = father;
      }
      son->right_ = father;
    } else {
      grandfather->left_ = son;
      father->right_ = son->left_;
      if (son->left_ != nullptr) {
        son->left_->root_ = father;
      }
      son->left_ = father;
    }
    son->root_ = grandfather;
    father->root_ = son;
    replace_father_grandfather(son, grandfather, father_is_left);
    son->is_red_ = false;
    grandfather->is_red_ = true;
  }
}

// Поворот вправо/влево
template <typename T>
void s21::red_black_tree<T>::replace_father_grandfather(Node* father,
                                                        Node* grandfather,
                                                        bool father_is_left) {
  if (grandfather->root_ != nullptr &&
      grandfather->root_->right_ == grandfather) {
    grandfather->root_->right_ = father;
  } else if (grandfather->root_ != nullptr) {
    grandfather->root_->left_ = father;
  }
  if (father_is_left) {
    grandfather->left_ = father->right_;
    if (father->right_ != nullptr) {
      father->right_->root_ = grandfather;
    }
    father->right_ = grandfather;
  } else {
    grandfather->right_ = father->left_;
    if (father->left_ != nullptr) {
      father->left_->root_ = grandfather;
    }
    father->left_ = grandfather;
  }
  father->root_ = grandfather->root_;
  grandfather->root_ = father;
  if (grandfather == root_tree_) {
    root_tree_ = father;
    root_tree_->is_red_ = false;
  }
}

template <typename T>
void s21::red_black_tree<T>::delete_red_node_with_0_children(iterator pos) {
  if (pos.node_pointer_ == start_tree_) {
    start_tree_ = pos.node_pointer_->root_;
  }

  if (pos.node_pointer_->root_->left_ == pos.node_pointer_) {
    pos.node_pointer_->root_->left_ = nullptr;
  } else {
    if (pos.node_pointer_->right_ == end_tree_) {
      pos.node_pointer_->root_->right_ = end_tree_;
      end_tree_->root_ = pos.node_pointer_->root_;
    } else {
      pos.node_pointer_->root_->right_ = nullptr;
    }
  }

  delete pos.node_pointer_;
  tree_size_--;
}

template <typename T>
void s21::red_black_tree<T>::delete_node_with_2_children(iterator pos) {
  iterator max_left_node(pos.node_pointer_->left_);
  while (max_left_node.node_pointer_->right_ != nullptr) {
    max_left_node.node_pointer_ = max_left_node.node_pointer_->right_;
  }

  auto copy_value = *pos;
  pos.node_pointer_->node_value_ = max_left_node.node_pointer_->node_value_;
  max_left_node.node_pointer_->node_value_ = copy_value;

  if (max_left_node.node_pointer_->is_red_) {
    delete_red_node_with_0_children(max_left_node);
  } else {
    if (max_left_node.node_pointer_->left_ == nullptr &&
        (max_left_node.node_pointer_->right_ == nullptr ||
         max_left_node.node_pointer_->right_ == end_tree_)) {
      delete_black_node_with_0_children(max_left_node);
    } else {
      delete_black_node_with_1_children(max_left_node);
    }
  }
}

template <typename T>
void s21::red_black_tree<T>::delete_black_node_with_1_children(iterator pos) {
  // У черной ноды 1 ребенок может быть только красным. Иначе дерево не
  // сбалансировано.
  if (pos.node_pointer_->left_ != nullptr) {
    pos.node_pointer_->node_value_ = pos.node_pointer_->left_->node_value_;
    if (pos.node_pointer_->left_ == start_tree_) {
      start_tree_ = pos.node_pointer_;
    }
    delete pos.node_pointer_->left_;
    pos.node_pointer_->left_ = nullptr;
  } else {
    Node* right_node = pos.node_pointer_->right_;
    pos.node_pointer_->node_value_ = right_node->node_value_;
    if (right_node->right_ == end_tree_) {
      pos.node_pointer_->right_ = end_tree_;
      end_tree_->root_ = pos.node_pointer_;
    } else {
      pos.node_pointer_->right_ = nullptr;
    }
    delete right_node;
  }
  tree_size_--;
}

// https://habr.com/ru/companies/otus/articles/521034/
// https://habr.com/ru/articles/573502/
template <typename T>
void s21::red_black_tree<T>::delete_black_node_with_0_children(iterator pos) {
  if (pos.node_pointer_->root_ != nullptr) {
    Node* parent = pos.node_pointer_->root_;

    if (parent->right_ == pos.node_pointer_) {
      if (pos.node_pointer_->right_ == end_tree_) {
        parent->right_ = end_tree_;
        end_tree_->root_ = parent;
      } else {
        parent->right_ = nullptr;
      }
      balancing_after_removal(parent, parent->left_);
    } else {
      parent->left_ = nullptr;
      if (pos.node_pointer_ == start_tree_) {
        start_tree_ = parent;
      }
      balancing_after_removal(parent, parent->right_);
    }
  } else {
    start_tree_ = end_tree_;
    root_tree_ = end_tree_;
    end_tree_->root_ = nullptr;
  }
  delete pos.node_pointer_;
  tree_size_--;
}

template <typename T>
void s21::red_black_tree<T>::balancing_after_removal(Node* parent,
                                                     Node* brother) {
  bool brother_is_left = true;
  if (parent->right_ == brother) {
    brother_is_left = false;
  }
  Node* left_child = brother->left_;
  Node* right_child = brother->right_;

  if (!brother->is_red_) {
    if (left_child == nullptr &&
        (right_child == nullptr || right_child == end_tree_)) {
      balancing_after_removal_black_brother_no_child(parent, brother);
    } else if ((brother_is_left && left_child != nullptr &&
                left_child->is_red_) ||
               (!brother_is_left && right_child != nullptr &&
                right_child != end_tree_ && right_child->is_red_)) {
      balancing_after_removal_black_brother_one_sided_child_not_affect_height(
          parent, brother, left_child, right_child, brother_is_left);
    } else if ((brother_is_left && right_child != nullptr &&
                right_child->is_red_) ||
               (!brother_is_left && left_child != nullptr &&
                left_child->is_red_)) {
      balancing_after_removal_black_brother_another_sided_child_not_affect_height(
          parent, brother, left_child, right_child, brother_is_left);
    } else {
      balancing_after_removal_black_brother_child_affect_height(parent,
                                                                brother);
    }
  } else {
    brother->is_red_ = false;
    parent->is_red_ = true;
    replace_father_grandfather(brother, parent, brother_is_left);
    Node* new_brother =
        (parent->left_ == nullptr) ? parent->right_ : parent->left_;
    balancing_after_removal(parent, new_brother);
  }
}

template <typename T>
void s21::red_black_tree<T>::balancing_after_removal_black_brother_no_child(
    Node* parent, Node* brother) {
  brother->is_red_ = true;
  if (parent->is_red_ || parent == root_tree_) {
    parent->is_red_ = false;
  } else {
    parent->is_red_ = false;
    Node* new_brother = (parent->root_->left_ == parent) ? parent->root_->right_
                                                         : parent->root_->left_;
    balancing_after_removal(parent->root_, new_brother);
  }
}

template <typename T>
void s21::red_black_tree<T>::
    balancing_after_removal_black_brother_one_sided_child_not_affect_height(
        Node* parent, Node* brother, Node* left_child, Node* right_child,
        bool brother_is_left) {
  brother->is_red_ = parent->is_red_;
  parent->is_red_ = false;
  if (brother_is_left) {
    left_child->is_red_ = false;
  } else {
    right_child->is_red_ = false;
  }
  replace_father_grandfather(brother, parent, brother_is_left);
}

template <typename T>
void s21::red_black_tree<T>::
    balancing_after_removal_black_brother_another_sided_child_not_affect_height(
        Node* parent, Node* brother, Node* left_child, Node* right_child,
        bool brother_is_left) {
  brother->is_red_ = true;
  if (brother_is_left) {
    right_child->is_red_ = false;
    replace_father_grandfather(right_child, brother, !brother_is_left);

    right_child->is_red_ = parent->is_red_;
    replace_father_grandfather(right_child, parent, brother_is_left);
  } else {
    left_child->is_red_ = false;
    replace_father_grandfather(left_child, brother, !brother_is_left);

    left_child->is_red_ = parent->is_red_;
    replace_father_grandfather(left_child, parent, brother_is_left);
  }
  parent->is_red_ = false;
  brother->is_red_ = false;
}

template <typename T>
void s21::red_black_tree<T>::
    balancing_after_removal_black_brother_child_affect_height(Node* parent,
                                                              Node* brother) {
  brother->is_red_ = true;
  if (parent->is_red_ || parent == root_tree_) {
    parent->is_red_ = false;
  } else {
    parent->is_red_ = false;
    Node* new_brother = (parent->root_->left_ == parent) ? parent->root_->right_
                                                         : parent->root_->left_;
    balancing_after_removal(parent->root_, new_brother);
  }
}