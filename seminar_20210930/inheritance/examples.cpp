#include <iostream>
#include <cstdio>
#include <fstream>


using namespace std;


class ParentA {
public:
  int a = 0xaaaaaaaa;
};

class ChildB : public ParentA {
public:
  int b = 0xbbbbbbbb;
};


class ChildC : public ParentA {
public:
  int c = 0xcccccccc;
};


int main() {
  ParentA a;
  ChildB b;
  ChildC c;

  {
    ofstream file;
    file.open("parent_a.bin", ios::out | ios::binary);
    file.write(reinterpret_cast<char*>(&a), sizeof(a));
  }

  {
    ofstream file;
    file.open("child_b.bin", ios::out | ios::binary);
    file.write(reinterpret_cast<char*>(&b), sizeof(b));
  }

  {
    ofstream file;
    file.open("child_c.bin", ios::out | ios::binary);
    file.write(reinterpret_cast<char*>(&c), sizeof(c));
  }
}
