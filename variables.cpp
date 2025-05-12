#include <iostream>
#include <string>
using namespace std;

int main() {
  int quantity = 12;
  float price_per_apple = 0.75f;
  double total = quantity * price_per_apple;
  char grade = 'A';
  bool available = true;
  string item = "Notebook";

  cout << "Item: " << item << endl;
  cout << "Total cost: $" << total << endl;
  cout << "Grade: " << grade << ", Available: " << available << endl;

  return 0;
}
