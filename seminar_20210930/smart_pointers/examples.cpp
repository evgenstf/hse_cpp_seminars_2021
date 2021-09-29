#include <iostream>
#include <cstdio>
#include <fstream>

#include <memory>


using namespace std;

class Class {
  int x;
  int y;
  int z;
};

int main() {
  {
    Class* pointer = new Class;
  }  // memory leak :(

  {
    Class* pointer = new Class;
    delete pointer;
  }  // ok

  {
    Class* pointer = new Class[5];
    // delete object; -- UB:(
    delete[] pointer; // ok
  }

  {
    unique_ptr<Class> pointer = make_unique<Class>();
  }

  std::cout << "shared ptr: \n";
  {
    shared_ptr<Class> pointer = make_shared<Class>();
    std::cout << pointer.use_count() << std::endl;
    {
      shared_ptr<Class> pointer_copy = pointer;
      std::cout << pointer.use_count() << std::endl;
    }
    std::cout << pointer.use_count() << std::endl;
  }


  std::cout << "weak ptr: \n";
  {
    shared_ptr<Class> pointer = make_shared<Class>();
    std::cout << pointer.use_count() << std::endl;
    {
      weak_ptr<Class> weak_pointer1 = pointer;
      weak_ptr<Class> weak_pointer2 = pointer;
      std::cout << "shared counter: " << pointer.use_count() << std::endl;
      std::cout << "weak counter: " << weak_pointer1.use_count() << std::endl;
    }
    std::cout << pointer.use_count() << std::endl;
  }
}
