

#include <iostream>
#include <string>
using namespace std;

// ===== Engine + Car (composition) =====
class Engine {
public:
    void run() {
        cout << "Engine is running" << endl;
    }
};

class Car {
private:
    Engine* eng;

public:
    Car(Engine* e) {
        eng = e;
    }

    void start() {
        eng->run();
    }
};


// ===== Author + Book (aggregation) =====
class Author {
private:
    string fullName;

public:
    Author(const string& name) {
        fullName = name;
    }

    string getName() const {
        return fullName;
    }
};

class Book {
private:
    string bookTitle;
    Author writer;

public:
    Book(const string& title, const string& authorName)
        : writer(authorName) {
        bookTitle = title;
    }

    void show() const {
        cout << bookTitle << " by " << writer.getName() << endl;
    }
};


// ===== Hardware classes =====
class CPU {
private:
    string model;
    double freq;

public:
    CPU(const string& m, double f) : model(m), freq(f) {
        cout << "CPU created: " << model << " (" << freq << " GHz)" << endl;
    }

    void work() {
        cout << "CPU working" << endl;
    }
};

class RAM {
private:
    double capacity;
    string memType;

public:
    RAM(double c, const string& t) : capacity(c), memType(t) {
        cout << "RAM initialized: " << capacity << "GB " << memType << endl;
    }

    void work() {
        cout << "RAM active" << endl;
    }
};

class GPU {
private:
    string model;
    int memory;

public:
    GPU(const string& m, int v) : model(m), memory(v) {
        cout << "GPU ready: " << model << " VRAM " << memory << "MB" << endl;
    }

    void work() {
        cout << "GPU running" << endl;
    }
};


// ===== Computer (composition) =====
class Computer {
private:
    string name;

    CPU cpu;
    RAM ram;
    GPU gpu;

public:
    Computer(const string& n,
             const string& cpuModel, double freq,
             double ramSize, const string& ramType,
             const string& gpuModel, int vram)
        : name(n),
          cpu(cpuModel, freq),
          ram(ramSize, ramType),
          gpu(gpuModel, vram) {
    }

    void start() {
        cpu.work();
        ram.work();
        gpu.work();

        cout << "Computer started: " << name << endl;
    }
};


// ===== main =====
int main() {
    Engine e;
    Car c(&e);
    c.start();

    cout << endl;

    Book b("Dune", "Frank Herbert");
    b.show();

    cout << endl;

    Computer pc(
        "MyPC",
        "INTEL 5", 5.6,
        16, "DDR4",
        "GTX 1050TI", 4056
    );

    pc.start();

    return 0;
}