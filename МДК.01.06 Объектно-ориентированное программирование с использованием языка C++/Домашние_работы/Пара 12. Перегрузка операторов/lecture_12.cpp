
#include <iostream>
using namespace std;

class Point {
private:
    double xVal;
    double yVal;

public:
    Point() {
        xVal = 0;
        yVal = 0;
    }

    Point(double xCoord, double yCoord) {
        xVal = xCoord;
        yVal = yCoord;
    }

    double x() const { return xVal; }
    double y() const { return yVal; }

    void setX(double newX) { xVal = newX; }
    void setY(double newY) { yVal = newY; }

    Point operator+(const Point& rhs) const {
        return Point(xVal + rhs.xVal, yVal + rhs.yVal);
    }

    Point operator-(const Point& rhs) const {
        return Point(xVal - rhs.xVal, yVal - rhs.yVal);
    }

    bool operator==(const Point& rhs) const {
        return (xVal == rhs.xVal && yVal == rhs.yVal);
    }

    friend ostream& operator<<(ostream& out, const Point& p);
};

ostream& operator<<(ostream& out, const Point& p) {
    out << "[" << p.xVal << ", " << p.yVal << "]";
    return out;
}

int main() {
    cout << "POINTS\n";

    Point a(3, 5);
    Point b(2, 4);
    Point c;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << "\nADD\n";
    Point s = a + b;
    cout << s << endl;

    cout << "\nSUB\n";
    Point d = a - b;
    cout << d << endl;

    cout << "\nCOMPARE\n";
    Point e(3, 5);

    cout << (a == b) << endl;
    cout << (a == e) << endl;

    cout << "\nCHAIN\n";
    Point r = a + b - e;
    cout << r << endl;

    return 0;
}   