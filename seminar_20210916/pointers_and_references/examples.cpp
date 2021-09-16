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

  ptr = &object;  // can be initialized with
  std::cout << "ptr: " << ptr << std::endl; // object address in memory
  std::cout << "*ptr: " << *ptr << std::endl; // dereferenced pointer is object
  std::cout << "ptr->size(): " << ptr->size() << std::endl;  // object methods can be calles using ->


  std::string** ptr_to_ptr = &ptr;
  std::cout << "ptr_to_ptr: " << ptr_to_ptr << std::endl; // address of pointer to object
}
