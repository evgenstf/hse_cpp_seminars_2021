#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>

#include <memory>


using namespace std;


class Parent {
public:
  void print() {
    cout << "Parent a: " << a << endl;
  }

private:
  int a = 10;
};

class Child : public Parent {
public:
  void print() {
    cout << "Child b: " << b << endl;
  }

private:
  int b = 20;
};

class Child2 : public Parent {
public:
  void print() {
    cout << "Child2 c: " << c << endl;
  }

private:
  int c = 20;
};

int main() {
  Child b;
  b.print();


  vector<unique_ptr<Parent>> objects;
  objects.push_back(make_unique<Child>());
  objects.push_back(make_unique<Child2>());

  for (const auto& ptr : objects) {
    ptr->print();
  }
}
