#include <iostream>
using namespace std;

class Animal {
public:
  void eat() {
    cout << "Eating..." << endl;
  }
};

class Dog : public Animal {
public:
  void bark() {
    cout << "Barking..." << endl;
  }
};

int main() {
  Dog myDog;
  myDog.eat();
  myDog.bark();
  return 0;
}
