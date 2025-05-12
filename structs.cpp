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
