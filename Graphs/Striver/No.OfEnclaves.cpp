/********************************************************************** QUESTION **************************************************************************************/

/*

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:

Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

Example 2:

Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 500
    grid[i][j] is either 0 or 1.


*/

/********************************************************************** DFS **************************************************************************************/

class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == 0)
            return;
       
        grid[i][j] = 0;
        
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        // visit all components that are connected to boundary and mark them visited by making them 0
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if((i == 0 || j == 0 || i == grid.size() - 1 || j == grid[i].size() - 1) && grid[i][j] == 1)
                dfs(grid, i, j);
            }    
        }
        
        // now the 1's left are the answers
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {a
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1)
                    count++;
            }    
        }
        
        return count;
        
    }
};

/********************************************************************** BFS **************************************************************************************/

class Solution {
public:
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        // visit all components that are connected to boundary and mark them visited by making them 0
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((i == 0 || j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1)
                    q.push({i, j});
            }
        }

        // perform bfs
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            grid[x][y] = 0;
            q.pop();

            int arr[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

            for(int k = 0; k < 4; k++) {
                int nx = x + arr[k][0];
                int ny = y + arr[k][1];
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                    q.push({nx, ny});
                }
            }
        }
        
        // now the 1's left are the answers
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1)
                    count++;
            }    
        }
        
        return count;
        
    }
};
