
bool isValid(const vector<string>& board, int A, int row, int col) {
    for(int i = row, j = col; i >= 0; i--) {
        if(board[i][j] == 'Q')
            return false;
    }
    
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q')
            return false;
    }
    
    for(int i = row, j = col; i >= 0 && j < A; i--, j++) {
        if(board[i][j] == 'Q')
            return false;
    }
    
    return true;
}

void helper(vector<vector<string>> &ans, int A, int row, vector<string> board) {
    if(row == A) {
        ans.push_back(board);
        return;
    }
    
    for(int col = 0; col < A; col++) {
        if(isValid(board, A, row, col)) {
            board[row][col] = 'Q';
            helper(ans, A, row + 1, board);
            board[row][col] = '.';
        }
    }
    
    return;
}

vector<vector<string> > Solution::solveNQueens(int A) {
    
    vector<string> board;
    string s = "";
    
    for(int i = 0; i < A; i++)
        s += '.';
    
    for(int i = 0; i < A; i++)
        board.push_back(s);
        
    vector<vector<string>> ans;
    helper(ans, A, 0, board);
    return ans;
}
