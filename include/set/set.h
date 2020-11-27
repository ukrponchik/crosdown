#pragma once
#include <initializer_list>
#include <iostream>
#include <string>
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
  /// \param el Елемент
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
    if (!s) {
      os << "\u2205";
      return os;
    }
    os << "{ ";
    for (const auto &el : s.elems) {
      os << el << ", ";
    }
    os << "}";
    return os;
  }

  /// Повертаж true, якщо множина пуста
  bool operator!() const {
    return elems.size() == 0;
  }

  /// Перетин (∩)
  set<T> operator*(const set<T> &obj) {
    set<T> tmp;

    for (const auto &el : elems) {
      if (obj(el)) tmp.add(el);
    }

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

  /// Повертає (A ∪ B) \ (A ∩ B). @see Симетрична різниця
  /// https://uk.wikipedia.org/wiki/%D0%A1%D0%B8%D0%BC%D0%B5%D1%82%D1%80%D0%B8%D1%87%D0%BD%D0%B0_%D1%80%D1%96%D0%B7%D0%BD%D0%B8%D1%86%D1%8F_%D0%BC%D0%BD%D0%BE%D0%B6%D0%B8%D0%BD#:~:text=%D0%A1%D0%B8%D0%BC%D0%B5%D1%82%D1%80%D0%B8%D1%87%D0%BD%D0%B0%20%D1%80%D1%96%D0%B7%D0%BD%D0%B8%D1%86%D1%8F%20%D0%B4%D0%B2%D0%BE%D1%85%20%D0%BC%D0%BD%D0%BE%D0%B6%D0%B8%D0%BD%20%E2%80%94%20%D1%82%D0%B5%D0%BE%D1%80%D0%B5%D1%82%D0%B8%D0%BA%D0%BE,%D0%BD%D0%B0%D0%BB%D0%B5%D0%B6%D0%B0%D1%82%D1%8C%20%D0%BE%D0%B4%D0%BD%D0%BE%D1%87%D0%B0%D1%81%D0%BD%D0%BE%20%D0%BE%D0%B1%D0%BE%D0%BC%20%D0%B2%D0%B8%D1%85%D1%96%D0%B4%D0%BD%D0%B8%D0%BC%20%D0%BC%D0%BD%D0%BE%D0%B6%D0%B8%D0%BD%D0%B0%D0%BC.&text=%D0%9D%D0%B0%20%D0%BF%D0%B8%D1%81%D1%8C%D0%BC%D1%96%20%D0%B4%D0%BB%D1%8F%20%D0%BF%D0%BE%D0%B7%D0%BD%D0%B0%D1%87%D0%B5%D0%BD%D0%BD%D1%8F%20%D1%81%D0%B8%D0%BC%D0%B5%D1%82%D1%80%D0%B8%D1%87%D0%BD%D0%BE%D1%97,%D0%B2%D0%B8%D0%BA%D0%BE%D1%80%D0%B8%D1%81%D1%82%D0%BE%D0%B2%D1%83%D1%94%D1%82%D1%8C%D1%81%D1%8F%20%D0%BF%D0%BE%D0%B7%D0%BD%D0%B0%D1%87%D0%B5%D0%BD%D0%BD%D1%8F%20A%20%E2%96%B3%20B.
  set<T> operator^(const set<T> &obj) {
    return (*this + obj) - ((*this) * obj);
  }
};
