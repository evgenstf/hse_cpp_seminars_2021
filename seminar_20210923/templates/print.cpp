#include <iostream>
#include <string>

template<typename T>
void print(const T& x) {
  std::cout << x << std::endl;
}

template void print<int>(const int&);
template void print<std::string>(const std::string&);
template void print<double>(const double&);
