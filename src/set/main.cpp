#include "set.h"

using std::string;
using std::cout;
using std::endl;

int main() {
  set<int> A{1, 3, 0, 4, 5};
  set<int> B{3, 4, 6, 7, 8};
  set<char> C{'a', 'b', 'c', 'f'};
  set<char> D{'b', 'c', 'd', 'e', 'f'};
  set<string> E{"email", "main"};
  set<string> F{"email", "main"};

  cout << (A ^ B) << endl;
  cout << (C ^ D) << endl;
  cout << (E ^ F) << endl;

  return 0;
}