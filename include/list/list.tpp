template <typename T> List<T>::List() : Size{0}, head(nullptr) {}

template <typename T> List<T>::~List() {
  clear();
}

template <typename T> void List<T>::push_back(T data) {
  if (head == nullptr) {
    head = new Node{data};
  } else {
    Node *current = this->head;
    while (current->next) {
      current = current->next;
    }
    current->next = new Node{data};
  }
  Size++;
}

template <typename T> T &List<T>::operator[](const int index) const {
  int counter = 0;
  Node *current = this->head;
  while (current != nullptr) {
    if (counter == index) {
      return current->data;
    }
    current = current->next;
    counter++;
  }
}

template <typename T> void List<T>::pop_front() {
  Node *tmp = head;
  head = head->next;

  delete tmp;

  Size--;
}

template <typename T> void List<T>::clear() {
  while (Size) {
    pop_front();
  }
}
