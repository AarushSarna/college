#include <iostream>
using namespace std;
class complex {
private:
    double real;
    double imag;
public:
    complex() {
        real = 0.0;
        imag = 0.0;
    }
    complex(double r, double i) {
        real = r;
        imag = i;
    }
    complex add(const complex& other) const {
        return complex(real + other.real, imag + other.imag);
    }
    void show() const {
        cout << "Complex number is " << real << " + " << imag << " i" << endl;
    }
};

int main() {
    complex s1(2, 5);
    complex s2(8, 5);
    complex s3 = s1.add(s2);
    s1.show();
    s2.show();
    s3.show();
    return 0;
}