#include <iostream>
using namespace std;

namespace Physics {
  const double gravity = 9.8;
  void describe() {
    cout << "This is the physics namespace." << endl;
  }
}

namespace Math {
  int add(int a, int b) {
    return a + b;
  }
}

int main() {
  Physics::describe();
  cout << "Gravity constant: " << Physics::gravity << endl;
  cout << "Sum: " << Math::add(3, 4) << endl;
  return 0;
}
