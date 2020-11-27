#pragma once
#include <ostream>

template <typename T> class List {
public:
  List();
  ~List();

  void push_back(T data);

  /// Get the size of list
  constexpr int size() const { return Size; }

  /**
   * Індексація
   *
   * @param index   Індекс елемента
   * @return Елемент
   */
  T &operator[](const int index) const;

  /// Видаляє елемент з початку
  void pop_front();

  /// Очищує список
  void clear();

  friend std::ostream &operator<<(std::ostream &os, const List<T> &lst) {
    for (int i = 0; i < lst.size(); i++) {
      os << lst[i] << ' ';
    }
    return os;
  }

  /// The order equal
  bool operator==(const List<T> &rht) {
    Node *current = this->head;
    Node *otherCurrent = rht.head;

    while (current->next && otherCurrent->next) {
      if (current->data != otherCurrent->data)
        return false;
      otherCurrent = otherCurrent->next;
      current = current->next;
    }
    return true;
  }

  /**
   * TODO:
   * -[ ] insert
   * -[ ] delete
   * -[ ] pop_back, push_front
   * -[ ] initializer CTOR
   */

private:
  // Клас вузол
  class Node {
  public:
    Node *next; // Вказівник на наступну область пам'яті
    T data; // Данні

    Node(T data = T{}, Node *next = nullptr) {
      this->data = data;
      this->next = next;
    }
  };

  Node *head; // Початок списка
  int Size;   // Розмір списка
};

#include "./list.tpp"
