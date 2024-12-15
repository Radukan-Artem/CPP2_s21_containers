// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Конструкторы

template <typename T, std::size_t N>
s21::array<T, N>::array() : size_(N) {
  array_values_ = new T[N];
}

template <typename T, std::size_t N>
s21::array<T, N>::array(std::initializer_list<value_type> const &items) {
  if (N < items.size()) {
    throw "Too many initializers";
  }
  array_values_ = new T[N];

  int i = 0;
  for (auto new_iterator = items.begin(); new_iterator != items.end();
       new_iterator++) {
    array_values_[i] = *new_iterator;
    i++;
  }
}

template <typename T, std::size_t N>
s21::array<T, N>::array(const array &a) : size_(a.size_) {
  array_values_ = new T[N];
  for (size_t i = 0; i < a.size_; i++) {
    array_values_[i] = a.array_values_[i];
  }
}

template <typename T, std::size_t N>
s21::array<T, N>::array(array &&a) : size_(a.size_) {
  array_values_ = std::move(a.array_values_);

  a.array_values_ = nullptr;
}

template <typename T, std::size_t N>
typename s21::array<T, N> &s21::array<T, N>::operator=(array &&a) {
  if (this != &a) {
    delete[] array_values_;
    size_ = a.size_;
    array_values_ = std::move(a.array_values_);

    a.array_values_ = nullptr;
  }
  return *this;
}

// // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// // Доступ к элементам

template <typename T, std::size_t N>
typename s21::array<T, N>::reference s21::array<T, N>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("out of range");
  }
  return array_values_[pos];
}

template <typename T, std::size_t N>
typename s21::array<T, N>::reference s21::array<T, N>::operator[](
    size_type pos) {
  return at(pos);
}

template <typename T, std::size_t N>
typename s21::array<T, N>::const_reference s21::array<T, N>::front() noexcept {
  return at(0);
}

template <typename T, std::size_t N>
typename s21::array<T, N>::const_reference s21::array<T, N>::back() noexcept {
  return at(size_ - 1);
}

template <typename T, std::size_t N>
typename s21::array<T, N>::iterator s21::array<T, N>::data() {
  return array_values_;
}

// // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// // Доступ к итераторам

template <typename T, std::size_t N>
typename s21::array<T, N>::iterator s21::array<T, N>::begin() noexcept {
  return array_values_;
}

template <typename T, std::size_t N>
typename s21::array<T, N>::iterator s21::array<T, N>::end() noexcept {
  return (array_values_ + size_);
}

// // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// // Доступ к информации

template <typename T, std::size_t N>
bool s21::array<T, N>::empty() {
  return (size_ == 0);
}

template <typename T, std::size_t N>
typename s21::array<T, N>::size_type s21::array<T, N>::size() {
  return size_;
}

template <typename T, std::size_t N>
typename s21::array<T, N>::size_type s21::array<T, N>::max_size() {
  return size_;
}

// // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// // Публичные методы

template <typename T, std::size_t N>
void s21::array<T, N>::swap(array &other) {
  value_type *array_values = array_values_;

  array_values_ = other.array_values_;

  other.array_values_ = array_values;
}

template <typename T, std::size_t N>
void s21::array<T, N>::fill(const_reference value) {
  for (size_type i = 0; i < size_; i++) {
    array_values_[i] = value;
  }
}