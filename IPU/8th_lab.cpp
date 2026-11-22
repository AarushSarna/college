#include <iostream>
using namespace std;
template <typename T>
class greater_of_two
{
private:
    T num1, num2;

public:
    greater_of_two(T a, T b)
    {
        num1 = a;
        num2 = b;
        cout << "Constructor initialized" << endl;
    }
    T greater()
    {
        return (num1 > num2) ? num1 : num2;
    }
    ~greater_of_two() {
        cout<<"Distructor was called"<<endl;
    }
};
int main(){
    greater_of_two<int> obj(3,5);
    int obj_greater = obj.greater();
    cout<<obj_greater<<endl;
    return 0;
}