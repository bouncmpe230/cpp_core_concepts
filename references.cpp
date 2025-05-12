#include <iostream>
using namespace std;

void increase(int &num) {
  num += 10;
}

int main() {
  int value = 5;
  increase(value);
  cout << "New value: " << value << endl;

  int& val_alias = value; 

  val_alias += 6;
  cout << "New value: " << val_alias << endl;
  cout << "New value: " << value << endl;

  return 0;
}
