// ________________________________________________________
// Node

template <typename T>
s21::queue<T>::Node::Node(value_type value, Node *next_node) {
  next_node_ = next_node;
  node_value_ = value;
}

template <typename T>
s21::queue<T>::Node::Node(const Node &other)
    : next_node_(other.next_node_), node_value_(other.node_value_) {}

template <typename T>
s21::queue<T>::Node::Node(Node &&other)
    : next_node_(other.next_node_), node_value_(other.node_value_) {
  other.next_node_ = nullptr;
}

template <typename T>
s21::queue<T>::Node::~Node() {}

// ________________________________________________________
// queue

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Конструкторы

template <typename T>
s21::queue<T>::queue()
    : start_queue_(nullptr), end_queue_(nullptr), queue_size_(0) {}

template <typename T>
s21::queue<T>::queue(std::initializer_list<value_type> const &items)
    : start_queue_(nullptr), end_queue_(nullptr), queue_size_(0) {
  for (auto new_iterator = items.begin(); new_iterator != items.end();
       new_iterator++) {
    push(*new_iterator);
  }
}

template <typename T>
s21::queue<T>::queue(const queue &q)
    : start_queue_(nullptr), end_queue_(nullptr), queue_size_(0) {
  Node *copy_node = q.start_queue_;
  for (size_t i = 0; i < q.queue_size_; i++) {
    push(copy_node->node_value_);
    copy_node = copy_node->next_node_;
  }
}

template <typename T>
s21::queue<T>::queue(queue &&q)
    : start_queue_(q.start_queue_),
      end_queue_(q.end_queue_),
      queue_size_(q.queue_size_) {
  q.start_queue_ = nullptr;
  q.end_queue_ = nullptr;
  q.queue_size_ = 0;
}

template <typename T>
s21::queue<T>::~queue() {
  clear();
}

template <typename T>
typename s21::queue<T> &s21::queue<T>::operator=(queue &&q) {
  if (this != &q) {
    clear();
    start_queue_ = q.start_queue_;
    end_queue_ = q.end_queue_;
    queue_size_ = q.queue_size_;
    q.start_queue_ = nullptr;
    q.end_queue_ = nullptr;
    q.queue_size_ = 0;
  }
  return *this;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Функции

template <typename T>
typename s21::queue<T>::const_reference s21::queue<T>::front() {
  if (start_queue_ == nullptr) {
    throw std::out_of_range("out of range");
  }
  return (start_queue_->node_value_);
}

template <typename T>
typename s21::queue<T>::const_reference s21::queue<T>::back() {
  // T null_value = T();
  if (end_queue_ == nullptr) {
    throw std::out_of_range("out of range");
  }
  return end_queue_->node_value_;
}

template <typename T>
bool s21::queue<T>::empty() {
  return queue_size_ == 0;
}

template <typename T>
typename s21::queue<T>::size_type s21::queue<T>::size() {
  return queue_size_;
}

template <typename T>
void s21::queue<T>::push(const_reference value) {
  Node *new_node = new Node(value);

  if (queue_size_ == 0) {
    start_queue_ = new_node;
  } else {
    end_queue_->next_node_ = new_node;
  }

  end_queue_ = new_node;
  queue_size_++;
}

template <typename T>
void s21::queue<T>::pop() {
  if (queue_size_ > 0) {
    Node *next_node = start_queue_->next_node_;
    delete start_queue_;
    start_queue_ = next_node;
    if (queue_size_ == 1) {
      end_queue_ = nullptr;
    }
    queue_size_--;
  }
}

template <typename T>
void s21::queue<T>::swap(queue &other) {
  Node *copy_start_queue = start_queue_;
  Node *copy_end_queue = end_queue_;
  size_type copy_queue_size = queue_size_;
  start_queue_ = other.start_queue_;
  end_queue_ = other.end_queue_;
  queue_size_ = other.queue_size_;
  other.start_queue_ = copy_start_queue;
  other.end_queue_ = copy_end_queue;
  other.queue_size_ = copy_queue_size;
}

template <typename T>
template <class... Args>
void s21::queue<T>::insert_many_back(Args &&...args) {
  for (const auto &value : {args...}) {
    push(value);
  }
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Вспомогательные функции

template <typename T>
void s21::queue<T>::clear() {
  while (queue_size_ > 0) {
    pop();
  }
}
