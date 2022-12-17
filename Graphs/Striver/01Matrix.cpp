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

// TC: O(2*M*N) ~ O(M*N) 
// SC: O(M*N)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX - 1));
        
        // first travel in the top left to bottom right direction and find the min distance of upper and left zeroes
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
        
        // then we move from bottom right to top left direction and find min distance of zeroes this time considering bottom and right 0s
        for(int r = m - 1; r >= 0; r--) {
            for(int c = n - 1; c >= 0; c--) {
                if(r != m - 1)
                    distance[r][c] = min(distance[r][c], distance[r + 1][c] + 1);
                if(c != n - 1)
                    distance[r][c] = min(distance[r][c], distance[r][c + 1] + 1);
            }
        }
        
        // we can simply return distance
        return distance;
    }
};

// it may come to your mind why not compute for all 4 directions at once, well the data in first traversal on top and left keeps getting updated but the one on 
// right and bottom doesn't so we can't use that data as of now, so in the second traversal top left data is updated and bottom right data keeps getting updated so we 
// have all the data we need then

/********************************************************************** BFS **************************************************************************************/

// TC: O(M*N + M*N*4) ~ O(M*N) 
// SC: O(M*N)

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
