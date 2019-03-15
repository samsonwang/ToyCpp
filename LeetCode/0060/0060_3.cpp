

// solution from leetcode
// https://leetcode.com/problems/permutation-sequence/discuss/22544/Most-concise-C%2B%2B-solution-minimal-memory-required

string getPermutation(int n, int k) {
    int i,j,f=1;
    // left part of s is partially formed permutation, right part is the leftover chars.
    string s(n,'0');
    for(i=1;i<=n;i++){
        f*=i;
        s[i-1]+=i; // make s become 1234...n
    }
    for(i=0,k--;i<n;i++){
        f/=n-i;
        j=i+k/f; // calculate index of char to put at s[i]
        char c=s[j];
        // remove c by shifting to cover up (adjust the right part).
        for(;j>i;j--)
            s[j]=s[j-1];
        k%=f;
        s[i]=c;
    }
    return s;
}

/*
  这个方法与0060_2的思路相似，但使用的内存更少，直接在string中进行字符的移动操作
*/
