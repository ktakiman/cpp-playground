#include <iostream>

// https://youtu.be/ybaE9qlhHvw?t=118

// --------------------------------------------------------------------------------
// true/false types
// --------------------------------------------------------------------------------

// this is a template type (struct) which hosts a boolean constexpr member
template <bool B>
struct bool_constant {
  static constexpr bool value = B;
};

// instantiation of the template can happen with only 2 possible values.
// a new type is created for each value
using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

// --------------------------------------------------------------------------------
// is_reference
// --------------------------------------------------------------------------------
template <typename T>
struct is_reference : false_type {};  // (private) inheritance

template <typename T>
struct is_reference<T&> : true_type {};

template <typename T>
struct is_reference<T&&> : true_type {};

// --------------------------------------------------------------------------------
// remove_reference
// --------------------------------------------------------------------------------
template <typename T>
struct remove_reference {
  using type = T;
};

template <typename T>
struct remove_reference<T&> {
  using type = T;
};

template <typename T>
struct remove_reference<T&&> {
  using type = T;
};

// --------------------------------------------------------------------------------
// add_lvalue_ref
// --------------------------------------------------------------------------------
template <typename...>
using void_t =
    void;  // Here, actual template parameters are not used at all. This is a
           // way to catch ill-formed type.
           // Also this 'void' can be any type as long as if it matches
           // the second template parameter of alr_impl we're using
           // from add_lvalue_ref

template <typename T, typename Enable>
struct alr_impl {
  using type = T;
};

template <typename T>
struct alr_impl<T, void_t<T&>> {
  using type = T&;
};

template <typename T>
struct add_lvalue_ref : alr_impl<T, void> {};

// add_lvalue_ref<int>  => alr_impl<int, void>   => alr_impl<int, void_t<int&>>
// add_lvalue_ref<int&> => alr_impl<int&, void>  => alr_impl<int&, void_t<int&>>
// add_lvalue_ref<void> => alr_impl<void, void>  => alr_impl<void, Enable>

// --------------------------------------------------------------------------------
// enable_if
// --------------------------------------------------------------------------------
template <bool B, typename T = void>
struct enable_if {
  using type = T;
};

template <typename T>
struct enable_if<false, T> {
  // nothing here !!!
};

// enable_if_t takes a boolean value and produces well-formed type if it's true,
// or ill-formed if false.
template <bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type;

// --------------------------------------------------------------------------------
// test !!
// --------------------------------------------------------------------------------
void TestTypeTraits() {
  std::cout << "Type traits test" << std::endl;
  static_assert(true_type::value);
  static_assert(!false_type::value);

  static_assert(is_reference<int&>::value);
  static_assert(is_reference<int&&>::value);
  static_assert(is_reference<int*&>::value);
  static_assert(!is_reference<int>::value);
  static_assert(!is_reference<int*>::value);

  static_assert(!is_reference<remove_reference<int>::type>::value);
  static_assert(!is_reference<remove_reference<int&>::type>::value);
  static_assert(!is_reference<remove_reference<int&&>::type>::value);

  static_assert(is_reference<add_lvalue_ref<int>::type>::value);
  static_assert(is_reference<add_lvalue_ref<int&>::type>::value);
  static_assert(is_reference<add_lvalue_ref<int&&>::type>::value);
  static_assert(!is_reference<add_lvalue_ref<void>::type>::value);
}
