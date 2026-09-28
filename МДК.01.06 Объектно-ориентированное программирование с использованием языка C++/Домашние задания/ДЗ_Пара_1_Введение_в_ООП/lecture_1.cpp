
#include <iostream>
#include <string>

using namespace std;

class Vehicle {
private:
    string brand;

public:
    int fuelLevel;

    Vehicle() {
        brand = "Audi";
        fuelLevel = 20;
    }

    void move(int kilometers) {
        fuelLevel -= kilometers / 100;
    }

    void addFuel(int liters) {
        fuelLevel += liters;
    }

    int showFuel() const {
        cout << "Fuel: " << fuelLevel << endl;
        return fuelLevel;
    }
};

int main() {
    Vehicle myCar;

    myCar.move(1000);
    myCar.showFuel();

    myCar.addFuel(5);
    myCar.showFuel();

    return 0;
}