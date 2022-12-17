/********************************************************************** QUESTION **************************************************************************************/

/*

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.
 

Example 1:

Input: m = 3, n = 7
Output: 28

Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

Constraints:

    1 <= m, n <= 100

*/

/********************************************************************** BRUTE FORCE **************************************************************************************/

// TC: 2^(M*N)

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)
            return 1;

        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};

/********************************************************************** MEMOIZATION **************************************************************************************/

// TC: O(M*N)
// SC: O((N-1)+(M-1)) + O(M*N)
// Reason: We are using a recursion stack space:O((N-1)+(M-1)), here (N-1)+(M-1) is the path length and an external DP Array of size ‘M*N’.

class Solution {
public:

    int uniquePaths(int m, int n, vector<vector<int>>& dp) {
        if(m == 1 || n == 1) {
            dp[m][n] = 1;
            return dp[m][n];
        }

        if(dp[m][n] != -1)
            return dp[m][n];

        dp[m][n] = uniquePaths(m - 1, n, dp) + uniquePaths(m, n - 1, dp);
        return dp[m][n];
    }
 
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return uniquePaths(m, n, dp);
    }
};

/********************************************************************** DP **************************************************************************************/

// TC and SC: O(M*N)

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == m - 1 || j == n - 1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }

        return dp[0][0];
    }
};

/********************************************************************** DP **************************************************************************************/

// TC and SC: O(M*N)

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        for(int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

/********************************************************************** DP WITH 2 ROWS***************************************************************************/

// TC: O(M*N)
// SC: O(N*2)

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // only two rows are functional hence take only two rows
        vector<int> prev(n, 1), curr(n, 1);

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                curr[j] = prev[j] + curr[j - 1];
            }

            // since one row has new data the other row must now be used to utilize that data
            swap(prev, curr);
        }

        // every time we're switching we are operating on curr so answer is with curr
        // but after final swap curr will become prev
        return prev[n - 1];
    }
};

/********************************************************************** DP WITH 1 ROW *********************************************************************************/

// TC: O(M*N)
// SC: O(N)

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<int> dp(n, 1);

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};
