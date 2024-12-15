// ________________________________________________________
// Node
template <typename T>
s21::stack<T>::Node::Node(value_type value, Node *previous_node) {
  previous_node_ = previous_node;
  node_value_ = value;
}

template <typename T>
s21::stack<T>::Node::Node(const Node &other)
    : previous_node_(other.previous_node_), node_value_(other.node_value_) {}

template <typename T>
s21::stack<T>::Node::Node(Node &&other)
    : previous_node_(other.previous_node_), node_value_(other.node_value_) {
  other.previous_node_ = nullptr;
}

template <typename T>
s21::stack<T>::Node::~Node() {}

// ________________________________________________________
// stack

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Конструкторы

template <typename T>
s21::stack<T>::stack()
    : start_stack_(nullptr), end_stack_(nullptr), stack_size_(0) {}

template <typename T>
s21::stack<T>::stack(std::initializer_list<value_type> const &items)
    : start_stack_(nullptr), end_stack_(nullptr), stack_size_(0) {
  for (auto new_iterator = items.begin(); new_iterator != items.end();
       new_iterator++) {
    push(*new_iterator);
  }
}

template <typename T>
s21::stack<T>::stack(const stack &s)
    : start_stack_(nullptr), end_stack_(nullptr), stack_size_(0) {
  Node *copy_node = s.end_stack_;
  for (size_t i = 0; i < s.stack_size_; i++) {
    Node *new_node = new Node(copy_node->node_value_);
    if (i == 0) {
      start_stack_ = new_node;
      end_stack_ = new_node;
    } else {
      start_stack_->previous_node_ = new_node;
      start_stack_ = new_node;
    }
    copy_node = copy_node->previous_node_;
    stack_size_++;
  }
}

template <typename T>
s21::stack<T>::stack(stack &&s)
    : start_stack_(s.start_stack_),
      end_stack_(s.end_stack_),
      stack_size_(s.stack_size_) {
  s.start_stack_ = nullptr;
  s.end_stack_ = nullptr;
  s.stack_size_ = 0;
}

template <typename T>
s21::stack<T>::~stack() {
  clear();
}

template <typename T>
typename s21::stack<T> &s21::stack<T>::operator=(stack &&s) {
  if (this != &s) {
    clear();
    start_stack_ = s.start_stack_;
    end_stack_ = s.end_stack_;
    stack_size_ = s.stack_size_;
    s.start_stack_ = nullptr;
    s.end_stack_ = nullptr;
    s.stack_size_ = 0;
  }
  return *this;
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Функции

template <typename T>
typename s21::stack<T>::const_reference s21::stack<T>::top() {
  // segmentation fault - в оригинале
  return end_stack_->node_value_;
}

template <typename T>
bool s21::stack<T>::empty() {
  return stack_size_ == 0;
}

template <typename T>
typename s21::stack<T>::size_type s21::stack<T>::size() {
  return stack_size_;
}

template <typename T>
void s21::stack<T>::push(const_reference value) {
  Node *new_node = new Node(value);

  if (stack_size_ == 0) {
    start_stack_ = new_node;
  } else {
    new_node->previous_node_ = end_stack_;
  }

  end_stack_ = new_node;
  stack_size_++;
}

template <typename T>
void s21::stack<T>::pop() {
  if (stack_size_ > 0) {
    Node *previous_node = end_stack_->previous_node_;
    delete end_stack_;
    end_stack_ = previous_node;
    if (stack_size_ == 1) {
      start_stack_ = nullptr;
    }
    stack_size_--;
  }
}

template <typename T>
void s21::stack<T>::swap(stack &other) {
  Node *copy_start_stack = start_stack_;
  Node *copy_end_stack = end_stack_;
  size_type copy_stack_size = stack_size_;
  start_stack_ = other.start_stack_;
  end_stack_ = other.end_stack_;
  stack_size_ = other.stack_size_;
  other.start_stack_ = copy_start_stack;
  other.end_stack_ = copy_end_stack;
  other.stack_size_ = copy_stack_size;
}

template <typename T>
template <class... Args>
void s21::stack<T>::insert_many_front(Args &&...args) {
  Node *start_stack_node = start_stack_;
  Node *last_node = nullptr;
  for (const auto &value : {args...}) {
    Node *new_node = new Node(value);
    if (last_node == nullptr) {
      start_stack_ = new_node;
    } else {
      new_node->previous_node_ = last_node;
    }
    last_node = new_node;
    stack_size_++;
    if (start_stack_node == nullptr) {
      end_stack_ = new_node;
    } else {
      start_stack_node->previous_node_ = new_node;
    }
  }
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Вспомогательные функции

template <typename T>
void s21::stack<T>::clear() {
  while (stack_size_ > 0) {
    pop();
  }
}