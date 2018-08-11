
#include <string>
#include <cstdio>

using namespace std;

// 暴力解法竟然AC了，竟然没有超时，其实暴力解法还是有很多可以优化的地方的

// 调整了循环的方向，这样能够减少判断的次数

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

