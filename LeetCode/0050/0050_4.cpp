
// leetcode fastest sample

// divide by 2 == move by left

double myPow(double x, int n) {
    if (n == 0)
        return 1;

    if (x == 0)
        return 0;

    if(n == std::numeric_limits<int>::min()) {
        x = x * x;
        n = n >> 1;
    }

    bool div = false;
    if (n < 0) {
        div = true;
        n *= -1;
    }

    double y = 1;
    double p = static_cast<double>(x);

    while (1) {
        if (n & 1)
            y = y * p;
        n = n >> 1;
        if (!n) {
            if (div)
                y = 1.0 / y;
            return y;
        }
        p = p * p;
    }
}
