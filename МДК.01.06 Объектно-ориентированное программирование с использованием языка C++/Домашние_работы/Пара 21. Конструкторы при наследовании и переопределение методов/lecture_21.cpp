

#include <iostream>
#include <string>
using namespace std;

// ===== Base Animal =====
class Animal {
public:
    virtual void sound() {
        cout << "Generic animal sound" << endl;
    }

    Animal(const string& name) {
        cout << "Animal created: " << name << endl;
    }
};

// ===== Dog =====
class Dog : public Animal {
public:
    Dog(const string& name) : Animal(name) {
        cout << "Dog initialized" << endl;
    }

    void sound() override {
        cout << "Woof" << endl;
    }
};


// ===== Character base =====
class Character {
private:
    string id;
    int hp;
    int power;

public:
    Character(const string& n, int health, int dmg)
        : id(n), hp(health), power(dmg) {}

    virtual int attack() {
        cout << id << " attacks" << endl;
        return power;
    }

    string name() { return id; }
    int health() { return hp; }
    int damage() { return power; }

    void takeHit(int dmg) {
        hp -= dmg;
        if (hp < 0) hp = 0;

        cout << id << " takes " << dmg
             << " damage. HP left: " << hp << endl;
    }
};


// ===== Mage =====
class Mage : public Character {
private:
    string spell;

public:
    Mage(const string& n, int hp, int dmg, const string& sp)
        : Character(n, hp, dmg), spell(sp) {}

    int attack() override {
        cout << name() << " casts magic attack" << endl;
        return damage();
    }

    void cast() {
        cout << name() << " uses spell: " << spell << endl;
    }
};


// ===== Warrior =====
class Warrior : public Character {
private:
    int armor;

public:
    Warrior(const string& n, int hp, int dmg, int arm)
        : Character(n, hp, dmg), armor(arm) {}

    int attack() override {
        cout << name() << " swings weapon for " << damage() << endl;
        return damage();
    }

    void special() {
        cout << name() << " performs heavy strike (armor " << armor << ")" << endl;
    }

    int getArmor() {
        return armor;
    }
};


// ===== main =====
int main() {
    setlocale(LC_ALL, "ru");

    Warrior w("Knight", 100, 25, 50);
    Mage m("Wizard", 80, 30, "Fireball");

    w.attack();
    m.attack();

    w.special();
    m.cast();

    Character* team[2] = { &w, &m };

    for (int i = 0; i < 2; i++) {
        team[i]->attack();
    }

    return 0;
}