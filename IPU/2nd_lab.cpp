#include <iostream>
using namespace std;
class complex_num {
private:
    double real;
    double imag;
public:
    complex_num() {
        real = 0.0;
        imag = 0.0;
    }
    complex_num(double r, double i) {
        real = r;
        imag = i;
    }
    complex_num add(const complex_num& other) const {
        return complex_num(real + other.real, imag + other.imag);
    }
    void show() const {
        cout << "Complex number is " << real << " + " << imag << " i" << endl;
    }
};

int main() {
    complex_num s1(2, 5);
    complex_num s2(8, 5);
    complex_num s3 = s1.add(s2);
    s1.show();
    s2.show();
    s3.show();
    return 0;
}