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