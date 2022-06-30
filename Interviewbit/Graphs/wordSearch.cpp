
/********************************************************************** INTERVIEW BIT **************************************************************************************/

/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell. 

The same letter cell may be used more than once.

Example :

Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]

word = "ABCCED", -> returns 1,
word = "SEE", -> returns 1,
word = "ABCB", -> returns 1,
word = "ABFSAB" -> returns 1
word = "ABCD" -> returns 0

Note that 1 corresponds to true, and 0 corresponds to false.

*/


//approach is just to go to every cell and from there check if the word exists or not without keeping check of visited
bool helper(vector<string>& board, string word, int i, int j, int s) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[s] )
            return false;
        
        if(s == word.size() - 1)
            return true;
        
        if(helper(board, word, i + 1, j, s + 1))
            return true;
        if(helper(board, word, i, j + 1, s + 1))
            return true;
        if(helper(board, word, i - 1, j, s + 1))
            return true;
        if(helper(board, word, i, j - 1, s + 1))
            return true;
        return false;
}

int Solution::exist(vector<string> &A, string B) {
    int m = A.size();
    int n = A[0].size();
    
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                bool ans = helper(A, B, i, j, 0);
                if(ans) return 1;
            }
        }
        return 0;
}

/********************************************************************** LEETCODE **************************************************************************************/

/*

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Example 1

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

*/


//keep check of visited rest is same
class Solution {
public:
    
    bool helper(vector<vector<char>> &board, string word, int i, int j, int s) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '0' || board[i][j] != word[s] )
            return false;
        
        if(s == word.size() - 1)
            return true;
        
        board[i][j] = '0';
        
        bool x = helper(board, word, i + 1, j, s + 1);
        bool y = helper(board, word, i, j + 1, s + 1);
        bool z = helper(board, word, i - 1, j, s + 1);
        bool w = helper(board, word, i, j - 1, s + 1);
        
        board[i][j] = word[s];
        
        return x || y || z || w;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
    
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                bool ans = helper(board, word, i, j, 0);
                if(ans) return true;
            }
        }
        return false;
    }
    
};
