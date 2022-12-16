/********************************************************************** QUESTION **************************************************************************************/

/*

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

 

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 104
    1 <= m * n <= 104
    mat[i][j] is either 0 or 1.
    There is at least one 0 in mat.

*/

/********************************************************************** DP **************************************************************************************/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX - 1));
        
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(mat[r][c] == 0) {
                    distance[r][c] = 0;
                    continue;
                }
                
                if(r > 0)
                    distance[r][c] = min(distance[r][c], distance[r - 1][c] + 1);
                if(c > 0)
                    distance[r][c] = min(distance[r][c], distance[r][c - 1] + 1);
            }
        }
        
        for(int r = m - 1; r >= 0; r--) {
            for(int c = n - 1; c >= 0; c--) {
                if(r != m - 1)
                    distance[r][c] = min(distance[r][c], distance[r + 1][c] + 1);
                if(c != n - 1)
                    distance[r][c] = min(distance[r][c], distance[r][c + 1] + 1);
            }
        }
        
        return distance;
    }
};

/********************************************************************** BFS **************************************************************************************/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        queue<pair<int, int>> q;
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0)
                    q.push({i, j});
                if(mat[i][j] == 1)
                    mat[i][j] = -1;
            }
        }

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            int arr[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
            for(int k = 0; k < 4; k++) {
                int nx = x + arr[k][0];
                int ny = y + arr[k][1];
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && mat[nx][ny] == -1) {
                    mat[nx][ny] = mat[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return mat;
    }
};
