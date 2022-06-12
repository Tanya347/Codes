#include<bits/stdc++.h>
using namespace std;

bool checkValid(vector<vector<int>>& board, int i, int j, int val) {
    
    for(int x = 0; x < 9; x++) {
        if(board[x][j] == val) return false;
        if(board[i][x] == val) return false;
    }
    
    for(int x = 0; x < 3; x++) {
            for(int y = 0; y < 3; y++) {
                if(board[3*(i/3) + x][3*(j/3) + y] == val)
                    return false;
            }
        }
    
    return true;
}

bool solveSudoku(vector<vector<int>>& board, int i, int j) {
    
    if(i == 9) {
        return true;
    }
    
    if(j == 9) {
        return solveSudoku(board, i + 1, 0);
    }
    
    if(board[i][j] != 0)
        return solveSudoku(board, i, j + 1);
    
    for(int k = 1; k <= 9; k++) {
        if(checkValid(board, i, j, k)) {
            board[i][j] = k;
            if(solveSudoku(board, i, j + 1))
                return true;
            board[i][j] = 0;
        } 
    }
    
    return false;
}


int main(){
    
    // write your code here
    vector<vector<int>> board(9, vector<int>(9));
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin>>board[i][j];
        }
    }
    
    if(solveSudoku(board, 0, 0)) 
        cout<<"true";
    else
        cout<<"false";
    return 0;
}
