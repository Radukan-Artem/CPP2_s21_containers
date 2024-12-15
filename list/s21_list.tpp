template <typename T>
s21::list<T>::Node::Node(value_type value, Node* next_node,
                         Node* previous_node) {
  next_node_ = next_node;
  previous_node_ = previous_node;
  node_value_ = value;
}

template <typename T>
s21::list<T>::Node::Node(const Node& other)
    : next_node_(other.next_node_),
      previous_node_(other.previous_node_),
      node_value_(other.node_value_) {}

template <typename T>
s21::list<T>::Node::Node(Node&& other)
    : next_node_(other.next_node_),
      previous_node_(other.previous_node_),
      node_value_(other.node_value_) {
  other.next_node_ = nullptr;
  other.previous_node_ = nullptr;
}

template <typename T>
s21::list<T>::Node::~Node() {}

// ________________________________________________________
// Iterator

template <typename T>
s21::list<T>::ListIterator::ListIterator() : node_pointer_(nullptr) {}

template <typename T>
s21::list<T>::ListIterator::ListIterator(Node* node_pointer)
    : node_pointer_(node_pointer) {}

template <typename T>
s21::list<T>::ListIterator::ListIterator(const ListIterator& other)
    : node_pointer_(other.node_pointer_) {}

template <typename T>
s21::list<T>::ListIterator::ListIterator(ListIterator&& other)
    : node_pointer_(other.node_pointer_) {
  other.node_pointer_ = nullptr;
}

template <typename T>
s21::list<T>::ListIterator::~ListIterator() {}

template <typename T>
typename s21::list<T>::ListIterator& s21::list<T>::ListIterator::operator=(
    ListIterator&& other) {
  if (this != &other) {
    node_pointer_ = other.node_pointer_;
    other.node_pointer_ = nullptr;
  }
  return *this;
}

template <typename T>
typename s21::list<T>::iterator& s21::list<T>::ListIterator::operator++() {
  node_pointer_ = node_pointer_->next_node_;
  return *this;
}

template <typename T>
typename s21::list<T>::iterator& s21::list<T>::ListIterator::operator++(int) {
  node_pointer_ = node_pointer_->next_node_;
  return *this;
}

template <typename T>
typename s21::list<T>::iterator& s21::list<T>::ListIterator::operator--() {
  node_pointer_ = node_pointer_->previous_node_;
  return *this;
}

template <typename T>
typename s21::list<T>::iterator& s21::list<T>::ListIterator::operator--(int) {
  node_pointer_ = node_pointer_->previous_node_;
  return *this;
}

template <typename T>
typename s21::list<T>::reference s21::list<T>::ListIterator::operator*() {
  return node_pointer_->node_value_;
}

template <typename T>
bool s21::list<T>::ListIterator::operator==(const iterator& other) {
  return node_pointer_ == other.node_pointer_;
}

template <typename T>
bool s21::list<T>::ListIterator::operator!=(const iterator& other) {
  return node_pointer_ != other.node_pointer_;
}

// ________________________________________________________
// ConstIterator

template <typename T>
s21::list<T>::ListConstIterator::ListConstIterator() : node_pointer_(nullptr) {}

template <typename T>
s21::list<T>::ListConstIterator::ListConstIterator(Node* node_pointer)
    : node_pointer_(node_pointer) {}

template <typename T>
s21::list<T>::ListConstIterator::ListConstIterator(
    const ListConstIterator& other)
    : node_pointer_(other.node_pointer_) {}

template <typename T>
s21::list<T>::ListConstIterator::ListConstIterator(ListConstIterator&& other)
    : node_pointer_(other.node_pointer_) {
  other.node_pointer_ = nullptr;
}

template <typename T>
s21::list<T>::ListConstIterator::ListConstIterator(const ListIterator& other)
    : node_pointer_(other.node_pointer_) {}

template <typename T>
s21::list<T>::ListConstIterator::ListConstIterator(ListIterator&& other)
    : node_pointer_(other.node_pointer_) {
  other.node_pointer_ = nullptr;
}

template <typename T>
s21::list<T>::ListConstIterator::~ListConstIterator() {}

template <typename T>
typename s21::list<T>::ListConstIterator&
s21::list<T>::ListConstIterator::operator=(ListConstIterator&& other) {
  if (this != &other) {
    node_pointer_ = other.node_pointer_;
    other.node_pointer_ = nullptr;
  }
  return *this;
}

template <typename T>
typename s21::list<T>::ListConstIterator&
s21::list<T>::ListConstIterator::operator=(ListIterator&& other) {
  if (this != &other) {
    node_pointer_ = other.node_pointer_;
    other.node_pointer_ = nullptr;
  }
  return *this;
}

template <typename T>
typename s21::list<T>::const_iterator&
s21::list<T>::ListConstIterator::operator++() {
  node_pointer_ = node_pointer_->next_node_;
  return *this;
}

template <typename T>
typename s21::list<T>::const_iterator&
s21::list<T>::ListConstIterator::operator++(int) {
  node_pointer_ = node_pointer_->next_node_;
  return *this;
}

template <typename T>
typename s21::list<T>::const_iterator&
s21::list<T>::ListConstIterator::operator--() {
  node_pointer_ = node_pointer_->previous_node_;
  return *this;
}

template <typename T>
typename s21::list<T>::const_iterator&
s21::list<T>::ListConstIterator::operator--(int) {
  node_pointer_ = node_pointer_->previous_node_;
  return *this;
}

template <typename T>
typename s21::list<T>::const_reference
s21::list<T>::ListConstIterator::operator*() {
  return node_pointer_->node_value_;
}

template <typename T>
bool s21::list<T>::ListConstIterator::operator==(const const_iterator& other) {
  return node_pointer_ == other.node_pointer_;
}

template <typename T>
bool s21::list<T>::ListConstIterator::operator!=(const const_iterator& other) {
  return node_pointer_ != other.node_pointer_;
}

// ________________________________________________________
// list

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Конструкторы

template <typename T>
s21::list<T>::list() : start_list_(nullptr), end_list_(nullptr), list_size_(0) {
  add_fake_node();
}

template <typename T>
s21::list<T>::list(size_type n)
    : start_list_(nullptr), end_list_(nullptr), list_size_(0) {
  add_fake_node();
  for (size_type i = 0; i < n; i++) {
    push_back(T());
  }
}

template <typename T>
s21::list<T>::list(std::initializer_list<value_type> const& items)
    : start_list_(nullptr), end_list_(nullptr), list_size_(0) {
  add_fake_node();
  for (auto new_iterator = items.begin(); new_iterator != items.end();
       new_iterator++) {
    push_back(*new_iterator);
  }
}

template <typename T>
s21::list<T>::list(const list& l)
    : start_list_(nullptr), end_list_(nullptr), list_size_(0) {
  add_fake_node();
  for (s21::list<T>::iterator new_iterator = l.start_list_;
       new_iterator != l.end_list_; new_iterator++) {
    push_back(*new_iterator);
  }
}

template <typename T>
s21::list<T>::list(list&& l)
    : start_list_(l.start_list_),
      end_list_(l.end_list_),
      list_size_(l.list_size_) {
  l.start_list_ = nullptr;
  l.end_list_ = nullptr;
  l.list_size_ = 0;
}

template <typename T>
s21::list<T>::~list() {
  clear();
  delete end_list_;
}

template <typename T>
typename s21::list<T>& s21::list<T>::operator=(list&& l) {
  if (this != &l) {
    clear();
    delete end_list_;
    start_list_ = l.start_list_;
    end_list_ = l.end_list_;
    list_size_ = l.list_size_;
    l.start_list_ = nullptr;
    l.end_list_ = nullptr;
    l.list_size_ = 0;
  }
  return *this;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Функции

template <typename T>
typename s21::list<T>::const_reference s21::list<T>::front() {
  return start_list_->node_value_;
}

template <typename T>
typename s21::list<T>::const_reference s21::list<T>::back() {
  return (list_size_ > 0) ? end_list_->previous_node_->node_value_
                          : end_list_->node_value_;
}

template <typename T>
typename s21::list<T>::iterator s21::list<T>::begin() {
  return start_list_;
}

template <typename T>
typename s21::list<T>::iterator s21::list<T>::end() {
  return end_list_;
}

template <typename T>
bool s21::list<T>::empty() {
  return list_size_ == 0;
}

template <typename T>
typename s21::list<T>::size_type s21::list<T>::size() {
  return list_size_;
}

template <typename T>
typename s21::list<T>::size_type s21::list<T>::max_size() {
  return SIZE_MAX / sizeof(Node);
}

template <typename T>
void s21::list<T>::clear() {
  while (list_size_ > 0) {
    pop_back();
  }
}

template <typename T>
typename s21::list<T>::iterator s21::list<T>::insert(iterator pos,
                                                     const_reference value) {
  Node* new_node = new Node(value);
  enter_node(pos, new_node);

  return new_node;
}

template <typename T>
void s21::list<T>::erase(iterator pos) {
  if (list_size_ > 0) {
    pos.node_pointer_->next_node_->previous_node_ =
        pos.node_pointer_->previous_node_;
    if (pos.node_pointer_ == start_list_) {
      start_list_ = pos.node_pointer_->next_node_;
    } else {
      pos.node_pointer_->previous_node_->next_node_ =
          pos.node_pointer_->next_node_;
    }
    delete pos.node_pointer_;
    list_size_--;
  }
}

template <typename T>
void s21::list<T>::push_back(const_reference value) {
  insert(end_list_, value);
}

template <typename T>
void s21::list<T>::pop_back() {
  erase(end()--);
}

template <typename T>
void s21::list<T>::push_front(const_reference value) {
  insert(start_list_, value);
}

template <typename T>
void s21::list<T>::pop_front() {
  erase(begin());
}

template <typename T>
void s21::list<T>::swap(list& other) {
  Node* copy_start_list = start_list_;
  Node* copy_end_list = end_list_;
  size_type copy_list_size = list_size_;
  start_list_ = other.start_list_;
  end_list_ = other.end_list_;
  list_size_ = other.list_size_;
  other.start_list_ = copy_start_list;
  other.end_list_ = copy_end_list;
  other.list_size_ = copy_list_size;
}

template <typename T>
void s21::list<T>::merge(list& other) {
  auto iterator_this = begin();
  for (auto iter = other.begin(); iter != other.end();) {
    while (*iterator_this <= *iter && iterator_this != end()) {
      iterator_this++;
    }
    iter++;
    enter_node(iterator_this, iter.node_pointer_->previous_node_);
  }
  other.start_list_ = other.end_list_;
  other.list_size_ = 0;
  other.end_list_->next_node_ = nullptr;
  other.end_list_->previous_node_ = nullptr;
}

template <typename T>
void s21::list<T>::splice(const_iterator pos, list& other) {
  if (other.list_size_ > 0) {
    iterator copy_pos = const_cast<Node*>(pos.node_pointer_);
    if (pos == begin()) {
      start_list_ = other.start_list_;
    } else {
      pos.node_pointer_->previous_node_->next_node_ = other.start_list_;
    }
    other.start_list_->previous_node_ = pos.node_pointer_->previous_node_;
    other.end_list_->previous_node_->next_node_ = copy_pos.node_pointer_;
    list_size_ = list_size_ + other.list_size_;
    copy_pos.node_pointer_->previous_node_ = other.end_list_->previous_node_;

    other.start_list_ = other.end_list_;
    other.list_size_ = 0;
  }
}

template <typename T>
void s21::list<T>::reverse() {
  if (list_size_ > 1) {
    auto start_iterator = begin();
    auto end_iterator = end();
    end_iterator--;
    for (size_type i = 0; i < list_size_ / 2; i++) {
      auto copy_value = *start_iterator;
      *start_iterator = *end_iterator;
      *end_iterator = copy_value;

      start_iterator++;
      end_iterator--;
    }
  }
}

template <typename T>
void s21::list<T>::unique() {
  if (list_size_ > 1) {
    auto first_iterator = begin();
    while (first_iterator != end().node_pointer_->previous_node_) {
      auto second_iterator = iterator(first_iterator.node_pointer_->next_node_);
      if (*first_iterator != *second_iterator) {
        first_iterator++;
      } else {
        first_iterator.node_pointer_->next_node_ =
            second_iterator.node_pointer_->next_node_;
        second_iterator.node_pointer_->next_node_->previous_node_ =
            first_iterator.node_pointer_;
        delete second_iterator.node_pointer_;
        list_size_--;
      }
    }
  }
}

template <typename T>
void s21::list<T>::sort() {
  if (list_size_ > 1) {
    qsortRecursive(start_list_, end_list_, list_size_);
  }
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Вспомогательные функции

template <typename T>
void s21::list<T>::add_fake_node() {
  Node* new_node = new Node();
  start_list_ = new_node;
  end_list_ = new_node;
}

template <typename T>
void s21::list<T>::enter_node(iterator pos, Node* new_node) {
  if (pos.node_pointer_ == start_list_) {
    start_list_ = new_node;
  } else {
    pos.node_pointer_->previous_node_->next_node_ = new_node;
  }

  new_node->previous_node_ = pos.node_pointer_->previous_node_;
  new_node->next_node_ = pos.node_pointer_;

  pos.node_pointer_->previous_node_ = new_node;
  list_size_++;
}

template <typename T>
void s21::list<T>::qsortRecursive(iterator start, iterator end,
                                  int count_elements) {
  //Указатели в начало и в конец массива
  int i = 0;
  int j = count_elements - 1;
  iterator copy_start(start);
  iterator copy_end(end);
  copy_end--;
  //Центральный элемент массива
  iterator middle(start);
  for (int i = 0; i < count_elements / 2; i++) {
    middle++;
  }
  auto middle_value = middle.node_pointer_->node_value_;

  do {
    while (*copy_start < middle_value) {
      i++;
      copy_start++;
    }
    while (*copy_end > middle_value) {
      j--;
      copy_end--;
    }
    if (i <= j) {
      auto copy_value = *copy_start;
      *copy_start = *copy_end;
      *copy_end = copy_value;

      i++;
      copy_start++;
      j--;
      copy_end--;
    }
  } while (i <= j);

  if (j > 0) {
    qsortRecursive(start, copy_end++, j + 1);
  }
  if (i < count_elements) {
    qsortRecursive(copy_start, end, count_elements - i);
  }
}

template <typename T>
template <class... Args>
typename s21::list<T>::iterator s21::list<T>::insert_many(const_iterator pos,
                                                          Args&&... args) {
  iterator copy_pos = const_cast<Node*>(pos.node_pointer_);
  int count_elem = 0;
  for (const auto& value : {args...}) {
    insert(copy_pos, value);
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
void s21::list<T>::insert_many_back(Args&&... args) {
  for (const auto& value : {args...}) {
    push_back(value);
  }
}

template <typename T>
template <class... Args>
void s21::list<T>::insert_many_front(Args&&... args) {
  auto iterator_this = begin();
  for (const auto& value : {args...}) {
    iterator_this = insert(iterator_this, value);
    iterator_this++;
  }
}