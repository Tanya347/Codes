#include<bits/stdc++.h>
using namespace std;

//function to display the 2-d array
void display(vector<vector<int>> &chess){
    for(int i=0;i<chess.size();i++){
        for(int j=0;j<chess.size();j++){
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printKnightsTour(vector<vector<int>> &chess,int n,int r,int c,int move){

  //write your code here
        if(r < 0 || c < 0 || r >= n || c >= n || chess[r][c] > 0)
            return;
        else if(move == n*n) {
            chess[r][c] = move;
            display(chess);
            chess[r][c] = 0;
            return;
        }

        chess[r][c] = move;

        printKnightsTour(chess, n, r - 2, c + 1, move + 1);
        printKnightsTour(chess, n, r - 1, c + 2, move + 1);
        printKnightsTour(chess, n, r + 1, c + 2, move + 1);
        printKnightsTour(chess, n, r + 2, c + 1, move + 1);
        printKnightsTour(chess, n, r + 2, c - 1, move + 1);
        printKnightsTour(chess, n, r + 1, c - 2, move + 1);
        printKnightsTour(chess, n, r - 1, c - 2, move + 1);
        printKnightsTour(chess, n, r - 2, c - 1, move + 1);

        chess[r][c] = 0;
    }
    
int main(){
        int n, r, c;
        cin>>n>>r>>c;
        vector<vector<int>> chess(n, vector<int>(n));
        printKnightsTour(chess, n, r, c, 1);
    }
