/********************************************************************** QUESTION **************************************************************************************/

/*

You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0. 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 10
    grid[i][j] is 0, 1, or 2.

*/

/********************************************************************** BRUTE FORCE **************************************************************************************/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        if(grid.empty()) return 0;

        queue<pair<int, int>> rotten;
        int count = 0, time = 0, total = 0;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 2) 
                    rotten.push({i, j});

                if(grid[i][j] != 0)
                    total++;
            }
        }

        while(!rotten.empty()) {

            int k = rotten.size();
            count += k;

            while(k--) {
                
                int x = rotten.front().first;
                int y = rotten.front().second;

                rotten.pop();

                int arr[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

                for(int i = 0; i < 4; i++) {
                    int j = x + arr[i][0];
                    int k = y + arr[i][1];

                    if(j >= 0 && k >= 0 && j < m && k < n && grid[j][k] == 1) {
                        grid[j][k] = 2;
                        rotten.push({j, k});
                    }
                }
            }

            if(!rotten.empty()) time++;
        }

        return (count == total)? time : -1;
    }
};

/********************************************************************** BRUTE FORCE **************************************************************************************/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int mins = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> cell;
        
        vector<vector<int>> level(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    cell.push({i, j});
                }
            }
        }
        
        vector<bool> visited(15, false);
            
        while(!cell.empty()) {
            
            int i = cell.front().first;
            int j = cell.front().second;
            cell.pop();
            
            if(!visited[level[i][j]]) {
                if(level[i][j])
                    mins++;
                visited[level[i][j]] = true;

            }
            
            int arr[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            
            for(int k = 0; k < 4; k++) {
                int x = i + arr[k][0];
                int y = j + arr[k][1];
                
                if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0)
                    continue;
                
                if(grid[x][y] == 1) {
                    grid[x][y] = 2;
                    cell.push({x, y});
                    level[x][y] = level[i][j] + 1;
                }
            }
            
            
        }
            
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) 
                    return -1;
            }
        }
        
        return mins;
    }
};



