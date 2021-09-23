#include <iostream>

#include <string>

#include <set>
#include <map>

using namespace std;

struct Less {
  bool operator()(const int lhs, const int rhs) const {
    return to_string(lhs) < to_string(rhs);
  }
};

int main() {
  set<int, Less> s;
  s.insert(1);
  s.insert(12);
  s.insert(123);
  s.insert(2);
  s.insert(23);
  s.insert(234);


  for (auto x : s) {
    cout << x << endl;
  }


  auto iterator = s.begin();

  // cout << iterator[2] << std::endl; // no random access :(

  ++iterator;
  ++iterator;
  cout << *iterator << endl;


  set<int, Less> s2 = {3, 4, 5, 6};

  s2.merge(s);

  for (auto x : s2) {
    cout << x << ' ';
  }
  cout << endl;


  auto exists_it = s2.find(3);
  auto not_exists_it = s2.find(999);  // s2.end()



  multiset<int> s3 = {2, 3, 3, 4};

  auto first_x_it = s3.lower_bound(3); // first 3
  auto next_after_x_it = s3.upper_bound(3); // 4


  map<string, int> m = {{"a", 1}, {"b", 2}};

  for (auto [key, value]: m) {
    cout << key << ' ' << value << endl;
  }
}
