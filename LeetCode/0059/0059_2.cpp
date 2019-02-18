
// leetcode submission sample

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        if (n == 0)
            return res;
        int colBeg = 0, colEnd = n - 1;
        int rowBeg = 0, rowEnd = n - 1;
        int count = 1;
        while (colBeg <= colEnd && rowBeg <= rowEnd) {
            for (int i = colBeg; i <= colEnd; ++i)
                res[rowBeg][i] = count++;
            for (int j = rowBeg+1; j <= rowEnd; ++j)
                res[j][colEnd] = count++;
            if (rowBeg < rowEnd&& colBeg < colEnd) {
                for (int i = colEnd-1; i > colBeg; --i)
                    res[rowEnd][i] = count++;
                for (int j = rowEnd; j > rowBeg; --j)
                    res[j][colBeg] = count++;
            }
            rowBeg++;
            colBeg++;
            rowEnd--;
            colEnd--;
        }
        return res;
    }
};
