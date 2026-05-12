

#include <iostream>
#include <string>
using namespace std;

// ===== Student =====
class Student {
public:
    string fullName;

    Student(const string& name) {
        fullName = name;
    }
};


// ===== School =====
class School {
private:
    Student* pupil;

public:
    School(Student* s) {
        pupil = s;
    }

    void printStudent() {
        cout << "Student: " << pupil->fullName << endl;
    }
};


// ===== Teacher =====
class Teacher {
public:
    string fullName;

    Teacher(const string& name) {
        fullName = name;
    }
};


// ===== Course =====
class Course {
private:
    string title;
    Teacher* lecturer;

public:
    Course(Teacher* t) {
        lecturer = t;
        title = "Unknown";
    }

    Course(const string& courseTitle, Teacher* t)
        : title(courseTitle), lecturer(t) {}

    void info() {
        cout << "Course: " << title
             << " | Teacher: " << lecturer->fullName << endl;
    }
};


// ===== main =====
int main() {
    setlocale(LC_ALL, "ru");

    Student a("Ivan");
    Student b("Alex");

    School school(&b);
    school.printStudent();

    Teacher t("Andrey");

    Course c1("C++ Basics", &t);
    c1.info();

    return 0;
}