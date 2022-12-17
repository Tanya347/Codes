/********************************************************************** QUESTION **************************************************************************************/

/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
 

Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 200
    0 <= grid[i][j] <= 100

*/

/********************************************************************** BRUTE FORCE ************************************************************************************/

// TC: 2^m*n

class Solution {
public:

    int rec(vector<vector<int>>& grid, int i, int j) {

        int m = grid.size();
        int n = grid[0].size();

        if(i == m - 1 && j == n - 1)
            return grid[i][j];

        if(i == m || j == n)
            return INT_MAX;
        
        return grid[i][j] + min(rec(grid, i + 1, j), rec(grid, i, j + 1));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return rec(grid, 0, 0);
    }
};

/********************************************************************** MEMOIZATION *******************************************************************************/

// TC: O(N*M)
// SC: O((M-1)+(N-1)) + O(N*M)
// Reason: We are using a recursion stack space:O((M-1)+(N-1)), here (M-1)+(N-1) is the path length and an external DP Array of size ‘N*M’.

class Solution {
public:

    int rec(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        if(i == m || j == n)
            return INT_MAX;
            
        if(dp[i][j] != -1)
            return dp[i][j];

        if(i == m - 1 && j == n - 1) {
            dp[i][j] = grid[i][j];
            return dp[i][j];
        }

        dp[i][j] = grid[i][j] + min(rec(grid, i + 1, j, dp), rec(grid, i, j + 1, dp));
        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return rec(grid, 0, 0, dp);
    }
};

/********************************************************************** DP **************************************************************************************/

// TC: O(N*M)
// SC: O(N*M)

// two ways this one is more intuitive if we code according to the recursion approach
int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        if(m == 1 && n == 1) {
            return grid[0][0];
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == m - 1 && j == n - 1)
                    dp[i][j] = grid[i][j];
                else if(i == m - 1 && j != n - 1)
                    dp[i][j] = grid[i][j] + dp[i][j + 1];
                else if(i != m - 1 && j == n - 1)
                    dp[i][j] = grid[i][j] + dp[i + 1][j];
                else
                    dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[0][0];
    }
};

// this one is similar to above approach just flip the direction
int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        if(m == 1 && n == 1) {
            return grid[0][0];
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else if(i == 0 && j != 0)
                    dp[i][j] = grid[i][j] + dp[i][j - 1];
                else if(i != 0 && j == 0)
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                else
                    dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
};

/********************************************************************** OPTIMIZED SPACE ******************************************************************************/

// TC: O(N*M)
// SC: O(N)

class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        if(m == 1 && n == 1) {
            return grid[0][0];
        }
        
        // We can just use grid instead of a whole new array because it just kept adding stuff from previous cells
        // which can also be done from previous cells in grid
      
        for(int i = 1; i < n; i++)
            grid[0][i] += grid[0][i - 1];
        
        for(int i = 1; i < m; i++)
            grid[i][0] += grid[i - 1][0];
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};
