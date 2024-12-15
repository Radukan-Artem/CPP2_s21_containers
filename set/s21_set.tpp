// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Конструкторы

template <typename Key>
s21::set<Key>::set() : s21::red_black_tree<Key>() {}

template <typename Key>
s21::set<Key>::set(std::initializer_list<value_type> const &items)
    : s21::red_black_tree<Key>(items) {}

template <typename Key>
s21::set<Key>::set(const set &m) : s21::red_black_tree<Key>(m) {}

template <typename Key>
s21::set<Key>::set(set &&m) : s21::red_black_tree<Key>(m) {}

template <typename Key>
s21::set<Key>::~set() {}

template <typename Key>
s21::set<Key> &s21::set<Key>::operator=(set &&m) {
  return move(m);
}

template <typename Key>
template <class... Args>
std::vector<std::pair<typename s21::red_black_tree<Key>::iterator, bool>>
s21::set<Key>::insert_many(Args &&...args) {
  std::vector<std::pair<typename s21::red_black_tree<Key>::iterator, bool>>
      result;
  for (const auto &value : {args...}) {
    result.push_back(this->insert(value));
  }
  return result;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Функции

template <typename Key>
typename s21::red_black_tree<Key>::iterator s21::set<Key>::find(
    const Key &key) {
  auto result_search = s21::red_black_tree<Key>::find_element(key);

  iterator result = result_search.first;
  if (result_search.second == false) {
    result = s21::red_black_tree<Key>::end();
  }

  return result;
}