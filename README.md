# C++ Core Concepts

This tutorial introduces the fundamentals of C++ programming, structured into short lessons. Each concept includes a detailed explanation, an example.


## Table of Contents

- [Basic Input and Output](#basic-input-and-output)
-  [Variables and Data Types](#variables-and-data-types)
- [Namespaces](#namespaces)
- [Structs and Member Functions](#structs-and-member-functions)
- [References and Reference Parameters](#references-and-reference-parameters)
- [Constructors and Destructors](#constructors-and-destructors)
- [Encapsulation (Private Members)](#encapsulation)
- [Inheritance](#inheritance)
- [Polymorphism](#polymorphism)



## Basic Input and Output


Input/output operations are essential for interacting with users. C++ provides `cin` for input and `cout` for output using the standard I/O stream library `<iostream>`.


```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
  string name;
  int age;

  cout << "Enter your name: ";
  getline(cin, name);  // reads a full line including spaces

  cout << "Enter your age: ";
  cin >> age;          // reads an integer input

  cout << "Welcome, " << name << ". You are " << age << " years old." << endl;
  return 0;
}
```

```bash
g++ basic_io.cpp -o basic_io
./basic_io
```

## Variables and Data Types

C++ supports several built-in data types: integers (`int`), floating point (`float`, `double`), characters (`char`), booleans (`bool`), and strings (`string`). Variables are containers that hold these values.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
  int apples = 10;
  double price_per_apple = 0.75;
  char grade = 'A';
  bool available = true;
  string message = "Total cost";

  double total = apples * price_per_apple;

  cout << message << ": $" << total << endl;
  cout << "Grade: " << grade << ", Available: " << available << endl;
  return 0;
}
```

## Namespaces

Namespaces prevent naming conflicts in larger programs by grouping functions, variables, and types under a named scope.

```cpp
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
```


## Structs and Member Functions

A `struct` in C++ is a user-defined type that groups related variables (called members). Structs can also include member functions.


```cpp
#include <iostream>
#include <string>
using namespace std;

struct Student {
  string name;
  int id;

  void print() {
    cout << "Name: " << name << ", ID: " << id << endl;
  }
};

int main() {
  Student s1 = {"Elif", 101};
  s1.print();

  s1.name = "Ali";
  s1.id = 102;
  s1.print();

  return 0;
}
```


## References and Reference Parameters

A reference is an alias for another variable. Functions can use reference parameters to modify arguments directly.


```cpp
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
```


## Constructors and Destructors

Special functions that manage an object's lifecycle.
A constructor is a special function automatically called when an object is created. A destructor is called when the object goes out of scope or is deleted.


```cpp
#include <iostream>
using namespace std;

class Timer {
public:
  Timer() {
    cout << "Timer started!" << endl;
  }

  ~Timer() {
    cout << "Timer stopped." << endl;
  }
};

int main() {
  Timer t;
  cout << "Running process..." << endl;
  return 0;
}
```

## Encapsulation

Encapsulation is the practice of restricting direct access to some components of an object.  It means hiding internal data and exposing only necessary interfaces. This ensures data protection, modularity, and easier maintenance. In C++, this is done using access specifiers: `private`, `protected`, and `public`. Typically, data members are made private and accessed via public getter/setter functions.

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
  double balance;  // only accessible within the class

public:
  BankAccount() {
    balance = 0.0;
  }

  void deposit(double amount) {
    if (amount > 0) {
      balance += amount;
    }
  }

  double getBalance() {
    return balance;
  }
};

int main() {
  BankAccount account;
  account.deposit(150.75);
  cout << "Current balance: $" << account.getBalance() << endl;
  return 0;
}
```

`balance` is private. Users interact with `deposit()` and `getBalance()` — no direct access.

## Inheritance

Inheritance allows one class to inherit properties and methods from another class. It promotes code reuse and logical hierarchies.

```cpp
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
  myDog.eat();   // inherited from Animal
  myDog.bark();  // defined in Dog
  return 0;
}
```

`Dog` inherits `eat()` from `Animal`. No need to rewrite shared functionality.

## Polymorphism

Polymorphism means "many forms". It allows the same interface to behave differently based on the actual object.

### Runtime Polymorphism 
Runtime polymorphism means the decision of which function to call is made at runtime, not compile time. In C++, this is achieved through:

- Inheritance (base and derived classes)
- Virtual functions: a member function that is declared in a base class and is meant to be overridden in derived classes
- Pointers or references to base class


```cpp
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
    Circle c;
    Square s;

    render(&c);  // Output: Drawing a circle
    render(&s);  // Output: Drawing a square

    return 0;
}
```


###  Compile-time Polymorphism
Compile-time polymorphism means the compiler determines which function to call based on the types and number of arguments at compile time — not at runtime. This includes:

- Function overloading
- Operator overloading
- Templates

####  Function Overloading

C++ allows defining multiple functions with the same name but different parameter types or counts. This is called function overloading.


```cpp
#include <iostream>
using namespace std;

int sum(int a, int b) {
  return a + b;
}

double sum(double a, double b) {
  return a + b;
}

int main() {
  cout << sum(3, 4) << endl;        // uses int version
  cout << sum(3.1, 4.2) << endl;    // uses double version
  return 0;
}
```

#### Templates

Templates allow writing generic functions and classes that work with any type, and the compiler generates the actual code for each type when needed.

```cpp
#include <iostream>
using namespace std;

template <typename T>
T maxValue(T a, T b) {
  return (a > b) ? a : b;
}

int main() {
  cout << maxValue(5, 10) << endl;        // integers
  cout << maxValue(3.14, 2.71) << endl;   // doubles
  cout << maxValue('x', 'm') << endl;     // characters
  return 0;
}
```

