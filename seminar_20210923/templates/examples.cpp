#include <iostream>
#include <cstdio>
#include <fstream>


using namespace std;


template<typename T>
void func(const T& x) {
  cout << x << endl;
}

int main() {
  func(1);
  func("str");
  func(1.1);
}
