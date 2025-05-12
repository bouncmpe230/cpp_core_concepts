#include <iostream>
using namespace std;

void increase(int &num) {
  num += 10;
}

int main() {
  int value = 5;
  increase(value);
  cout << "New value: " << value << endl;
  return 0;
}
