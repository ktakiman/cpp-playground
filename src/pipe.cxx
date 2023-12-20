#include "pipe.h"

#include <iostream>
#include <string>

namespace Playground {

void TestPipe() {
  std::cin.unsetf(std::ios_base::skipws);
  // char c;
  // while (std::cin >> c) {
  //   std::cout << c;
  // }
  std::string s;
  while (std::getline(std::cin, s)) {
    std::cout << s;
  }
  // while (std::cin >> s) {
  //   std::cout << s;
  // }
}

};  // namespace Playground
