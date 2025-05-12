#include <iostream>
using namespace std;

class Shape {
public:
  virtual void draw() {
    cout << "Drawing shape" << endl;
  }
};

class Circle : public Shape {
public:
  void draw() override {
    cout << "Drawing circle" << endl;
  }
};

class Square : public Shape {
public:
  void draw() override {
    cout << "Drawing square" << endl;
  }
};

int main() {
  Shape* s;
  Circle c;
  Square q;

  s = &c;
  s->draw();

  s = &q;
  s->draw();

  return 0;
}
