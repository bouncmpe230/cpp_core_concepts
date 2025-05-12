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
