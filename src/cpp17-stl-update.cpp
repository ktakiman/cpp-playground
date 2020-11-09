#include "cpp17-stl-update.h"

#include <iostream>
#include <variant>
#include <vector>
#include <string>

namespace Playground {

void TestVariant() {

  std::variant<int, double> v1, v2, v3;

  v1 = 3;
  v2 = 3.14;

  std::cout << std::get<int>(v1) << " " << std::get<double>(v1) << std::endl;
}

}
