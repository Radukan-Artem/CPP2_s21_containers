// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Конструкторы

template <typename Key>
s21::multiset<Key>::multiset() : s21::red_black_tree<Key>() {}

template <typename Key>
s21::multiset<Key>::multiset(std::initializer_list<value_type> const& items)
    : s21::red_black_tree<Key>() {
  for (auto new_iterator = items.begin(); new_iterator != items.end();
       new_iterator++) {
    auto result_search =
        s21::red_black_tree<Key>::find_place_to_insert(*new_iterator);
    typename s21::red_black_tree<Key>::Node* new_node =
        new typename s21::red_black_tree<Key>::Node(*new_iterator);
    s21::red_black_tree<Key>::enter_node(result_search.first, new_node,
                                         result_search.second);
  }
}

template <typename Key>
s21::multiset<Key>::multiset(const multiset& m) : s21::red_black_tree<Key>() {
  for (s21::multiset<Key>::iterator new_iterator = m.start_tree_;
       new_iterator != m.end_tree_; new_iterator++) {
    auto result_search =
        s21::red_black_tree<Key>::find_place_to_insert(*new_iterator);
    typename s21::red_black_tree<Key>::Node* new_node =
        new typename s21::red_black_tree<Key>::Node(*new_iterator);
    s21::red_black_tree<Key>::enter_node(result_search.first, new_node,
                                         result_search.second);
  }
}

template <typename Key>
s21::multiset<Key>::multiset(multiset&& m) : s21::red_black_tree<Key>(m) {}

template <typename Key>
s21::multiset<Key>::~multiset() {}

template <typename Key>
s21::multiset<Key>& s21::multiset<Key>::operator=(multiset&& m) {
  return move(m);
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Функции

template <typename Key>
typename s21::red_black_tree<Key>::iterator s21::multiset<Key>::insert(
    const value_type& value) {
  auto result_search = s21::red_black_tree<Key>::find_place_to_insert(value);
  typename s21::red_black_tree<Key>::Node* new_node =
      new typename s21::red_black_tree<Key>::Node(value);
  s21::red_black_tree<Key>::enter_node(result_search.first, new_node,
                                       result_search.second);
  return new_node;
}

template <typename Key>
void s21::multiset<Key>::merge(multiset& other) {
  for (auto iter = other.begin(); iter != other.end();) {
    insert(iter.node_pointer_->node_value_);
    other.erase(iter);
    iter = other.begin();
  }
}

template <typename Key>
size_t s21::multiset<Key>::count(const Key& key) {
  size_type result = 0;

  auto result_search = s21::red_black_tree<Key>::find_element(key);

  iterator iterator_key = result_search.first;
  iterator_key--;
  iterator iterator_key_copy = result_search.first;

  while (iterator_key != nullptr &&
         iterator_key.node_pointer_->node_value_ == key) {
    result++;
    iterator_key--;
  }

  while (iterator_key_copy != this->end() &&
         iterator_key_copy.node_pointer_->node_value_ == key) {
    result++;
    iterator_key_copy++;
  }

  return result;
}

template <typename Key>
typename s21::red_black_tree<Key>::iterator s21::multiset<Key>::find(
    const Key& key) {
  auto result_search = s21::red_black_tree<Key>::find_element(key);

  iterator result = result_search.first;
  if (result_search.second == false) {
    result = s21::red_black_tree<Key>::end();
  }

  return result;
}

template <typename Key>
std::pair<typename s21::red_black_tree<Key>::iterator,
          typename s21::red_black_tree<Key>::iterator>
s21::multiset<Key>::equal_range(const Key& key) {
  std::pair<typename s21::red_black_tree<Key>::iterator,
            typename s21::red_black_tree<Key>::iterator>
      result;

  auto result_search = s21::red_black_tree<Key>::find_element(key);

  result.first = result_search.first;
  result.second = result_search.first;
  bool result_changed = false;

  while (result.first.node_pointer_->left_ != nullptr &&
         result.first.node_pointer_->node_value_ == key) {
    result.first--;
  }
  if (result.first.node_pointer_->node_value_ != key &&
      result.first.node_pointer_ != this->end_tree_) {
    result.first++;
  }

  while (result.second.node_pointer_ != this->end_tree_ &&
         result.second.node_pointer_->node_value_ == key) {
    result.second++;
    result_changed = true;
  }
  if (result_changed == false &&
      result.second.node_pointer_ != this->end_tree_) {
    result.second++;
  }

  return result;
}

template <typename Key>
typename s21::red_black_tree<Key>::iterator s21::multiset<Key>::lower_bound(
    const Key& key) {
  auto result_search = s21::red_black_tree<Key>::find_element(key);

  iterator result = result_search.first;
  while (*result == key && result.node_pointer_->left_ != nullptr) {
    result--;
  }

  while (*result < key && result.node_pointer_ != this->end_tree_) {
    result++;
  }

  return result;
}

template <typename Key>
typename s21::red_black_tree<Key>::iterator s21::multiset<Key>::upper_bound(
    const Key& key) {
  auto result_search = s21::red_black_tree<Key>::find_place_to_insert(key);

  iterator result = result_search.first;
  while (*result <= key && result.node_pointer_ != this->end_tree_) {
    result.node_pointer_++;
  }

  return result;
}

template <typename Key>
template <class... Args>
std::vector<std::pair<typename s21::red_black_tree<Key>::iterator, bool>>
s21::multiset<Key>::insert_many(Args&&... args) {
  std::vector<std::pair<typename s21::red_black_tree<Key>::iterator, bool>>
      result;
  for (const auto& value : {args...}) {
    std::pair<iterator, bool> result_insert;
    result_insert.first = insert(value);
    result_insert.second = true;
    result.push_back(result_insert);
  }
  return result;
}