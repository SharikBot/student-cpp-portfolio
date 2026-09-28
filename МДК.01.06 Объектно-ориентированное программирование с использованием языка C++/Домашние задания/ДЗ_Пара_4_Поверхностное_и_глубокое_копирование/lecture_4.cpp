
#include <iostream>
#include <cstring>

using namespace std;

class MyString {
private:
    char* buffer;
    size_t size;

public:
    MyString(const char* text = "") {
        size = strlen(text);
        buffer = new char[size + 1];
        strcpy(buffer, text);
    }

    MyString(const MyString& other) {
        size = other.size;
        buffer = new char[size + 1];
        strcpy(buffer, other.buffer);
    }

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] buffer;

            size = other.size;
            buffer = new char[size + 1];
            strcpy(buffer, other.buffer);
        }
        return *this;
    }

    ~MyString() {
        delete[] buffer;
    }

    void show() const {
        cout << buffer << endl;
    }
};