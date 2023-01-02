#include "pipe.h"

#include <iostream>

namespace Playground {

void TestPipe() {
  std::string s;
  while (std::cin >> s) {
    std::cout << "GOT: " << s << std::endl;
  }
}

};  // namespace Playground
