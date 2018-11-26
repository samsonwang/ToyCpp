
#include <string>
using namespace std;

string multiply(string num1, string num2) {
    vector<int> vt(num1.size()+ num2.size()-1, 0);
    for (int i = num1.size()-1; i>= 0; i--) {
        for (int j = num2.size()-1; j>=0; j--) {
            vt[i+j] += (num1[i] -'0')* (num2[j] - '0');
        }
    }
    for (int i = vt.size()-1; i>0 ; i--) {
        if (vt[i] >= 10) {
            vt[i-1] += vt[i] /10;
            vt[i] = vt[i] % 10;
        }
    }
    if (vt[0] == 0) return "0";

    string tmp;
    for (auto u : vt)
        tmp += to_string(u);
    return tmp;
}

int main(int argc, char* argv[]) {

    string n1 = "52";
    string n2 = "0";

    string ret = multiply(n1, n2);

    return 0;
}
