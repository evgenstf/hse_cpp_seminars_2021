#include <iostream>
#include <string>

using namespace std;


struct Struct {
  int a = 10;
  int b = 20;
};

int main() {
  char x = 'c';
  //int* x1 = (char*) &x;

  //std::cout << "x: " << x << " x1: " << x1 << std::endl;

  int x2 = static_cast<int>(x);
  std::cout << "x2: " << x2 << std::endl;


  Struct st;

  char* c = reinterpret_cast<char*>(&st);

  for (int i = 0; i < 16; ++i) {
    std::cout << c[i];
  }
  std::cout << std::endl;
};
