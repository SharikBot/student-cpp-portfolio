
#include <iostream>
#include <string>
using namespace std;

// ===== Base =====
class Base {
public:
    int publicVal;
protected:
    int protectedVal;
private:
    int privateVal;
};


// ===== Engine / Car =====
class Engine {
public:
    void ignite() {
        // engine start logic
    }
};

class Car : private Engine {
public:
    void drive() {
        ignite();
    }
};


// ===== Inheritance demo =====
class Derived : public Base {
public:
    void init() {
        protectedVal = 25;
    }
};


// ===== Device =====
class Device {
private:
    string label;
    bool state;

public:
    Device(bool st, const string& name) {
        label = name;
        state = st;
    }

    bool turnOn() {
        cout << label << " ON" << endl;
        state = true;
        return state;
    }

    bool turnOff() {
        cout << label << " OFF" << endl;
        state = false;
        return state;
    }

    string getName() {
        return label;
    }
};


// ===== Light =====
class Light : public Device {
public:
    Light(bool st, const string& name)
        : Device(st, name) {}

    bool turnOn() {
        cout << getName() << " light ON" << endl;
        return Device::turnOn();
    }

    bool turnOff() {
        cout << getName() << " light OFF" << endl;
        return Device::turnOff();
    }
};


// ===== Thermostat =====
class Thermostat : private Device {
public:
    Thermostat(bool st, const string& name)
        : Device(st, name) {}

    void enable() {
        turnOn();
    }

    void disable() {
        turnOff();
    }
};


// ===== main =====
int main() {
    setlocale(LC_ALL, "ru");

    Light lamp(true, "Lamp");
    lamp.turnOn();
    lamp.turnOff();

    cout << endl;

    Thermostat t(false, "Heater");
    t.enable();
    t.disable();

    return 0;
}