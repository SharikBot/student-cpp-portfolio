
#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    int pages;

public:
    Book() {
        title = "Unknown book";
        pages = 0;
    }

    Book(const string& t, int p) {
        title = t;
        pages = p;
    }

    int getPages() const {
        return pages;
    }

    void printInfo() const {
        cout << "Title: " << title << endl;
        cout << "Pages: " << pages << endl;
    }
};

int main() {
    Book firstBook;
    cout << "Book 1:" << endl;
    firstBook.printInfo();

    cout << endl;

    Book secondBook("War and Peace", 1225);
    cout << "Book 2:" << endl;
    secondBook.printInfo();

    return 0;
}