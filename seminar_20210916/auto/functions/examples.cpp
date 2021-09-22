#include <iostream>
#include <cassert>


int add(int a, int b) {  // auto will be replaced with type of a + b (int)
  return a + b;
}

int main() {
  int add_result = add(1, 5);
  static_assert(std::is_same_v<decltype(add_result), int>);
  assert(std::is_same_v<decltype(add_result), int>);

  auto lambda = [](int a, int b){ return a + b; };
}
