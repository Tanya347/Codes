/********************************************************************** QUESTION **************************************************************************************/

/*

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.


*/

/********************************************************************** BRUTE FORCE **************************************************************************************/

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix, int i, int j, int m, int n) {

        if(i >= 0 && j >= 0 && i < m && j < n) {
            if(i == m - 1)
                return matrix[i][j];
            
            int x = minFallingPathSum(matrix, i+1, j-1, m, n);
            int y = minFallingPathSum(matrix, i+1, j, m, n);
            int z = minFallingPathSum(matrix, i+1, j+1, m, n);
            return matrix[i][j] + min(x, min(y, z));
        }
        else return INT_MAX;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = INT_MAX;
        for(int j = 0; j < n; j++) {

            ans = min(ans, minFallingPathSum(matrix, 0, j, m, n));
        }
        return ans;
    }
};

/********************************************************************** MEMOIZATION **************************************************************************************/

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {

        if(i >= 0 && j >= 0 && i < matrix.size() && j < matrix[0].size()) {
            if(i == matrix.size() - 1) {
                dp[i][j] = matrix[i][j];
                return dp[i][j];
            }
            
            if(dp[i][j] != - 1)
                return dp[i][j];

            int x = minFallingPathSum(matrix, i+1, j-1, dp);
            int y = minFallingPathSum(matrix, i+1, j, dp);
            int z = minFallingPathSum(matrix, i+1, j+1, dp);
            return dp[i][j] = matrix[i][j] + min(x, min(y, z));
        }
        else 
            return INT_MAX;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));

        int ans = INT_MAX;
        for(int j = 0; j < matrix[0].size(); j++) {
            ans = min(ans, minFallingPathSum(matrix, 0, j, dp));
        }

        return ans;
    }
};

/********************************************************************** DP **************************************************************************************/

class Solution {
public:


    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < n; i++) dp[0][i] = matrix[m - 1][i];

        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int x = INT_MAX, y = INT_MAX, z = INT_MAX;
                
                if(j >= 1) x = dp[i - 1][j - 1];
                y = dp[i - 1][j];
                if(j < n - 1) z = dp[i - 1][j + 1];
                
                dp[i][j] = matrix[m - i - 1][j] + min(x, min(y, z));
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            ans = min(ans, dp[m - 1][i]);
        }

        return ans;
    }
};

/********************************************************************** SPACE OPT **************************************************************************************/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> prev(n, 0);

        for(int i = 0; i < n; i++)
            prev[i] = matrix[m - 1][i];

        for(int i = m - 2; i >= 0; i--) {
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++) {
                int x = INT_MAX, y = INT_MAX, z = INT_MAX;
                if(j >= 1)
                    x = prev[j - 1];
                y = prev[j];
                if(j < n - 1)
                    z = prev[j + 1];
                curr[j] = matrix[i][j] + min(x, min(y, z));
            }
            prev = curr;
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            ans = min(ans, prev[i]);
        }

        return ans;
    }
};

/********************************************************************** NO EXTRA SPACE ********************************************************************************/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = m - 2; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                int x = INT_MAX, y = INT_MAX, z = INT_MAX;
                if(j >= 1)
                    x = matrix[i + 1][j - 1];
                y = matrix[i + 1][j];
                if(j < n - 1)
                    z = matrix[i + 1][j + 1];
                matrix[i][j] += min(x, min(y, z));
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            ans = min(ans, matrix[0][i]);
        }

        return ans;
    }
};
