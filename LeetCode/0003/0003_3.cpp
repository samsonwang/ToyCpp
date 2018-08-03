
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

// using brute force

bool isStringWithUniqueString(const string& str)
{
    // 用于判断字符串是否是具有唯一字符的
    
    set<char> setChar;
    for (size_t i = 0; i<str.length(); ++i)
    {
        if (setChar.find(str[i]) != setChar.end())
        {
            return false;
        }
        
        setChar.insert(str[i]);
    }
    return true;
}

int lengthOfLongestSubstring(string s)
{
    int lengthMax = 0;

    for (size_t i=0; i<s.length(); ++i)
    {
        for (size_t j=i+1; j<=s.length(); ++j)
        {
            // get sub-string
            string strTemp = s.substr(i, j-i);
            if (isStringWithUniqueString(strTemp))
            {
                lengthMax = max(lengthMax, (int)strTemp.length());
            }
        }
    }

    return lengthMax;
}

int main(int argc, char *argv[])
{
    // test case
    string str1 = "abcabcbb";
    string str2 = "bbbbbb";
    string str3 = "pwwkew";
    string str4 = "dvdfd";
    string str5 = "a";
    string str6 = "tmmzuxt";

    int n1 = lengthOfLongestSubstring(str1);
    int n2 = lengthOfLongestSubstring(str2);
    int n3 = lengthOfLongestSubstring(str3);
    int n4 = lengthOfLongestSubstring(str4);
    int n5 = lengthOfLongestSubstring(str5);
    int n6 = lengthOfLongestSubstring(str6);

    printf("%s result %d\n", str1.c_str(), n1);
    printf("%s result %d\n", str2.c_str(), n2);
    printf("%s result %d\n", str3.c_str(), n3);
    printf("%s result %d\n", str4.c_str(), n4);
    printf("%s result %d\n", str5.c_str(), n5);
    printf("%s result %d\n", str6.c_str(), n6);
            
    return 0;
}


