#include "meta-programming.h"

#include <iostream>
#include <string>
#include <type_traits>
#include <typeinfo>

// https://www.youtube.com/watch?v=Am2is2QCvxY

namespace Playground {

//------------------------------------------------------------------------------
// greatest common devisor
//------------------------------------------------------------------------------
template <unsigned int M, unsigned int N>
struct gcd {
  static_assert(M != 0);
  // does this need to be static type?
  constexpr static int value = gcd<N, M % N>::value;
};

// specialization to stop the recursiion
template <unsigned int M>
struct gcd<M, 0> {
  static_assert(M != 0);
  constexpr static int value = M;
};

void TestGcd() {
  std::cout << "gcd of 168 and 180 = " << gcd<168, 180>::value << std::endl;
}

//------------------------------------------------------------------------------
// identity meta-function, used as a base class expose T as ::type
//
//------------------------------------------------------------------------------
template <typename T>
struct type_is {
  // can also do 'typedef T type' here
  using type = T;
};

//------------------------------------------------------------------------------
// remove const or volatile
// can 'T" become 'const (type)'??????
// std::remove_const, std::remove_volatile, std::remove_cv provides these
// metafunctions
//------------------------------------------------------------------------------
template <typename T>
struct remove_const : type_is<T> {};

// specialization to handle the 'remove' part
template <typename T>
struct remove_const<const T> : type_is<T> {};

template <typename T>
using remove_const_t = typename remove_const<T>::type;

template <typename T>
struct remove_volatile : type_is<T> {};

// specialization to handle the 'remove' part
template <typename T>
struct remove_volatile<volatile T> : type_is<T> {};

template <typename T>
struct RemoveConstTest {
  RemoveConstTest(T* p) : v(*p), ncv(*p) {}
  T v;
  remove_const_t<T> ncv;
};

void TestRemoveConst() {
  int i = 1;
  int* p = &i;

  RemoveConstTest test1(p);
  test1.v += 10;    // test.v is int so we can modify it
  test1.ncv += 10;  // test.ncv is int so we can modify it

  const int* cp = &i;
  RemoveConstTest test2(cp);
  // test2.v += 10;   // test.v is const int so this would become an error if
  // uncommented out
  test2.ncv += 10;  // test.ncv is int so we can modify it
}

//------------------------------------------------------------------------------
// type A or B (this is what std::conditional does)
//------------------------------------------------------------------------------

template <bool, typename T, typename>
struct conditional : type_is<T> {};

template <typename T,
          typename U>  // 'bool' must not be included here, this is tricky...
struct conditional<false, T, U> : type_is<U> {};

//------------------------------------------------------------------------------
// type A or nothing (this is what std::enable_if does, and a building block of
// SFINAE)
//------------------------------------------------------------------------------
template <bool, typename T>
struct enable_if : type_is<T> {};

template <typename T>
struct enable_if<false, T> {};  // no ::type defined

//------------------------------------------------------------------------------
// integral constant
//------------------------------------------------------------------------------
template <typename T, T v>
struct integral_constant {
  static constexpr T value = v;
};

template <typename T>
struct is_constant : integral_constant<bool, false> {};

template <typename T>
struct is_constant<const T> : integral_constant<bool, true> {};

//------------------------------------------------------------------------------
void TestMetaProgramming() {
  TestGcd();
  TestRemoveConst();
}

};  // namespace Playground
