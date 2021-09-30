#include <iostream>

#include <string>

#include <set>
#include <map>

using namespace std;

struct Less {
  bool operator()(const int lhs, const int rhs) const {
    ++cnt;
    return to_string(lhs) < to_string(rhs);
  }

  mutable int cnt = 0;
};

int main() {
  set<int, Less> s;
  s.insert(1);
  s.insert(12);
  s.insert(123);
  s.insert(2);
  s.insert(23);
  s.insert(234);


  auto comparator = s.key_comp();

  cout << "compares count: " << comparator.cnt << endl;

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
  //                     ^     ^
  //                     lb    ub

  auto first_x_it = s3.lower_bound(3); // first 3
  auto next_after_x_it = s3.upper_bound(3); // 4


  cout << "3 count: " << s3.count(3) << endl;



  map<string, int> m = {{"a", 1}, {"b", 2}};

  cout << "map: \n";
  for (auto [key, value]: m) {
    cout << key << ' ' << value << endl;
  }
}
