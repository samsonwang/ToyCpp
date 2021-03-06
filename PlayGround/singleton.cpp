#include <iostream>

using namespace std;

class Singleton
{
public:
    static Singleton *getInstance();
private:
    Singleton() {}
    static Singleton *instance;
};

Singleton* Singleton::instance = new Singleton();
Singleton* Singleton::getInstance() {
    if(!instance) {
        //        instance = new Singleton();
        cout << "getInstance(): First instance\n";
        return instance;
    }
    else {
        cout << "getInstance(): Previous instance\n";
        return instance;
    }
}

// below code will not work
// Singleton::instance = NULL;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    return 0;
}
