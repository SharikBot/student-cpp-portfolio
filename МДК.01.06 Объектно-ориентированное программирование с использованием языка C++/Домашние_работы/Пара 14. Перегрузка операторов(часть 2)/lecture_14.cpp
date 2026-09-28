

#include <iostream>
using namespace std;

// ===== Array =====
class Array {
private:
    int data[5];
    int len;

public:
    Array() {
        len = 5;
        for (int i = 0; i < len; i++) {
            data[i] = 0;
        }
    }

    Array(int a, int b, int c, int d, int e) {
        len = 5;
        data[0] = a;
        data[1] = b;
        data[2] = c;
        data[3] = d;
        data[4] = e;
    }

    int& operator[](int i) {
        if (i < 0 || i >= len) {
            cout << "Index error: " << i << endl;
            exit(1);
        }
        return data[i];
    }

    const int& operator[](int i) const {
        if (i < 0 || i >= len) {
            cout << "Index error: " << i << endl;
            exit(1);
        }
        return data[i];
    }

    void print() const {
        cout << "[ ";
        for (int i = 0; i < len; i++) {
            cout << data[i];
            if (i != len - 1) cout << ", ";
        }
        cout << " ]" << endl;
    }
};


// ===== Count =====
class Count {
private:
    int val;

public:
    Count() {
        val = 0;
    }

    Count(int start) {
        val = start;
    }

    int get() const {
        return val;
    }

    Count& operator++() {
        ++val;
        return *this;
    }

    Count operator++(int) {
        Count temp = *this;
        val++;
        return temp;
    }

    Count& operator--() {
        --val;
        return *this;
    }

    Count operator--(int) {
        Count temp = *this;
        val--;
        return temp;
    }

    void print() const {
        cout << "value: " << val << endl;
    }
};


// ===== main =====
int main() {
    cout << "ARRAY\n";

    Array a;
    a[2] = 99;

    a.print();
    cout << "a[2] = " << a[2] << endl;

    cout << "\nCOUNT\n";

    Count c(10);
    c.print();

    ++c;
    c.print();

    c--;
    c.print();

    return 0;
}