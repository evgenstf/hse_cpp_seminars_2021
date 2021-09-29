#include <iostream>
#include <cstdio>
#include <fstream>


using namespace std;


struct Struct {
  char c1 = 0xfA; // 1 byte
  int x = 0xfffffffB;  // 4 byte
  char c2 = 0xfC;  // 1 byte
};

#pragma pack(push, 1)
struct PackedStruct {
  char c1 = 0xfA;
  int x = 0xfffffffB;
  char c2 = 0xfC;
};
#pragma pack(pop)



class Class {
public:
  Class(int a, int b, int c):
    a_(a), b_(b), c_(c) {}


  void print() {
  }

private:
  int a_;
  int b_;
  int c_;

protected:
  int d_ = 0;
  int e_ = 1;
  int f_ = 2;
};


class Child : public Class {
public:
  void print() {
    // cout << a_;
    cout << d_ << ' ' << e_ << ' ' << f_ << endl;
  }
};


int main() {
  Struct st;

  cout << "st size: " << sizeof(st) << endl;

  ofstream file;
  file.open("st.bin", ios::out | ios::binary);
  file.write(reinterpret_cast<char*>(&st), sizeof(st));


  PackedStruct packed_st;

  cout << "packed_st size: " << sizeof(packed_st) << endl;

  ofstream file2;
  file2.open("packed_st.bin", ios::out | ios::binary);
  file2.write(reinterpret_cast<char*>(&packed_st), sizeof(packed_st));
}
