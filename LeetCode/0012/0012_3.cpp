
// 这个是耗时最短的答案 16ms
class Solution {
public:
    string intToRoman(int num) {
        string s;

        switch(num / 1000) {
        case 1:
            s += "M"; break;
        case 2:
            s += "MM"; break;
        case 3:
            s += "MMM"; break;
        default:
            break;
        }

        num -= (num / 1000) * 1000;

        switch(num / 100) {
        case 1:
            s += "C"; break;
        case 2:
            s += "CC"; break;
        case 3:
            s += "CCC"; break;
        case 4:
            s += "CD"; break;
        case 5:
            s += "D"; break;
        case 6:
            s += "DC"; break;
        case 7:
            s += "DCC"; break;
        case 8:
            s += "DCCC"; break;
        case 9:
            s += "CM"; break;
        default:
            break;
        }

        num -= (num / 100) * 100;

        switch(num / 10) {
        case 1:
            s += "X"; break;
        case 2:
            s += "XX"; break;
        case 3:
            s += "XXX"; break;
        case 4:
            s += "XL"; break;
        case 5:
            s += "L"; break;
        case 6:
            s += "LX"; break;
        case 7:
            s += "LXX"; break;
        case 8:
            s += "LXXX"; break;
        case 9:
            s += "XC"; break;
        default:
            break;
        }

        num -= (num / 10) * 10;

        switch(num) {
        case 1:
            s += "I"; break;
        case 2:
            s += "II"; break;
        case 3:
            s += "III"; break;
        case 4:
            s += "IV"; break;
        case 5:
            s += "V"; break;
        case 6:
            s += "VI"; break;
        case 7:
            s += "VII"; break;
        case 8:
            s += "VIII"; break;
        case 9:
            s += "IX"; break;
        default:
            break;
        }

        return s;
    }
};

static int x = [] () {
                   ios::sync_with_stdio(false);
                   cin.tie(NULL);
                   return 0;
               } ();
