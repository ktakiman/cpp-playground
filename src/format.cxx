#include <iostream>
#include <iomanip>

void TestFormat() {
  int i = 0;
  unsigned char* pc = reinterpret_cast<unsigned char*>(&i); 

  std::cout << std::hex;
  for (int j = 0; j < 8; ++j) {
    std::cout << std::setw(2) << std::setfill('0') << (int)(*(pc + j));
  }
  std::cout << std::endl << std::dec;
}
