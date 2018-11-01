bool isValidSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < 9; i++) {
        bitset<9> col;
        bitset<9> row;
        bitset<9> rect;
        for(int j = 0; j < 9; j++) {
            //check row
            if(board[i][j] != '.' && row[board[i][j]] == true) {
                return false;
            }
            else {
                row[board[i][j]] = true;
            }

            //check col
            if(board[j][i] != '.' && col[board[j][i]] == true) {
                return false;
            }
            else {
                col[board[j][i]] = true;
            }

            //check 3x3
            int x = (3 * (i % 3)) + (j % 3);
            int y = (3 * (i / 3)) + (j / 3);

            //check rect
            if(board[y][x] != '.' && rect[board[y][x]] == true) {
                return false;
            }
            else {
                rect[board[y][x]] = true;
            }
        }
    }

    return true;
}
