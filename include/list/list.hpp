#pragma once
#include <ostream>

template <typename T> class List {
public:
  List();
  ~List();

  void push_back(T data);

  /// Get the size of list
  constexpr int size() const { return Size; }

  T& operator[](const int index) const;

  void pop_front();

  void clear();

  friend std::ostream &operator<<(std::ostream &os, const List<T> &lst) {
    for (int i = 0; i < lst.size(); i++) {
      os << lst[i] << ' ';
    }
    return os;
  }

  bool operator==(const List<T> &rht) {
    Node *current = this->head;
    Node *otherCurrent = rht.head;

    while (current->next && otherCurrent->next) {
      if (current->data != otherCurrent->data) return false;
      otherCurrent = otherCurrent->next;
      current = current->next;
    }
    return true;
  }

private:
  class Node {
  public:
    Node *next;
    T data;

    Node(T data = T{}, Node *next = nullptr) {
      this->data = data;
      this->next = next;
    }
  };

  Node *head;
  int Size;
};


#include "./list.tpp"