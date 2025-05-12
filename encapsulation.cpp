#include <iostream>
using namespace std;

class BankAccount {
private:
  double balance;

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
