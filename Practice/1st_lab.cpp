#include <iostream>
using namespace std;
class student {
    private:
        int length;
        int breath;

    public:
        student() {length=0;
            breath=0;}
        void setLength(int l) {length=l;};
        void setBreath(int b) {breath=b;};
        int area() {return length*breath;};
        int perimeter() {return 2*(length+breath);}
        void show() {cout<<"Area is "<<area()<<endl<<"Perimeter is "<<perimeter();}

};
int main() {
    student s;
    s.setLength(5);
    s.setBreath(10);
    s.area();
    s.perimeter();
    s.show();
    return 0;
};