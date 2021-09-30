#include <iostream>
#include <cstdio>
#include <fstream>


using namespace std;


class ParentA {
public:
  int a = 0xaaaaaaaa;
};

class ParentB {
public:
  int b = 0xbbbbbbbb;
};


class ChildC : public ParentA, private ParentB {
public:
  int c = 0xcccccccc;
};


int main() {
  ChildC c;

  {
    ofstream file;
    file.open("child_c.bin", ios::out | ios::binary);
    file.write(reinterpret_cast<char*>(&c), sizeof(c));
  }
}
