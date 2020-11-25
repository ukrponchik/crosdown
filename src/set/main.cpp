#include "set.h"

using std::string;

/// Повертає (A ∪ B) \ (A ∩ B)
template <typename T>
set<T> symetric(set<T> &s1, set<T> &s2) {
  return (s1 + s2) - (s1 * s2);
}

int main() {
  set<int> A{1, 3, 0, 4, 5};
  set<int> B{3, 4, 6, 7, 8};
  set<char> C{'a', 'b', 'c', 'f'};
  set<char> D{'b', 'c', 'd', 'e', 'f'};
  set<string> E{"email", "main"};
  set<string> F{"email", "main"};

  std::cout << symetric(A, B) << std::endl;
  std::cout << symetric(C, D) << std::endl;
  std::cout << symetric(E, F) << std::endl;

  return 0;
}