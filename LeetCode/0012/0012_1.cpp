
#include <string>
#include <cstdio>
using namespace std;



string intToRoman(int num) {

    // 按照位，把数字分开
    // 根据题意，最多有4位（1~3999）
    // digit1 ~ 4 分别代表个十百千
    int digit1 = num%10;
    int digit2 = num/10%10;
    int digit3 = num/100%10;
    int digit4 = num/1000%10;

    printf("digit %d => %d %d %d %d\n",
           num, digit4, digit3, digit2, digit1);

    string ans;

    // 千
    for (int i=0; i<digit4; ++i) {
        ans += 'M';
    }

    // 百
    switch (digit3) {
    case 1:
    case 2:
    case 3:
        for (int i=0; i<digit3; ++i) {
            ans += 'C';
        }
        break;

    case 4:
        ans += "CD";
        break;

    case 5:
    case 6:
    case 7:
    case 8:
        ans += 'D';
        for (int i=5; i<digit3; ++i) {
            ans += 'C';
        }
        break;

    case 9:
        ans += "CM";
        break;
    default:
        break;
    }

    // 十
    switch (digit2) {
    case 1:
    case 2:
    case 3:
        for (int i=0; i<digit2; ++i){
            ans += 'X';
        }
        break;

    case 4:
        ans += "XL";
        break;

    case 5:
    case 6:
    case 7:
    case 8:
        ans += 'L';
        for (int i=5; i<digit2; ++i) {
            ans += "X";
        }
        break;

    case 9:
        ans += "XC";
        break;

    default:
        break;
    }

    // 个
    switch (digit1) {
    case 1:
    case 2:
    case 3:
        for (int i=0; i<digit1; ++i) {
            ans += 'I';
        }
        break;

    case 4:
        ans += "IV";
        break;

    case 5:
    case 6:
    case 7:
    case 8:
        ans += 'V';
        for (int i=5; i<digit1; ++i) {
            ans += 'I';
        }
        break;

    case 9:
        ans += "IX";
        break;

    default:
        break;
    }


    return ans;
}

// 写完之后发现这也应该算是比较笨的暴力解法了，因为 要一位位的计算

int main(int argc, char* argv[])
{
    int n1 = 3;
    int n2 = 4;
    int n3 = 9;
    int n4 = 58;
    int n5 = 1994;
    int n6 = 4;

    string ans1 = intToRoman(n1);
    string ans2 = intToRoman(n2);
    string ans3 = intToRoman(n3);
    string ans4 = intToRoman(n4);
    string ans5 = intToRoman(n5);
    string ans6 = intToRoman(n6);

    printf("%d, %s\n", n1, ans1.c_str());
    printf("%d, %s\n", n2, ans2.c_str());
    printf("%d, %s\n", n3, ans3.c_str());
    printf("%d, %s\n", n4, ans4.c_str());
    printf("%d, %s\n", n5, ans5.c_str());
    printf("%d, %s\n", n6, ans6.c_str());

    return 0;
}
