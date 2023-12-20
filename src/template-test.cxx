#pragma once

#include <iostream>
#include <type_traits>

template <typename T>
void check_type(T t, const char* what) {
  std::cout << what << " ~ typeid(T).name(): " << typeid(t).name() << std::endl;
  std::cout << "  std::is_integral?              " << std::is_integral<T>::value
            << std::endl;
  std::cout << "  std::is_floating_point?        "
            << std::is_floating_point<T>::value << std::endl;
  std::cout << "  std::is_arithmetic?            "
            << std::is_arithmetic<T>::value << std::endl;
  std::cout << "  std::is_enum?                  " << std::is_enum<T>::value
            << std::endl;
  std::cout << "  std::is_default_constructible? "
            << std::is_default_constructible<T>::value << std::endl;

  std::cout << std::endl;
}

enum class EMyEnum { none, hoo, bar };

class MyClass {};

struct MyStruct {};

void TestTemplate() {
  check_type('a', "char");
  check_type(16, "int");
  check_type(16u, "unsigned int");
  check_type(16l, "long");
  check_type(16ul, "unsigned long");
  check_type(16ll, "long long");
  check_type(16ull, "usigned long long");
  check_type(3.14f, "float");
  check_type(3.14, "double");
  check_type(EMyEnum::none, "enum");
  check_type(MyClass{}, "MyClass");
  check_type(MyStruct{}, "MyStruct");
}
