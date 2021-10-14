#include <iostream>
#include <cstdio>
#include <fstream>


using namespace std;


class GrandParentA {
public:
  int a = 0xaaaaaaaa;
};

class ParentB: virtual public GrandParentA {
public:
  int b = 0xbbbbbbbb;
};


class ParentC: virtual public GrandParentA {
public:
  int c = 0xcccccccc;
};


class ChildD : public ParentB, public ParentC {
public:
  int d = 0xdddddddd;
};


int main() {
  ChildD d;

  {
    ofstream file;
    file.open("child_d.bin", ios::out | ios::binary);
    file.write(reinterpret_cast<char*>(&d), sizeof(d));
  }
}
