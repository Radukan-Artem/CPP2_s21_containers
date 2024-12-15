// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Конструкторы

template <typename Key, typename T>
s21::map<Key, T>::map() : s21::red_black_tree<s21::pair<Key, T>>() {}

template <typename Key, typename T>
s21::map<Key, T>::map(std::initializer_list<value_type> const& items)
    : s21::red_black_tree<s21::pair<Key, T>>() {
  for (auto iter = items.begin(); iter != items.end(); iter++) {
    s21::pair<Key, T> element((*iter).first, (*iter).second);
    insert(element);
  }
}

template <typename Key, typename T>
s21::map<Key, T>::map(const map& m)
    : s21::red_black_tree<s21::pair<Key, T>>(m) {}

template <typename Key, typename T>
s21::map<Key, T>::map(map&& m) : s21::red_black_tree<s21::pair<Key, T>>(m) {}

template <typename Key, typename T>
s21::map<Key, T>::~map() {}

template <typename Key, typename T>
s21::map<Key, T>& s21::map<Key, T>::operator=(map&& m) {
  return move(m);
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Функции

template <typename Key, typename T>
T& s21::map<Key, T>::at(const Key& key) {
  s21::pair<Key, T> p1(key, T());

  auto result_search = s21::red_black_tree<s21::pair<Key, T>>::find_element(p1);

  if (result_search.second == false) {
    // Если при вызове функции, не использовался try-catch, то деструкторы не
    // вызываются. Появляются утечки У оригинала так же
    throw std::out_of_range("Incorrect input, index is out of range");
  }

  return result_search.first->node_value_.second;
}

template <typename Key, typename T>
T& s21::map<Key, T>::operator[](const Key& key) {
  s21::pair<Key, T> element(key, T());

  auto result_search = s21::red_black_tree<s21::pair<Key, T>>::insert(element);

  return result_search.first.node_pointer_->node_value_.second;
}

template <typename Key, typename T>
std::pair<typename s21::red_black_tree<s21::pair<Key, T>>::iterator, bool>
s21::map<Key, T>::insert(const s21::pair<Key, T>& value) {
  return s21::red_black_tree<s21::pair<Key, T>>::insert(value);
}

template <typename Key, typename T>
std::pair<typename s21::red_black_tree<s21::pair<Key, T>>::iterator, bool>
s21::map<Key, T>::insert(const Key& key, const T& obj) {
  s21::pair<Key, T> element(key, obj);
  return s21::red_black_tree<s21::pair<Key, T>>::insert(element);
}

template <typename Key, typename T>
std::pair<typename s21::red_black_tree<s21::pair<Key, T>>::iterator, bool>
s21::map<Key, T>::insert_or_assign(const Key& key, const T& obj) {
  s21::pair<Key, T> element(key, obj);
  return s21::red_black_tree<s21::pair<Key, T>>::insert_or_assign(element);
}

template <typename Key, typename T>
template <class... Args>
std::vector<
    std::pair<typename s21::red_black_tree<s21::pair<Key, T>>::iterator, bool>>
s21::map<Key, T>::insert_many(Args&&... args) {
  std::vector<std::pair<
      typename s21::red_black_tree<s21::pair<Key, T>>::iterator, bool>>
      result;
  for (const auto& value : {args...}) {
    result.push_back(insert(value));
  }
  return result;
}