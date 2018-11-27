

// method 2: using next_permutation to iterate all the permutations
// next_permutation is in leetcode 31
vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > ans;
    sort(num.begin(), num.end());
    ans.push_back(num);

    while(next_permutation(num.begin(), num.end()))
        ans.push_back(num);
    return ans;
}

// O(n) = n log n + n! * (n + n)
// n log n for sort, n! for each possible permutation, n for copying the current solution, + n for next permutation which can be done n in worst case
