

// ===== Задание 1 =====
#include <iostream>
using namespace std;

class Student {
private:
    string fullName;
    int ageYears;
    double avgGrade;

public:
    Student(string n, int a, double g) {
        fullName = n;
        ageYears = a;
        avgGrade = g;
    }

    ~Student() {
        cout << "Student object removed\n";
    }

    void update(string n, int a, double g) {
        fullName = n;
        ageYears = a;
        avgGrade = g;
    }

    void show() {
        cout << "=== Student ===\n";
        cout << "Name : " << fullName << endl;
        cout << "Age  : " << ageYears << endl;
        cout << "Grade: " << avgGrade << endl;
    }
};

int main() {

    Student s1("Alex", 20, 4.6);
    s1.show();

    cout << "\nCopy example\n";

    Student s2 = s1;
    s2.show();

    return 0;
}


// ===== Задание 2 =====
#include <iostream>
using namespace std;

class Car {
public:
    string model;

private:
    int yearMade;

protected:
    int maxSpeed;

public:
    Car(string m, int y, int s) {
        model = m;
        yearMade = y;
        maxSpeed = s;
    }

    void setYear(int y) {
        yearMade = y;
    }

    int getYear() {
        return yearMade;
    }

    void setSpeed(int s) {
        maxSpeed = s;
    }

    int getSpeed() {
        return maxSpeed;
    }

    void show() {
        cout << "--- Car ---\n";
        cout << "Model: " << model << endl;
        cout << "Year : " << yearMade << endl;
        cout << "Speed: " << maxSpeed << endl;
    }
};

int main() {

    Car c1("Toyota", 2021, 180);
    c1.show();

    cout << "\nUpdate values\n";

    c1.setYear(2023);
    c1.setSpeed(200);

    c1.show();

    return 0;
}


// ===== Задание 3 =====
#include <iostream>
using namespace std;

class Product {
private:
    string title;
    double cost;
    int stock;

public:
    Product(string t, double c, int s) {
        title = t;
        cost = c;
        stock = s;
    }

    ~Product() {
        cout << "Product removed\n";
    }

    Product* update(string t, double c, int s) {
        title = t;
        cost = c;
        stock = s;
        return this;
    }

    void show() {
        cout << "--- Product ---\n";
        cout << "Name  : " << title << endl;
        cout << "Price : " << cost << endl;
        cout << "Stock : " << stock << endl;
    }

    void buy(int count) {
        if (count <= stock) {
            stock -= count;
            cout << "Bought: " << count << endl;
        } else {
            cout << "Not enough stock\n";
        }
    }
};

int main() {

    Product p1("Laptop", 1500.0, 10);

    p1.show();
    cout << endl;

    p1.buy(3);

    cout << endl;
    p1.show();

    return 0;
}