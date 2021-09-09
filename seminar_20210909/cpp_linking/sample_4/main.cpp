#include <iostream>

double average(int a, int b);

int main() {
  int a = 10;
  int b = 20;
  std::cout << static_cast<int>(average(a, b)) << std::endl;
  return 0;
}
