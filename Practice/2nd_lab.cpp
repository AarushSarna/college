//Design a class Point to represent a point in 2D plane.
#include <iostream>
#include <cmath> 
using namespace std;
class point {
private:
    int x_axis;
    int y_axis;
public:
    point() {
        x_axis = 0;
        y_axis = 0;
    }
    point(int c) {
        x_axis = c;
        y_axis = c;
    }
    point(int x, int y) {
        x_axis = x;
        y_axis = y;
    }
    
    void show() const {
        cout << "Point is (" << x_axis << ", " << y_axis << ")" << endl;
    }
    
    double distanceFromOrigin() const {
        return sqrt((x_axis * x_axis) + (y_axis * y_axis));
    }
    
    double distanceBetween(const point& other) const {
        return sqrt(pow(x_axis - other.x_axis, 2) + pow(y_axis - other.y_axis, 2));
    }
};

int main() {
    point p1(2, 7);
    point p2(3, 9);
    
    p1.show();
    p2.show();
    
    double dist = p1.distanceBetween(p2); // Distance is a number, not a point object
    cout << "Distance between p1 and p2: " << dist << endl;

    return 0;
}