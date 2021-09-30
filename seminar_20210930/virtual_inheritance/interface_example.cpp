#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>

#include <memory>


using namespace std;


class Interface {
public:
  virtual void print() = 0;
};

class Realisation : public Interface {
public:
  void print() override {
    cout << "Child b: " << b << endl;
  }

private:
  int b = 20;
};

int main() {
  Realisation realisation;
  realisation.print();
}
