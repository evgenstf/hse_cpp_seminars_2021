// article to read: https://www.educative.io/edpresso/differences-between-pointers-and-references-in-cpp

#include <string>
#include <iostream>

int main() {
  std::string object = "string";

  std::string& ref = object;  // alias to object.  we can change object using this reference.
                              // cannot be not initialized (NULL). cannot be initialized by another object.

  ref = "changed_using_ref";
  std::cout << "object: " << object << std::endl;
  std::cout << "ref: " << ref << std::endl;




  std::string* ptr = NULL;  // independent object. can be not initialized (using NULL keyword).
  std::cout << "ptr: " << ptr << std::endl; // can be printed


  /*
  int* a, *b, *c; // bad

  int* a; // good
  int* b;
  int* c;
  */



  if (ptr) {
    std::cout << "initialised\n";
  } else {
    std::cout << "not initialised\n";
  }

  ptr = &object;  // can be initialized with
  std::cout << "ptr: " << ptr << std::endl; // object address in memory
  std::cout << "*ptr: " << *ptr << std::endl; // dereferenced pointer is object
  std::cout << "ptr->size(): " << ptr->size() << std::endl;  // object methods can be calles using ->

  std::string** ptr_to_ptr = &ptr;
  std::cout << "ptr_to_ptr: " << ptr_to_ptr << std::endl; // address of pointer to object


  int a[100]; // a -- int*

  std::cout << "int size: " << sizeof(int) << std::endl;
  std::cout << "a: " << a << std::endl;
  std::cout << "a[0]: " << a[0] << std::endl;

  char* ptr_char = object.data();
  std::cout << ptr_char[0] << ptr_char[1] << ptr_char[2] << std::endl;
}
