
#include <iostream>

double myPow(double x, int n) {
    if (n == 0) {
        return 1;
    }

    double half = myPow(x, n/2);
    int left = n % 2;
    if (left == 0) {
        return half * half;
    }
    else if (left > 0) {
        return half * half * x;
    }
    else {
        return half * half / x;
    }
}

int main(int argc, char* argv[]) {

    std::cout << "10 % 3," << 10 % 3 << std::endl;
    std::cout << "-10 % 3," << -10 % 3 << std::endl;
    std::cout << "10 % -3," << 10 % -3 << std::endl;
    std::cout << "-10 % -3," << -10 % -3 << std::endl;

    std::cout << myPow(2, INT_MIN) << std::endl;

    return 0;
}
