#include <string>
#include <iostream>

int main() {
  // int x = 0;  // non-const object

  const int x1 = 0; // const object
  int const x2 = 0; // const object as well


  std::string str = "string";

  /*
  std::string& ref = str; // non-const ref, the object can be changed
  ref = "changed_using_ref";
  std::cout << "str: " << str << std::endl;

  const std::string& ref1 = str; // const reference to non-const object
  std::string const& ref2 = str; // const reference to non-const object as well
  */

  std::string another = "another_string";
  /*
  std::string* ptr = &str; // non-const pointer to non-const object
  *ptr = "changed_using_ptr";
  std::cout << "str: " << str << std::endl;
  std::cout << "*ptr: " << *ptr << std::endl;

  ptr = &another;
  std::cout << "str: " << str << std::endl;
  std::cout << "*ptr: " << *ptr << std::endl;

  const std::string* ptr1 = &str; // non-const pointer to const object
  std::string const* ptr2 = &str; // non-const pointer to const object
  ptr1 = &another;
  std::cout << "*ptr1: " << *ptr1 << std::endl;
  */



  /*
  std::string* const ptr3 = &str; // const pointer (!), not object (!)
  *ptr3 = "changed_using_const_ptr";
  std::cout << "str: " << str << std::endl;

  const std::string* const ptr4 = &str; // const pointer to const object
  */

  // advanced examples:
  volatile int x3 = 0;  // volatile object (cannot be optimized by compiler)
}
