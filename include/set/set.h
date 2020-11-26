#pragma once
#include <initializer_list>
#include <iostream>
#include <vector>

/**
 * @brief Class set
 * @class set @file set.h
 *
 * @ingroup Числа та символи
 * @ingroup Рядки
 *
 * @tparam T число, символ, рядок
 */
template <typename T> class set {
private:
  std::vector<T> elems;

public:
  set() {}

  /// Copy CTOR
  set(const set &ob) {
    for (const auto &el : ob.elems) {
      elems.push_back(el);
    }
  }

  /// Initilaizer CTOR
  set(const std::initializer_list<T> &list) {
    for (const auto &el : list) {
      elems.push_back(el);
    }
  }

  /// Добавляє елемент до множини
  void add(T el) {
    elems.push_back(el);
  }

  /// Оператор присвоєння
  set<T>& operator=(const set<T> &obj) {
    elems.clear();
    for (const auto &el : elems) {
      elems.push_back(el);
    }

    return *this;
  }

  /// Оператор індексації. Видаляє елемент з множини та повертає його.
  T operator[](T el) {
    for (size_t i = 0; i < elems.size(); i++) {
      if (el == elems[i]) {
        T tmp = elems[i];
        elems.erase(elems.begin() + i);
        return tmp;
      }
    }
    return T{};
  }

  /// Повертає true, якщо елемент належить множині
  bool operator()(const T &el) const {
    for (const auto &elem : elems) {
      if (elem == el) return true;
    }
    return false;
  }

  friend std::ostream &operator<<(std::ostream &os, const set &s) {
    for (const auto &el : s.elems) {
      os << el << " ";
    }
    return os;
  }

  /// Return true if set is empty
  bool operator!() {
    return elems.size() == 0;
  }

  /// Перетин (∩)
  set<T> operator*(const set<T> &obj) {
    set<T> tmp;

    for (const auto &el : elems) {
      if (obj(el)) tmp.add(el);
    }

    if (!tmp)
      return set<T>{};
    return tmp;
  }

  /// Різниця (\)
  set<T> operator-(const set<T> &obj) {
    set<T> tmp;

    for (const auto &el : elems) {
      if (!obj(el)) tmp.add(el);
    }

    if (!tmp)
      return set<T>{};
    return tmp;
  }

  /// Об'єднання (∪)
  set<T> operator+(const set<T> &obj) {
    set<T> tmp;

    for (const auto &el : elems) {
      tmp.add(el);
    }

    for (const auto &el : obj.elems) {
      if (!tmp(el)) tmp.add(el);
    }

    if (!tmp) return set<T>{};
    return tmp;
  }

  /// Повертає (A ∪ B) \ (A ∩ B)
  set<T> operator^(const set<T> &obj) {
    return (*this + obj) - ((*this) * obj);
  }
};
