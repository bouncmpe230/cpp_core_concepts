#include <iostream>
using namespace std;

int sum(int a, int b) {
  return a + b;
}

int sum(int a, int b, int c) {
  return a + b + c;
}

double sum(double a, double b) {
  return a + b;
}

int main() {
  cout << sum(3, 4) << endl;
  cout << sum(3.1, 4.2) << endl;
  cout << sum(3.1, 4.2, 5.3) << endl;
  return 0;
}
