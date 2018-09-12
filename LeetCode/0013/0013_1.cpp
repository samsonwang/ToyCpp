

#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

static auto fast = []() {
                       ios_base::sync_with_stdio(0);
                       cin.tie(0);
                       cout.tie(0);
                       return 0;
                   }();


int romanToInt(string str) {

    int ans = 0;
    int pos = 0;
    const int len = str.length();

    // 千位
    while (pos < len && str[pos] == 'M') {
        ++pos;
    }
    ans += 1000 * pos;
    if (pos == len) {
        return ans;
    }

    // 百位
    switch (str[pos]) {
    case 'C':
        ans += 100;
        ++pos;

        if (str[pos] == 'D') {
            ans += 300;
            ++pos;
        }
        else if (str[pos] == 'M') {
            ans += 800;
            ++pos;
        }
        else {
            while (pos < len && str[pos] == 'C') {
                ans += 100;
                ++pos;
            }
        }

        break;

    case 'D':
        ans += 500;
        ++pos;
        while (pos < len && str[pos] == 'C') {
            ans += 100;
            ++pos;
        }
        break;

    default:
        break;
    }
    if (pos == len) {
        return ans;
    }

    // 十位
    switch (str[pos]) {
    case 'X':
        ans += 10;
        ++pos;

        if (str[pos] == 'C') {
            ans += 80;
            ++pos;
        }
        else if (str[pos] == 'L'){
            ans += 30;
            ++pos;
        }
        else {
            while (pos < len && str[pos] == 'X') {
                ans += 10;
                ++pos;
            }
        }
        break;

    case 'L':
        ans += 50;
        ++pos;
        while (pos < len && str[pos] == 'X') {
            ans += 10;
            ++pos;
        }
        break;

    default:
        break;
    }
    if (pos == len) {
        return ans;
    }

    // 个位
    switch (str[pos]) {
    case 'I':
        ans += 1;
        ++pos;
        if (str[pos] == 'X') {
            ans += 8;
            ++pos;
        }
        else if (str[pos] == 'V') {
            ans += 3;
            ++pos;
        }
        else {
            while (pos < len && str[pos] == 'I') {
                ++ans;
                ++pos;
            }
        }

        break;
    case 'V':
        ans += 5;
        ++pos;
        while (pos < len && str[pos] == 'I') {
            ++ans;
            ++pos;
        }
        break;
    default:
        break;
    }

    return ans;
}

int main(int argc, char* argv[]) {
    string str1 = "III";
    string str2 = "IV";
    string str3 = "IX";
    string str4 = "LVIII";
    string str5 = "MCMXCIV";
    string str6 = "DCXXI";
    string str7 = "MMMXLV";

    int ret1 = romanToInt(str1);
    int ret2 = romanToInt(str2);
    int ret3 = romanToInt(str3);
    int ret4 = romanToInt(str4);
    int ret5 = romanToInt(str5);
    int ret6 = romanToInt(str6);
    int ret7 = romanToInt(str7);

    printf("%s\t\t-  %d\n", str1.c_str(), ret1);
    printf("%s\t\t-  %d\n", str2.c_str(), ret2);
    printf("%s\t\t-  %d\n", str3.c_str(), ret3);
    printf("%s\t\t-  %d\n", str4.c_str(), ret4);
    printf("%s\t\t-  %d\n", str5.c_str(), ret5);
    printf("%s\t\t-  %d\n", str6.c_str(), ret6);
    printf("%s\t\t-  %d\n", str7.c_str(), ret7);

    return 0;
}
