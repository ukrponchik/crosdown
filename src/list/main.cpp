#include "list.hpp"
#include <iostream>

int main() {
  List<int> lst1;
  lst1.push_back(5);
  lst1.push_back(3);
  lst1.push_back(4);

  List<int> lst2;
  lst2.push_back(4);
  lst2.push_back(3);
  lst2.push_back(5);

  std::cout << lst1 << std::endl;
  std::cout << lst2 << std::endl;

  std::cout << (lst1 == lst2) << std::endl;

  return 0;
}