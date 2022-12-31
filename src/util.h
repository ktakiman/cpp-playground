#pragma once

#include <cstddef>
#include <iomanip>
#include <iostream>

namespace Playground {

template <typename T>
void DumpMemory(std::ostream& os, const T* addr, const char* title = nullptr,
                int bytes_per_line = 8) {
  std::string indent;
  if (title != nullptr) {
    os << ">> " << title << std::endl << std::endl;
    indent = "  ";
  }
  int offset = 0;
  auto size = sizeof(T);
  auto bytes = reinterpret_cast<const std::byte*>(addr);
  for (int line = 0; line < (size + bytes_per_line - 1) / bytes_per_line;
       line++) {
    os << indent << "0x" << std::setw(16) << std::setfill('0') << std::hex
       << bytes + offset << ": ";

    for (int pos = 0; pos < bytes_per_line && offset < size; pos++) {
      if (pos % 4 == 0) {
        os << std::setw(1) << ' ';
      }
      os << std::setw(2) << std::to_integer<unsigned short>(*(bytes + offset))
         << ' ';
      offset++;
    }

    os << std::endl;
  }

  os << std::endl;
}

struct Chatty {
  // ref-qualifiers added in c++11
  // https://akrzemi1.wordpress.com/2014/06/02/ref-qualifiers/
  void TellLorR(const char* prefix) &;
  void TellLorR(const char* prefix) &&;
};

}  // namespace Playground
