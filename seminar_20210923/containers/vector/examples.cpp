#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v1 = {1,2,3};  // using initializer list
  vector<int> v2(/*size =*/ 10, /*initial_value =*/ 5);

  v2.assign(/*size =*/ 20, /*initial_value =*/ 6);

  for (size_t i = 0; i < v2.size(); ++i) {
    v2[i] = i;
  }

  std::cout << v2[0] << std::endl;
  std::cout << v2.at(0) << std::endl;
  // std::cout << v2.at(20) << std::endl;

  std::cout << v2.front() << ' ' << v2.back() << std::endl;

  auto* pointer = v2.data();
  std::cout << pointer[3] << std::endl;


  auto iterator = v2.begin(); // for constant use cbegin

  std::cout << iterator[2] << std::endl;

  auto reversed_iterator = v2.rbegin(); // for constant use crbegin
  std::cout << reversed_iterator[2] << std::endl;



  // preallocate space:

  vector<int> v4;
  v4.reserve(100);

  std::cout << "capacity: " << v4.capacity() << std::endl;

  v4.push_back(42);

  v4.shrink_to_fit();
  std::cout << "capacity: " << v4.capacity() << std::endl;
}
