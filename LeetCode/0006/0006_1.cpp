
#include <string>
#include <cstdio>
#include <cassert>

using namespace std;

// 通过找规律，总结出每一行的运算规律


string convert(string s, int numRows) {

    int len = s.length();
    assert(numRows > 0);
    int base = 2*numRows - 2;
    if (base == 0) {
        return s;
    }
    
    string ans;
    
    // 第一行和最后一行需要进行特殊处理

    // 第一行
    int i = 0;
    while (base*i < len) {
        ans += s[base*i];
        ++i;
    }

    // 中间行
    for (int j=1; j<numRows-1; ++j) {
        i = 0;
        while (base*i - j < len) {
            
            if (base*i - j >=0 ) {
                ans += s[base*i-j];
            }

            if (base*i + j < len) {
                ans += s[base*i+j];                
            }

            ++i;
        }
    }

    // 最后一行
    int lastStart = numRows - 1;
    i = 0;
    while (lastStart + base*i < len) {
        ans += s[lastStart + base*i];
        ++i;
    }

    return ans;
}

int main(int argc, char* argv[]) {

    string str1 = "PAYPALISHIRING";

    string ret1 = convert(str1, 3);
    string ret2 = convert(str1, 4);
    string ret3 = convert("A", 1);

    printf("ret1: %s\n", ret1.c_str());
    printf("ret2: %s\n", ret2.c_str());
    printf("ret3: %s\n", ret3.c_str());
    
    return 0;
}


