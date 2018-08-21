
// https://leetcode.com/problems/string-to-integer-atoi/description/


#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>

using namespace std;

// 这道题并不难，思路也比较容易想出来
// 可能需要注意的问题是
// 1. 字符到数字的转换，这个涉及到ascii码表的记忆
//    如果记不住了可以使用'0' 'a' 'A'
// 2. 这道题所需要注意的细节问题还是比较多的


int parseChar(char ch) {
    int num = ch - '0';
    if (num > 9 || num < 0) {
        return -1;
    }

    return num;
}

int myAtoi (string str) {

    bool isNegative = false;
    bool isOverflow = false;
    int num = 0;

    // 从前向后进行转换
    size_t pos = 0;

    // 去除多余的空格
    while (str[pos] == ' ') {
        ++pos;
    }

    // 首先判断是否有符号位
    if (str.length() > 0) {
        if (str[pos] == '-') {
            isNegative = true;
            ++pos;
        }
        else if (str[pos] == '+') {
            ++pos;
        }
    }

    // 是否以数字进行开头
	// 从左向右读取数字，每次读取需要判断是否溢出
    for ( ; pos < str.length(); ++pos) {
        int digit = parseChar(str[pos]);
        if (digit < 0) {
            // 负数说明该位不是数字了
            break;
        }

        // 如何判断是否溢出
        int temp = num*10;
        if (temp/10 != num) {
            isOverflow = true;
            break;
        }

        num = temp + digit;
    }

    // 如果num变成负数，也是溢出了，相当于对最后一位检查溢出
    if (isOverflow || num < 0) {
        return isNegative ? INT_MIN : INT_MAX;
    }

    int ans = isNegative ? -num : num;

    return ans;
}

int main(int argc, char* argv[])
{
    string str1 = "42";
    string str2 = "-42";
    string str3 = "4193 with words";
    string str4 = "words and 987";
    string str5 = "-91283472332";
    string str6 = "   -42";
    string str7 = "+45";
    string str8 = "  +46";
    string str9 = "2147483648";

    int ans1 = myAtoi(str1);
    int ans2 = myAtoi(str2);
    int ans3 = myAtoi(str3);
    int ans4 = myAtoi(str4);
    int ans5 = myAtoi(str5);
    int ans6 = myAtoi(str6);
    int ans7 = myAtoi(str7);
    int ans8 = myAtoi(str8);
    int ans9 = myAtoi(str9);

    printf("%s, %d\n", str1.c_str(), ans1);
    printf("%s, %d\n", str2.c_str(), ans2);
    printf("%s, %d\n", str3.c_str(), ans3);
    printf("%s, %d\n", str4.c_str(), ans4);
    printf("%s, %d\n", str5.c_str(), ans5);
    printf("%s, %d\n", str6.c_str(), ans6);
    printf("%s, %d\n", str7.c_str(), ans7);
    printf("%s, %d\n", str8.c_str(), ans8);
    printf("%s, %d\n", str9.c_str(), ans9);


    printf("%x, %x\n", INT_MAX, INT_MIN);

    return 0;
}
