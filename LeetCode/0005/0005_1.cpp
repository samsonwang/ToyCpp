
#include <string>
#include <cstdio>

using namespace std;
// 最容易想到的就是暴力解法了

bool isPalindrome(const string& str) {

    int len = str.length();
    if (len <=0) {
        return false;
    }

    int head = 0;
    int tail = len - 1;

    while (head < tail) {
        if (str[head] != str[tail]) {
            return false;
        }

        ++head;
        --tail;
    }
    
    return true;
}

string longestPalindrome(string s) {

    string ans = "";
    
    for (size_t i=0; i < s.length(); ++i) {
        for (size_t j=1; i+j <= s.length(); ++j) {
            string temp = s.substr(i, j);
            if (isPalindrome(temp)
                && ans.length() < temp.length()) {
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

