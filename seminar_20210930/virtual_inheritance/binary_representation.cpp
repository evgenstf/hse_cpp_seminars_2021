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
  int a = 0xaaaaaaaa;
};

class Child : public Parent {
public:
  virtual void print() {
    cout << "Child b: " << b << endl;
  }

private:
  int b = 0xbbbbbbbb;
};

int main() {
  Child object;
  {
    ofstream file;
    file.open("binary_representation.bin", ios::out | ios::binary);
    file.write(reinterpret_cast<char*>(&object), sizeof(object));
  }
}
