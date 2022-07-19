/********************************************************************** QUESTION **************************************************************************************/

/*

Given N x M character matrix A of O's and X's, where O = white, X = black.


Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)




Input Format:

    The First and only argument is a N x M character matrix.

Output Format:

    Return a single integer denoting number of black shapes.

Constraints:

    1 <= N,M <= 1000
    A[i][j] = 'X' or 'O'

Example:

Input 1:
    A = [ OOOXOOO
          OOXXOXO
          OXOOOXO  ]
Output 1:
    3
Explanation:
    3 shapes are  :
    (i)    X
         X X
    (ii)
          X
    (iii)
          X
          X

Note: we are looking for connected shapes here.

XXX
XXX
XXX

is just one single connected black shape.


*/

/********************************************************************** ANSWER **************************************************************************************/

 
void getCount(vector<string> &A, vector<vector<bool>>& visited, int i, int j) {
    
    if(i < 0 || j < 0 || i >= A.size() || j >= A[0].size() || visited[i][j] || A[i][j] == 'O') {
        return;
    }
    
    visited[i][j] = true;
    getCount(A, visited, i + 1, j);
    getCount(A, visited, i, j + 1);
    getCount(A, visited, i - 1, j);
    getCount(A, visited, i, j - 1);
    
}

int Solution::black(vector<string> &A) {
    int n = A.size();
    int m = A[0].length();
    int count = 0;
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j] && A[i][j] == 'X') {
                getCount(A, visited, i, j);
                count++;
            }
        }
    }


