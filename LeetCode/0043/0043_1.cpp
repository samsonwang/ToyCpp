
#include <string>
using namespace std;


string add(string n1, string n2) {
    //
    int n1pos = (int)n1.size() - 1;
    int n2pos = (int)n2.size() - 1;

    string ret;
    int carry = 0;
    while (n1pos >= 0 || n2pos >= 0 || carry > 0) {
        int n1digit = n1pos<0 ? 0 : (n1[n1pos] - '0');
        int n2digit = n2pos<0 ? 0 : (n2[n2pos] - '0');
        int digit = n1digit + n2digit + carry;
        carry = digit / 10;
        digit = digit % 10;
        char ch = digit + '0';
        ret.insert(ret.begin(), ch);// ch + ret;
        --n1pos;
        --n2pos;
    }
    return ret;
}

string multiply(string num1, string num2) {
    // stores num1 x 0 ~ num1 x 9
    string num1m[10];
    num1m[0] = "0";

    for (int i=1; i<10; ++i) {
        num1m[i] = add(num1m[i-1], num1);
    }

    string ret = "0";
    int n2pos = (int)num2.size() - 1;
    int base = 0;
    while (n2pos >= 0) {
        int n2digit = num2[n2pos] - '0';
        string s = num1m[n2digit];
        if (n2digit != 0 && s != "0") {
            s.insert(s.size(), base, '0');
            ret = add(ret, s);
        }
        --n2pos;
        ++base;
    }

    return ret;
}

int main(int argc, char* argv[]) {

    string n1 = "52";
    string n2 = "0";

    string ret = multiply(n1, n2);

    return 0;
}
