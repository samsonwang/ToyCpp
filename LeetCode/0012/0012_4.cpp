static int fast = []() {
                      ios_base::sync_with_stdio(0);
                      cin.tie(0);
                      cout.tie(0);
                      return 0;
                  }();

// 这样的打表法显得更加优雅
class Solution {
public:
    string intToRoman(int num) {
        vector<int> base{1000, 100, 10, 1};
        string roman = "MDCLXVI";
        int index = 0, r;
        string ret = "";
        while(num) {
            r = num/base[index];
            num = num - r*base[index];
            if(r == 4) {
                ret += roman[2*index];
                ret += roman[2*index-1];
            }
            else if(r == 9) {
                ret += roman[2*index];
                ret += roman[2*index -2];
            }
            else if(r >= 5) {
                ret += roman[2*index - 1];
                // 下面这个string的用法值得学习
                string tmp(r-5, roman[2*index]);
                ret += tmp;
            }
            else if(r < 5) {
                string tmp(r, roman[2*index]);
                ret += tmp;
            }
            index++;
        }
        return ret;
    }
};
