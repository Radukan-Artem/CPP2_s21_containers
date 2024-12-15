// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Вспомогательные функции

template <typename T>
void s21::vector<T>::change_size_array(size_type size) {
  value_type* new_array = new value_type[size];
  for (size_type i = 0; i < size_; i++) {
    new_array[i] = array_values_[i];
  }
  delete[] array_values_;
  array_values_ = new_array;
  capacity_ = size;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Конструкторы

template <typename T>
s21::vector<T>::vector() : size_(0), capacity_(0), array_values_(nullptr) {}

template <typename T>
s21::vector<T>::vector(size_type n) : size_(n), capacity_(n) {
  array_values_ = nullptr;
  if (n > 0) {
    array_values_ = new T[n];
    for (size_type i = 0; i < n; i++) {
      array_values_[i] = T();
    }
  }
}

template <typename T>
s21::vector<T>::vector(std::initializer_list<value_type> const& items) {
  size_ = items.size();
  capacity_ = size_;
  array_values_ = new value_type[size_];

  int i = 0;
  for (auto new_iterator = items.begin(); new_iterator != items.end();
       new_iterator++) {
    array_values_[i] = *new_iterator;
    i++;
  }
}

template <typename T>
s21::vector<T>::vector(const vector& v)
    : size_(v.size_), capacity_(v.capacity_) {
  array_values_ = new value_type[size_];

  for (size_t i = 0; i < v.size_; i++) {
    array_values_[i] = v.array_values_[i];
  }
}

template <typename T>
s21::vector<T>::vector(vector&& v) : size_(v.size_), capacity_(v.capacity_) {
  array_values_ = std::move(v.array_values_);

  v.array_values_ = nullptr;
  v.size_ = 0;
  v.capacity_ = 0;
}

template <typename T>
s21::vector<T>::~vector() {
  size_ = 0;
  capacity_ = 0;
  delete[] array_values_;
}

template <typename T>
typename s21::vector<T>& s21::vector<T>::operator=(vector&& v) {
  if (this != &v) {
    delete[] array_values_;
    size_ = v.size_;
    capacity_ = v.capacity_;
    array_values_ = std::move(v.array_values_);

    v.array_values_ = nullptr;
    v.size_ = 0;
    v.capacity_ = 0;
  }
  return *this;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Доступ к элементам

template <typename T>
typename s21::vector<T>::reference s21::vector<T>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("out of range");
  }
  return array_values_[pos];
}

template <typename T>
typename s21::vector<T>::reference s21::vector<T>::operator[](size_type pos) {
  return array_values_[pos];
}

template <typename T>
typename s21::vector<T>::const_reference s21::vector<T>::front() noexcept {
  return *(this->array_values_);
}

template <typename T>
typename s21::vector<T>::const_reference s21::vector<T>::back() noexcept {
  return (empty() ? *this->array_values_ : array_values_[size_ - 1]);
}

template <typename T>
T* s21::vector<T>::data() {
  return array_values_;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Доступ к итераторам

template <typename T>
typename s21::vector<T>::iterator s21::vector<T>::begin() noexcept {
  return array_values_;
}

template <typename T>
typename s21::vector<T>::iterator s21::vector<T>::end() noexcept {
  return (array_values_ + size_);
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Доступ к информации

template <typename T>
bool s21::vector<T>::empty() {
  return (size_ == 0);
}

template <typename T>
typename s21::vector<T>::size_type s21::vector<T>::size() {
  return size_;
}

template <typename T>
typename s21::vector<T>::size_type s21::vector<T>::max_size() {
  return SIZE_MAX / sizeof(value_type);
}

template <typename T>
void s21::vector<T>::reserve(size_type size) {
  if (size > capacity_) {
    change_size_array(size);
  }
}

template <typename T>
typename s21::vector<T>::size_type s21::vector<T>::capacity() {
  return capacity_;
}

template <typename T>
void s21::vector<T>::shrink_to_fit() {
  if (size_ < capacity_) {
    change_size_array(size_);
  }
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Публичные методы

template <typename T>
void s21::vector<T>::clear() {
  while (size_) {
    pop_back();
  }
}

template <typename T>
typename s21::vector<T>::iterator s21::vector<T>::insert(
    iterator pos, const_reference value) {
  size_type index = pos - array_values_;
  if (size_ == capacity_) {
    reserve(capacity_ ? capacity_ * 2 : 1);
  }
  iterator result_pos = array_values_ + index;

  for (iterator i = end(); i != result_pos; i--) {
    *i = *(i - 1);
  }
  *result_pos = value;
  size_++;
  return result_pos;
}

template <typename T>
void s21::vector<T>::erase(iterator pos) {
  for (iterator i = pos; i != end(); i++) {
    *i = *(i + 1);
  }

  size_--;
}

template <typename T>
void s21::vector<T>::push_back(const_reference value) {
  iterator pos = end();
  insert(pos, value);
}

template <typename T>
void s21::vector<T>::pop_back() {
  if (size_ > 0) {
    erase(end() - 1);
  }
}

template <typename T>
void s21::vector<T>::swap(vector& other) {
  size_type size = size_;
  size_type capacity = capacity_;
  value_type* array_values = array_values_;

  size_ = other.size_;
  capacity_ = other.capacity_;
  array_values_ = other.array_values_;

  other.size_ = size;
  other.capacity_ = capacity;
  other.array_values_ = array_values;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Методы insert_many

template <typename T>
template <class... Args>
typename s21::vector<T>::iterator s21::vector<T>::insert_many(
    const_iterator pos, Args&&... args) {
  iterator copy_pos = iterator(pos);
  int count_elem = 0;
  for (const auto& value : {args...}) {
    copy_pos = insert(copy_pos, value);
    copy_pos++;
    count_elem++;
  }
  // Для схожести с insert_range
  for (int i = 0; i < count_elem; i++) {
    copy_pos--;
  }
  return copy_pos;
}

template <typename T>
template <class... Args>
void s21::vector<T>::insert_many_back(Args&&... args) {
  for (const auto& value : {args...}) {
    push_back(value);
  }
}