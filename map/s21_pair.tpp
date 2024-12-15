template <typename Key, typename T>
s21::pair<Key, T>::pair(Key first, T second) : first(first), second(second) {}

template <typename Key, typename T>
s21::pair<Key, T>::~pair() {}

template <typename Key, typename T>
s21::pair<Key, T>& s21::pair<Key, T>::operator=(pair& p) {
  first = p.first;
  second = p.second;

  p.first = Key();
  p.second = T();
  return *this;
}

template <typename Key, typename T>
s21::pair<Key, T>& s21::pair<Key, T>::operator=(pair&& p) {
  if (this != &p) {
    first = p.first;
    second = p.second;

    p.first = Key();
    p.second = T();
  }
  return *this;
}

template <typename Key, typename T>
bool s21::pair<Key, T>::operator<(const pair& other) {
  return first < other.first;
}

template <typename Key, typename T>
bool s21::pair<Key, T>::operator<=(const pair& other) {
  return first <= other.first;
}

template <typename Key, typename T>
bool s21::pair<Key, T>::operator>=(const pair& other) {
  return first >= other.first;
}

template <typename Key, typename T>
bool s21::pair<Key, T>::operator>(const pair& other) {
  return first > other.first;
}

template <typename Key, typename T>
bool s21::pair<Key, T>::operator==(const pair& other) {
  return first == other.first;
}

template <typename Key, typename T>
bool s21::pair<Key, T>::operator!=(const pair& other) {
  return first != other.first;
}