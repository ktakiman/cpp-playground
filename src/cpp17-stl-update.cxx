#include "cpp17-stl-update.h"

#include <any>
#include <climits>
#include <iostream>
#include <optional>
#include <string>
#include <variant>
#include <vector>

#include "util.h"

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

void TestOptional() {
  std::optional<int> v1;
  std::optional<int> v2(std::nullopt);
  std::optional<int> v3(1);
  auto v4 = std::make_optional(2);
  // auto v5 = std::make_optional<int>(std::nullopt);  // does not compile

  std::cout << "v1 has value: " << v1.has_value() << std::endl;
  std::cout << "v2 has value: " << v2.has_value() << std::endl;
  std::cout << "v3 has value: " << v3.has_value() << std::endl;
  std::cout << "v4 has value: " << v4.has_value() << std::endl;
  // std::cout << "v5 has value: " << v5.has_value() << std::endl;

  std::cout << "v1 with 'or' value: " << v1.value_or(INT_MIN) << std::endl;
  std::cout << "v3 with 'or' value: " << v3.value_or(INT_MIN) << std::endl;

  try {
    std::cout << v1.value();
  } catch (const std::exception& e) {
    std::cout << "v1.value() threw an exception: " << e.what() << std::endl;
  }

  auto MakeHalf = [](std::optional<int> param1) {
    return param1.value_or(1) % 2 == 0 ? std::make_optional(param1.value() / 2)
                                       : std::nullopt;
  };

  std::cout << "half of 10: " << MakeHalf(10).value_or(INT_MIN) << std::endl;
  std::cout << "half of 7: " << MakeHalf(7).value_or(INT_MIN) << std::endl;
  std::cout << "half of std::optnulll: "
            << MakeHalf(std::optional<int>()).value_or(INT_MIN) << std::endl;

  auto s1 = std::make_optional(std::string("hi"));

  // use -> to call a method on contained object
  std::cout << "length of s1: " << s1->length() << std::endl;

  std::cout << "size of int and std::optional<int>: " << sizeof(int) << ", "
            << sizeof(std::optional<int>) << std::endl;
  std::cout << "size of std::string and std::optional<std::string>: "
            << sizeof(std::string) << ", " << sizeof(std::optional<std::string>)
            << std::endl;
}

void TestAny() {
  /* any1 = std::string("hi"); */
  /* any1 = std::vector<std::string> { "this", "is", "like", "magic" }; */

  // std::any takes up 16 bytes,
  // - first 8 bytes is an address to a behind-scene static function specific to
  //   the type assigned
  // - second 8 bytes is a raw value if the value can be stored within 8 bytes,
  //   otherwise an address to the object created on heap
  std::cout << "size of std::any: " << sizeof(std::any) << std::endl
            << std::endl;

  std::any empty_any;

  DumpMemory(std::cout, &empty_any, "empty_std::any");

  int i1 = 0x1234abcd;
  int i2 = -1;
  std::any any_int1 = i1;
  std::any any_int2 = i2;

  DumpMemory(std::cout, &i1, "int == 0x1234abcd");
  DumpMemory(std::cout, &any_int1, "std::any<int> == 0x1234abcd");

  DumpMemory(std::cout, &i2, "int == -1");
  DumpMemory(std::cout, &any_int2, "std::any<int> == -1");

  std::string s1 = "foo bar";
  std::string s2 = "foo bar too var chuu bee";
  std::any any_s1 = s1;
  std::any any_s2 = s2;

  std::cout << "size of std::string: " << sizeof(std::string) << std::endl
            << std::endl;

  DumpMemory(std::cout, &s1, "std::string = 'foo bar'");
  DumpMemory(std::cout, &any_s1, "std::any<std::string> = 'foo bar'");

  // peek under the hood

#ifndef _MSC_VER
  std::string* ps1 =
      *reinterpret_cast<std::string**>(reinterpret_cast<char*>(&any_s1) + 8);
  DumpMemory(std::cout, ps1, "dynamic allocated by std::any");
#endif

  auto takeAny = [](std::any& any) {
    try {
      std::cout << "any_cast<std::string>(&) : "
                << std::any_cast<std::string>(any) << std::endl;
    } catch (const std::bad_any_cast& e) {
      std::cout << e.what() << std::endl;
    }

    if (auto s = std::any_cast<std::string>(&any)) {
      std::cout << "any_cast<std::string>(*) : " << s->c_str() << std::endl;
    } else {
      std::cout << "any_cast<std::string>(*) : returned nullptr" << std::endl;
    }
  };

  takeAny(any_int1);
  takeAny(any_s1);
}

}  // namespace Playground
