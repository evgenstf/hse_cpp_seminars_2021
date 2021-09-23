#include <iostream>

#include <string>

#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Hasher {
  size_t operator()(const pair<int, int>& x) const {
    size_t first = x.first;
    size_t second = x.second;
    return (first << sizeof(first)) | second;
  }
};

struct BrokenHasher {
  size_t operator()(const pair<int, int>& x) const {
    return 1;
  }
};

struct AlwaysEqual {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
    return true;
  }
};

int main() {
  cout << "    s: \n";
  unordered_set<pair<int, int>, Hasher> s;
  s.emplace(4, 1);
  s.emplace(5, 12);
  s.emplace(6, 123);
  s.emplace(7, 2);
  s.emplace(8, 23);
  s.emplace(9, 234);


  for (auto [first, second] : s) {
    cout << first << ' ' << second << endl;
  }

  cout << " s bucket count: " << s.bucket_count() << endl;

  cout << "    s2: \n";

  unordered_set<pair<int, int>, BrokenHasher, AlwaysEqual> s2;
  s2.emplace(4, 1);
  s2.emplace(5, 12);
  s2.emplace(6, 123);
  s2.emplace(7, 2);
  s2.emplace(8, 23);
  s2.emplace(9, 234);


  for (auto [first, second] : s2) {
    cout << first << ' ' << second << endl;
  }
  cout << " s2 bucket count: " << s2.bucket_count() << endl;
  s2.rehash(5);
  cout << " after rehash: " << s2.bucket_count() << endl;

}
