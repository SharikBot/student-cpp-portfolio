

#include <iostream>
#include <string>
using namespace std;

// ===== Base class =====
class Animal {
public:
    Animal(const string& n) {
        cout << "Animal constructor called" << endl;
    }

    void eat() {
        cout << "Animal is eating" << endl;
    }

    void sound() {
        cout << "generic animal sound" << endl;
    }
};


// ===== Derived class =====
class Dog : public Animal {
public:
    Dog(const string& n) : Animal(n) {
        cout << "Dog constructor called" << endl;
    }

    void sound() {
        cout << "Woof" << endl;
    }
};


// ===== Person hierarchy =====
class Person {
protected:
    string fullName;

public:
    Person(const string& name) {
        fullName = name;
    }
};

class Student : public Person {
private:
    int score;

public:
    Student(const string& name, int s)
        : Person(name), score(s) {}

    void print() {
        cout << fullName << " | score: " << score << endl;
    }
};


// ===== Employee hierarchy =====
class Employee {
private:
    string fullName;
    int years;

public:
    Employee(const string& name, int exp) {
        fullName = name;
        years = exp;
    }

    void work() {
        cout << fullName << " is working" << endl;
    }

    string getName() {
        return fullName;
    }

    int getExperience() {
        return years;
    }
};


// ===== Manager =====
class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(const string& name, int exp, int team)
        : Employee(name, exp), teamSize(team) {}

    void work() {
        cout << "Manager " << getName()
             << " manages " << teamSize << " people" << endl;
    }

    void meeting() {
        cout << getName() << " is in a meeting" << endl;
    }
};


// ===== Developer =====
class Developer : public Employee {
private:
    string stage;

public:
    Developer(const string& name, int exp, const string& st)
        : Employee(name, exp), stage(st) {}

    void work() {
        cout << "Developer " << getName()
             << " works on stage: " << stage << endl;
    }

    void breakTime() {
        cout << getName() << " is on break" << endl;
    }
};


// ===== main =====
int main() {
    setlocale(LC_ALL, "ru");

    Dog dog("Buddy");
    dog.sound();

    return 0;
}