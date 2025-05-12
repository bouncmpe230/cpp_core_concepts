#include <iostream>
using namespace std;

template <typename T>
T maxValue(T a, T b) {
  return (a > b) ? a : b;
}

int main() {
  cout << maxValue(5, 10) << endl;
  cout << maxValue(3.14, 2.71) << endl;
  cout << maxValue('x', 'm') << endl;
  return 0;
}
