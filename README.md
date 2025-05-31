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
- [Constructors and Destructors in Polymorphism](#constructorsAndPolymorphism)



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

## Constructors and Destructors in Polymorphism

When using polymorphism, constructors and destructors play a crucial role in managing resources and ensuring proper cleanup. In derived classes, constructors can explicitly call a specific constructor of the base class using an initializer list (e.g., `Base(3, 2)`). If no base constructor is specified, the compiler automatically inserts a call to the base class’s default constructor. This ensures the base portion of the object is properly initialized before the derived constructor runs.

Destructors, on the other hand, are automatically called in the reverse order of construction: the derived class’s destructor runs first, followed by the base class’s destructor. However, this only happens fully if the object is destroyed with its actual (most-derived) type. If a derived object is deleted through a base class pointer and the base class does not have a `virtual` destructor, then only the base class’s destructor will be executed. This can lead to memory leaks and undefined behavior, which is why it is recommended for polymorphic base classes to declare destructors as `virtual`.

In the following example, we demonstrate how constructors and destructors work in a polymorphic context with inheritance. In this snippet, we have a memory leak due to `stackArr[0]` storing a pointer to an `Apartment`, but deleting it as a `Building*`. This will only call the `Building` destructor, not the `Apartment` destructor, leading to a memory leak.

All stack-allocated objects will call both their destructors when their scope ends, but heap-allocated objects will only call the base destructor if deleted through a base pointer. One can differentiate between the two by their declaration: stack-allocated objects are declared as `Building hamlinHall;`, while heap-allocated objects are created with `new`, like `Building* b = new Apartment();`.

```cpp
Building b;     // creates an object on the stack, calls the constructor

Building* all;  // does not call the constructor, just declares a pointer

#include <iostream>
using namespace std;

class Building {
protected:
    int floors;
    string address;
public:
    Building() {
        floors = 0;
        address = "Unknown";
        cout << "Unspecified building created\n";
    }

    Building(int f, string addr) : floors(f), address(addr) {
        cout << "Building constructed at " << address << " with " << floors << " floors.\n";
    }

    void setAddress(string addr) {
        address = addr;
        cout << "Address set from Building class\n";
    }

    ~Building() {
        cout << "Building at " << address << " is being destroyed.\n";
    }
};

class Apartment : public Building {
protected:
    int units;
    int inhabitants;
public:
    Apartment() {
        units = 0;
        inhabitants = 0;
        cout << "Unspecified apartment created\n";
    }

    Apartment(int u, int inh) {
        units = u;
        inhabitants = inh;
        cout << "Apartment constructed at " << address << " with " << floors
             << " floors, " << units << " units and " << inhabitants << " inhabitants.\n";
    }

    Apartment(int f, string addr, int u, int inh) : Building(f, addr), units(u), inhabitants(inh) {
        cout << "Apartment constructed at " << address << " with " << floors
             << " floors, " << units << " units and " << inhabitants << " inhabitants.\n";
    }

    void setAddress(string addr) {
        address = addr;
        cout << "Address set from Apartment class\n";
    }

    ~Apartment() {
        cout << "Apartment at " << address << " is being destroyed.\n";
    }
};

void func(Building* (*bl)[2]) {
    Building *b = new Apartment();

    (*bl)[0] = new Apartment(3, "Main St", 8, 30);
    (*bl)[1] = new Building(2, "Second St");
    b = (*bl)[0];  // this line does not affect the output
    return;
}

int main() {
    Apartment hamlinHall;
    Building* stackArr[2];

    func(&stackArr); // this function call will create objects on the heap
    hamlinHall.setAddress("Hamlin Hall, 123 Main St");
    delete stackArr[0]; // delete the Apartment object
    delete stackArr[1]; // delete the Building object
    return 0;
}
```
### Output
```cpp
Unspecified building created   // hamlinHall's base constructor (Apartment inherits Building)

Unspecified apartment created  // hamlinHall's default Apartment constructor

Unspecified building created   // base constructor for *b = new Apartment()

Unspecified apartment created  // Apartment constructor for `b` 

Building constructed at Main St with 3 floors.   // (*bl)[0]'s base constructor

Apartment constructed at Main St with 3 floors, 8 units and 30 inhabitants.  // (*bl)[0] Apartment part

Building constructed at Second St with 2 floors.  // (*bl)[1] is a pure Building

Address set from Apartment class  // calling hamlinHall.setAddress()

Building at Main St is being destroyed.  // only base destructor is called due to delete via Building* this causes a memory leak since stackArr is declared as Building* it only calls the base destructor

Building at Second St is being destroyed.  // Building object fully destroyed

Apartment at Hamlin Hall, 123 Main St is being destroyed.  // stack-allocated: Apartment destructor called

Building at Hamlin Hall, 123 Main St is being destroyed. // stack-allocated: base (building) destructor called
```
---