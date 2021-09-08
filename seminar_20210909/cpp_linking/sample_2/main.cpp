double average(int a, int b) {
  return static_cast<double>(a + b) / 2.0;
}

int main() {
  int a = 10;
  int b = 20;
  return static_cast<int>(average(a, b));
}
