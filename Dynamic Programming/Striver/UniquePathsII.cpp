/********************************************************************** QUESTION **************************************************************************************/

/*

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.
 

Example 1:

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:

Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

    m == obstacleGrid.length
    n == obstacleGrid[i].length
    1 <= m, n <= 100
    obstacleGrid[i][j] is 0 or 1.

*/

/********************************************************************** BRUTE FORCE **************************************************************************************/

// TC: O(2^n)

class Solution {
public:

    int uniquePaths(vector<vector<int>>& obstacleGrid, int i, int j) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // if we exceed array bounds or if the grid is blocked just return 0
        if(i == m || j == n || obstacleGrid[i][j] == 1)
            return 0;
        
        // if we reach destination return 1
        if(i == m - 1 && j == n - 1)
            return 1;

        return uniquePaths(obstacleGrid, i + 1, j) + uniquePaths(obstacleGrid, i, j + 1);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        // if destination itself is blocked there is no path
        if(obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1)
            return 0;
        else
            return uniquePaths(obstacleGrid, 0, 0);
    }
};

/********************************************************************** MEMOIZATION **************************************************************************************/

// TC: O(N*M)
// O((M-1)+(N-1)) + O(N*M)
// Reason: We are using a recursion stack space:O((M-1)+(N-1)), here (M-1)+(N-1) is the path length and an external DP Array of size ‘N*M’.

class Solution {
public:

    int uniquePaths(vector<vector<int>>& obstacleGrid, int i, int j, int m, int n, vector<vector<int>>& dp) {
        
        if(i == m || j == n || obstacleGrid[i][j] == 1) {
            dp[i][j] = 0;
            return dp[i][j];
        }

        if(i == m - 1 && j == n - 1) {
            dp[i][j] = 1;
            return 1;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = uniquePaths(obstacleGrid, i + 1, j, m, n, dp) + uniquePaths(obstacleGrid, i, j + 1, m, n, dp);
        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        if(obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1)
            return 0;
        else
            return uniquePaths(obstacleGrid, 0, 0, m, n, dp);
    }
};

/********************************************************************** DP **************************************************************************************/

// TC: O(N*M)
// SC: O(N*M)

class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // doing this so that there's 1 for padding, it just starts off the chain of answers
        dp[0][1] = 1;

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        } 

        return dp[m][n];
    }
};

class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
    
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                if(i == 0 && j == 0)
                    dp[i][j] = 1;

                else if(!obstacleGrid[i][j]) {
                    int up = 0, left = 0;
                    if(i >= 1)
                        up = dp[i - 1][j];
                    if(j >= 1)
                        left = dp[i][j - 1];
                    dp[i][j] = left + up;
                }
            }
        } 

        return dp[m - 1][n - 1];
    }
};

/********************************************************************** SPACE OPT 2 ROWS ***************************************************************************/

class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> prev(n, 0);

        for(int i = 0; i < m; i++) {
            
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++) {

                if(obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                    continue;
                }

                if(i == 0 && j == 0)
                    curr[j] = 1;

                else if(!obstacleGrid[i][j]) {
                    int up = 0, left = 0;
                    if(i >= 1)
                        up = prev[j];
                    if(j >= 1)
                        left = curr[j - 1];
                    curr[j] = left + up;
                }
            }
            prev = curr;
        } 

        return prev[n - 1];
    }
};

/********************************************************************** SPACE OPT 1 ROW *********************************************************************************/

class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                    continue;
                }

                if(i == 0 && j == 0)
                    dp[j] = 1;

                else if(!obstacleGrid[i][j]) {
                    if(j >= 1)
                        dp[j] += dp[j - 1];
                }
            }
        } 

        return dp[n - 1];
    }
};
