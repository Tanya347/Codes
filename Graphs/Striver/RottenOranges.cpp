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

/********************************************************************** SPACE OPTIMIZED *********************************************************************************/

// TC = O(M*N*4 + M*N) ~ O(M*N) (since we are travelling to every element in the grid)
// SC = O(M*N) (for worst case when all oranges are rotten then queue will have M*N elements)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int, int>> rotten;
        // count is for maintaining the count of oranges that we make rotten
        // time is for counting the time taken
        // total is the total no. of oranges in the matrix
        int count = 0, time = 0, total = 0;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                
                // insert the indices of rotten oranges as we will perform bfs on them
                if(grid[i][j] == 2) 
                    rotten.push({i, j});

                if(grid[i][j] != 0)
                    total++;
            }
        }

        while(!rotten.empty()) {
            
            // find the number of rotten oranges in each level and add it to count
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
            
            // for each level increment time only if queue is not empty, if it is that means all oranges have already been made rotten 
            if(!rotten.empty()) time++;
        }

        // if count is not equal to total that means it is not possible to make all oranges rotten hence return -1
        return (count == total)? time : -1;
    }
};

/********************************************************************** ANOTHER METHOD **************************************************************************************/

// TC = O(M*N*4 + M*N) ~ O(M*N)
// SC = O(M*N) (for worst case when all oranges are rotten then queue will have M*N elements)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        // store {{row, column}, time}
        queue < pair < pair < int, int > , int >> q;
    
        int cntFresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0}); 
                }

                // count fresh oranges
                if (grid[i][j] == 1) cntFresh++;
            }
        }

        int tm = 0;
        // delta row and delta column
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1}; 
        int cnt = 0;

        // bfs traversal (until the queue becomes empty)
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();
            
            // exactly 4 neighbours 
            for (int i = 0; i < 4; i++) {
                // neighbouring row and column
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                // check for valid cell and 
                // then for unvisited fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m  && grid[nrow][ncol] == 1) {
                    // push in queue with timer increased
                    q.push({{nrow, ncol}, t + 1}); 
                    grid[nrow][ncol] = 2;
                    // oranges that become rotten
                    cnt++;
                }
            }
        }

        // if all oranges are not rotten
        if (cnt != cntFresh) return -1;

        return tm;

    }
};

/********************************************************************** EXPLANATION **************************************************************************************/

- here instead of making a pair for indices we are also including a field for time, that increments for every level
- The pairs of cell number and initial time, i.e., <<row, column>, time> will be pushed in the queue and marked as visited (represents rotten) in the visited array. For example, ((2,0), 0) represents cell (2, 0) and initial time 0.  
- count the fresh oranges and also maintain a count of the oranges that we make rotten and if they are not equal that means not all oranges have been made rotten hence return -1

/********************************************************************** MY STUPID CODE **************************************************************************************/

// TC = O(M*N*4 + 2*M*N) ~ O(M*N)
// SC = O(M*N + M*N + 15) ~ O(M*N) 
    
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

/********************************************************************** EXPLANATION **************************************************************************************/

-So upon seeing simultaneous traversal BFS came to mind

-So I started storing all cells with rotten oranges in the queue first and then thought of performing BFS on them one by one and making all oranges rotten

-But if I performed one by one and kept incrementing the time it would be wrong as oranges on same levels are becoming rotten simultaneously

-So I thought of storing each cell’s level and maintaining a check whether this level has been visited or not
    
-If the level is greater than 0 (0 level stands for already rotten oranges which should not contribute to time) and it has not been visited then increment minutes

-While visiting neighbors check whether it is a normal orange and also whether it lies within the ranges. 
    
-After making the rotten orange push the cell to queue and update its level which will be parent’s level + 1
    
-After performing BFS check if there is still a normal orange since that means making all oranges rotten is not possible and hence return –1
