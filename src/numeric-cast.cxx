#include "numeric-cast.h"

#include <cstdint>
#include <iostream>

namespace Playground {

void TestNumericCast() {
  std::cout << "size of long = " << sizeof(long) << std::endl;

  uint32_t u32 = 0xffffffff;

  int32_t i32 = static_cast<int32_t>(u32);
  uint32_t u32_back = static_cast<uint32_t>(i32);

  std::cout << u32 << std::endl << i32 << std::endl << u32_back << std::endl;

  int i = static_cast<int32_t>(u32);
  uint32_t u32_back2 = static_cast<uint32_t>(i);

  std::cout << i << std::endl << u32_back2 << std::endl;
}

};  // namespace Playground
