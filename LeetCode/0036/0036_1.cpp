
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// brute force
bool isValidSudoku(vector<vector<char>>& board) {
    int exist[10];
    // row
    for (size_t i=0; i<9; ++i) {
        memset(exist, 0, sizeof(exist));
        for (size_t j=0; j<9; ++j) {
            char ch = board[i][j];
            if (ch == '.') {
                continue;
            }
            int n = ch - '0';
            if (exist[n] == 1) {
                return false;
            }
            exist[n] = 1;
        }
    }

    // column
    for (size_t i=0; i<9; ++i) {
        memset(exist, 0, sizeof(exist));
        for (size_t j=0; j<9; ++j) {
            char ch = board[j][i];
            if (ch == '.') {
                continue;
            }
            int n = ch - '0';
            if (exist[n] == 1) {
                return false;
            }
            exist[n] = 1;
        }
    }
    // sub-box
    vector<vector<int>> index{
        {0,0},
        {0,1},
        {0,2},
        {1,0},
        {1,1},
        {1,2},
        {2,0},
        {2,1},
        {2,2}};

    for (size_t m=0; m<9; m=m+3) {
        for (size_t n=0; n<9; n=n+3) {
            memset(exist, 0, sizeof(exist));
            for (size_t i=0; i<index.size(); ++i) {
                size_t x = index[i][0] + m;
                size_t y = index[i][1] + n;
                char ch = board[x][y];
                if (ch == '.') {
                    continue;
                }
                int n = ch - '0';
                if (exist[n] == 1) {
                    return false;
                }
                exist[n] = 1;
            }

        }
    }

    return true;
}

int main(int argc, char* argv[]) {

    vector<vector<char>> board2{
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    vector<vector<char>> board{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};

    for (const auto& line : board) {
        for (char ch : line) {
            cout << ch << " ";
        }
        cout << endl;
    }


    bool ans = isValidSudoku(board);

    cout << ans << endl;

    return 0;
}
