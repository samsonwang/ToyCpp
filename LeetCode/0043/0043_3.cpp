
#include <string>
#include <vector>
using namespace std;

// graph demostrates
string multiply(string num1, string num2) {
    vector<int> nums(num1.size()+num2.size(), 0);

    for (int i=(int)num1.size()-1; i>=0; --i) {
        for (int j=(int)num2.size()-1; j>=0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = nums[i+j+1] + mul;
            nums[i+j+1] = sum % 10;
            nums[i+j] += sum / 10;
        }
    }
    
    // skip leading zero
    bool leadingZero = true;
    string ret;
    for (auto n : nums) {
        if (n == 0 && leadingZero) {
            continue;
        }
        else {
            leadingZero = false;
        }

        ret += to_string(n);
    }
    
    if (ret.empty()) {
        return "0";
    }

    return ret;
}

int main(int argc, char* argv[]) {

    string n1 = "123";
    string n2 = "456";

    string ret = multiply(n1, n2);

    return 0;
}
