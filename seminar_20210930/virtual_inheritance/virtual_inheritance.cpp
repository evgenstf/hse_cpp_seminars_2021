#include <iostream>
#include <cstdio>
#include <fstream>

#include <memory>


using namespace std;


class Parent {
public:
  virtual void print() {
    cout << "Parent a: " << a << endl;
  }

private:
  int a = 10;
};

class Child : public Parent {
public:
  virtual void print() {
    cout << "Child b: " << b << endl;
  }

private:
  int b = 20;
};

int main() {
  unique_ptr<Parent> object = make_unique<Child>();
  object->print();
}
