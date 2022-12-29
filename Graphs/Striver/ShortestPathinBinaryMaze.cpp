/******************************************************************* QUESTION *******************************************************************************/

/*

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        queue<pair<int, pair<int, int>>> q;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        
        if(grid[0][0] == 1) 
            return -1;

        dist[0][0] = 1;
        q.push({1, {0, 0}});

        while(!q.empty()) {
            
            int distance = q.front().first;
            pair<int, int> cell = q.front().second;
            q.pop();

            if(cell.first == n - 1 && cell.second == n - 1)
                return distance;
            
            int arr[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

            for(int i = 0; i < 8; i++) {
                int x = cell.first + arr[i][0];
                int y = cell.second + arr[i][1];

                if(x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 0) {
                    if(distance + 1 < dist[x][y]) {
                        dist[x][y] = distance + 1;
                        q.push({distance + 1, {x, y}});
                    }
                }
            }

        }

        return -1;
    }
};
