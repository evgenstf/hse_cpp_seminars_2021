#include <iostream>
#include <cstdio>
#include <fstream>

#include <memory>


using namespace std;


class ParentA {
public:
  ~ParentA() {
    std::cout << "called ParentA destructor\n";
  }
  int a = 0xaaaaaaaa;
};

class ChildB : public ParentA {
public:
  ~ChildB() {
    std::cout << "called ChildB destructor\n";
  }
  int b = 0xbbbbbbbb;
};


class VParentA {
public:
  virtual ~VParentA() {
    std::cout << "called virtual VParentA destructor\n";
  }
  int a = 0xaaaaaaaa;
};

class VChildB : public VParentA {
public:
  ~VChildB() override {
    std::cout << "called virtual VChildB destructor\n";
  }
  int b = 0xbbbbbbbb;
};


int main() {
  {
    std::unique_ptr<ParentA> a = std::make_unique<ChildB>();
  }

  std::cout << std::endl;

  {
    std::unique_ptr<VParentA> va = std::make_unique<VChildB>();
  }
}
