
#include <iostream>
#include <string>
using namespace std;

// ===== Person =====
class Person {
private:
    int age = 0;

public:
    void setAge(int value) {
        if (value >= 0 && value <= 120) {
            age = value;
        }
    }

    int getAge() const {
        return age;
    }
};


// ===== Student =====
class StudentP {
private:
    string fullName;

public:
    void setName(const string& n) {
        fullName = n;
    }

    string getName() const {
        return fullName;
    }
};


// ===== Product =====
class Product {
private:
    string title;
    double cost = 0;

public:
    void setName(const string& n) {
        title = n;
    }

    void setPrice(double p) {
        if (p > 0) {
            cost = p;
        }
    }

    string getName() const {
        return title;
    }

    double getPrice() const {
        return cost;
    }
};


// ===== Clothes =====
class Clothes {
public:
    enum class Type { TSHIRT, JEANS, COAT, SUIT, SHORTS };

private:
    Type type;
    string name;
    double price = 0;
    int size = 0;
    string color;

public:
    void setName(const string& n) {
        name = n;
    }

    void setPrice(double p) {
        if (p > 0) {
            price = p;
        }
    }

    void setType(Type t) {
        type = t;
    }

    void setSize(int s) {
        size = s;
    }

    void setColor(const string& c) {
        color = c;
    }

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    int getSize() const {
        return size;
    }

    string getColor() const {
        return color;
    }

    string getCategory() const {
        if (type == Type::TSHIRT || type == Type::JEANS)
            return "Casual";
        if (type == Type::COAT)
            return "Outerwear";
        if (type == Type::SUIT)
            return "Formal";
        if (type == Type::SHORTS)
            return "Sport";

        return "Unknown";
    }
};


// ===== main =====
int main() {
    setlocale(LC_ALL, "ru");

    Clothes item;

    item.setName("T-Shirt");
    item.setPrice(1500);
    item.setType(Clothes::Type::TSHIRT);
    item.setSize(42);
    item.setColor("Red");

    cout << item.getName() << endl;
    cout << item.getPrice() << endl;
    cout << item.getCategory() << endl;

    return 0;
}