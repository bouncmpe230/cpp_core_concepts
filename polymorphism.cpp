#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a generic shape\n";
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle\n";
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a square\n";
    }
};

void render(Shape* s) {
    s->draw();  // Decided at runtime
}

int main() {
    Shape* s;
    Circle c;
    Square q;

    s = &c;
    s->draw();

    s = &q;
    s->draw();

    render(&c);  // Output: Drawing a circle
    render(&q);  // Output: Drawing a square

    return 0;
}
