#include <iostream>
using namespace std;
template <typename T>
T square_of(T x) {
    return x * x;
}
int main() {
    int result = square_of(5);
    string result_str = square_of("Hello");
    cout << result << endl;
    cout << result_str << endl;
    return 0;
}