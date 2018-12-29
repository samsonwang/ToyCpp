
#include <iostream>

double myPow(double x, int n) {
    if (n == 0) {
        return 1.0;
    }
    else if (n > 0) {
        for (int i=1; i<n; ++i) {
            x *= x;
        }
        return x;
    }
    else {
        // 这里要求开根号，
    }

}

int main(int argc, char* argv[]) {

    return 0;
}
