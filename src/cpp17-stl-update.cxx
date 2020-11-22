#include "cpp17-stl-update.h"

#include <iostream>
#include <optional>
#include <string>
#include <variant>
#include <vector>

namespace Playground {

void TestVariant() {
  std::variant<int, double> v1, v2;

  v1 = 3;

  // will throw std::bad_variant_access
  try {
    std::cout << std::get<double>(v1) << std::endl;
  } catch (const std::exception& e) {
    std::cout << "exception thrown (expected) msg = " << e.what() << std::endl;
  }

  if (auto v = std::get_if<int>(&v1)) {
    std::cout << v << " " << *v << std::endl;
  }

  v2 = 3.14;

  std::cout << "v1 holds the type at index " << v1.index() << std::endl;
  std::cout << "v2 holds the type at index " << v2.index() << std::endl;

  std::cout << "v1 holds int? " << std::holds_alternative<int>(v1) << std::endl;
  std::cout << "v1 holds double? " << std::holds_alternative<double>(v1)
            << std::endl;

  std::cout << "v2 holds int? " << std::holds_alternative<int>(v2) << std::endl;
  std::cout << "v2 holds double? " << std::holds_alternative<double>(v2)
            << std::endl;
}

}  // namespace Playground
