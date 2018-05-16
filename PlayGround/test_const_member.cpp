
#include<iostream>
using namespace std;

class A
{
public:
    A(int b)
        :k(b) {}//second time
    const int k = 666;//first time
};

int main() {
    A a(555);
    cout << a.k << endl;
    return 0;
}

