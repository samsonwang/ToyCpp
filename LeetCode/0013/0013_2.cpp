
static int fast = []() {
                      ios_base::sync_with_stdio(0);
                      cin.tie(0);
                      cout.tie(0);
                      return 0;
                  }();

// 这个方法更具有规律性，而且在leetcode上的速度是最快的


int romanToInt(string s) {
    int result = 0;
    int size = s.size();
    for(int i = 0; i < size; ++i) {
        switch(s[i]) {
        case 'M':
            if(i - 1 >= 0 && s[i - 1] == 'C')
                result += 800;
            else
                result += 1000;
            break;

        case 'D':
            if(i - 1 >= 0 && s[i - 1] == 'C')
                result += 300;
            else
                result += 500;
            break;

        case 'C':
            if(i - 1 >= 0 && s[i - 1] == 'X')
                result += 80;
            else
                result += 100;
            break;

        case 'L':
            if(i - 1 >= 0 && s[i - 1] == 'X')
                result += 30;
            else
                result += 50;
            break;

        case 'X':
            if(i - 1 >= 0 && s[i - 1] == 'I')
                result += 8;
            else
                result += 10;
            break;

        case 'V':
            if(i - 1 >= 0 && s[i - 1] == 'I')
                result += 3;
            else
                result += 5;
            break;

        case 'I':
            result += 1;
            break;

        default:;
        }
    }
    return result;
}
