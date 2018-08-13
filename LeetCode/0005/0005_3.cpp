
#include <string>
#include <cstdio>

using namespace std;

// 使用暴力解法显然不是这道题目的本意
// 我还有一个思路的以某个字符为中心进行展开

string longestPalindrome(string s) {

    string ans = "";
    
    for (size_t i=0; i < s.length(); ++i) {

        // 如何确定初始的边界很重要
        size_t j = i;
        size_t k = i;

        // 向两边拓展边界
        while (j-1>=0 && s[j-1]==s[i]) {
            --j;
        }

        while (k+1<s.length() && s[k+1]==s[i]) {
            ++k;
        }

        while (j-1>=0
               && k+1<s.length()
               && s[j-1]==s[k+1]) {
            --j;
            ++k;
        }

        if (k-j+1 > ans.length()) {
            ans = s.substr(j, k-j+1);
        }
    }

    return ans;
}

int main(int argc, char* argv[]) {

    string str1 = "abab";
    string str2 = "bb";
    string str3 = "a";
    string str4 = "babad";

    
    string ret1 = longestPalindrome(str1);
    string ret2 = longestPalindrome(str2);
    string ret3 = longestPalindrome(str3);
    string ret4 = longestPalindrome(str4);

    printf("%s---%s\n", str1.c_str(), ret1.c_str());
    printf("%s---%s\n", str2.c_str(), ret2.c_str());
    printf("%s---%s\n", str3.c_str(), ret3.c_str());
    printf("%s---%s\n", str4.c_str(), ret4.c_str());
    

    return 0;
}

