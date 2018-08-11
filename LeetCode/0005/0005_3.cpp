
#include <string>
#include <cstdio>

using namespace std;

// 使用暴力解法显然不是这道题目的本意
// 我还有一个思路的以某个字符为中心进行展开

string longestPalindrome(string s) {

    string ans = "";
    
    for (size_t i=0; i < s.length(); ++i) {

        // 如何确定初始的边界很重要
        
        
        for (size_t j=s.length()-i; j != 0; --j) {

            if (ans.length() >= j) {
                continue;
            }
            
            string temp = s.substr(i, j);
            if (ans.length() < temp.length()
                && isPalindrome(temp)) {
                ans = temp;
            }
        }

        
    }

    return ans;
}

int main(int argc, char* argv[]) {

    string str1 = "abab";
    string str2 = "bb";
    string str3 = "a";

    
    string ret1 = longestPalindrome(str1);
    string ret2 = longestPalindrome(str2);
    string ret3 = longestPalindrome(str3);

    printf("%s---%s\n", str1.c_str(), ret1.c_str());
    printf("%s---%s\n", str2.c_str(), ret2.c_str());
    printf("%s---%s\n", str3.c_str(), ret3.c_str());
    

    return 0;
}

