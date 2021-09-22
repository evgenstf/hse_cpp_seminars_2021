#include <utility>
#include <iostream>
#include <string>
#include <typeinfo>

template<typename T>
void print_type(T x) {
  std::cout << x << " is ";
  if (std::is_same_v<T, int>) {
    std::cout << "int";
  } else if (std::is_same_v<T, double>) {
    std::cout << "double";
  } else {
    std::cout << "unknown";
  }
  std::cout << std::endl;
}

int main() {
  auto a = 1 + 2;      // type of a is int
  print_type(a);

  auto b = 1 + 1.2;    // type of b is double
  print_type(b);



  std::string str = "string";

  auto copy_str = str;  // makes a copy
  static_assert(std::is_same_v<decltype(copy_str), std::string>);

  const auto const_str = str;  // makes a constant copy
  static_assert(std::is_same_v<decltype(const_str), const std::string>);

  auto& ref_str = str;  // makes a reference
  static_assert(std::is_same_v<decltype(ref_str), std::string&>);

  const auto& const_ref_str = str;  // makes a constance reference
  static_assert(std::is_same_v<decltype(const_ref_str), const std::string&>);

  auto* ptr_str = &str;  // makes a pointer
  static_assert(std::is_same_v<decltype(ptr_str), std::string*>);

  const auto* const_ptr_str = &str;  // makes a constant pointer
  static_assert(std::is_same_v<decltype(const_ptr_str), const std::string*>);



  auto copy_str2 = const_ref_str;  // auto doesn't capture references and consts!!!
  static_assert(std::is_same_v<decltype(copy_str2), std::string>);


  decltype(const_ref_str) copy_str3 = const_ref_str;  // decltype do capture references and consts
  static_assert(std::is_same_v<decltype(copy_str3), const std::string&>);

  return 0;
}
