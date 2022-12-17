/********************************************************************** QUESTION **************************************************************************************/

/*

You are given an r rows and c cols matrix grid representing a field of cherries where grid[i][j] represents the number of chocolates that you can collect from the (i, j) cell.

You have two robots that can collect chocolates for you:

    Robot #1 is located at the top-left corner (0, 0), and
    Robot #2 is located at the top-right corner (0, cols - 1).

Return the maximum number of chocolates collection using both robots by following the rules below:

    From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
    When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.
    When both robots stay in the same cell, only one takes the chocolates.
    Both robots cannot move outside of the grid at any moment.
    Both robots should reach the bottom row in grid.

Example:

Input:
r = 3, c = 4
grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output:
24
Explanation:
Path of robot #1 and #2 are described in color green and blue respectively. Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12. Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12. Total of cherries: 12 + 12 = 24.

Your Task:
You don't need to read input or print anything. Your task is to complete the function Solve() which takes r rows, c column and a matrix grid and returns the maximum number of chocolates can be collect by two robots.

Expected Time Complexity: O(r * c * c)
Expected Space Complexity: O(c * c * c)

Constraint:
2 <= r < = 70
0 <= grid[i][j] <= 100


*/

/********************************************************************** BRUTE FORCE **********************************************************************************/

class Solution {
  public:
  
  
    int rec(int i, int j1, int j2, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // should not take INT_MIN, as addition to some integer may take it out of bounds
        if(j1 < 0 || j2 < 0 || j1 >= n || j2 >= n)
            return -1e8;
            
        // base case
        if(i == m - 1) {
            if(j1 == j2)
                return grid[i][j1];
            else 
                return grid[i][j1] + grid[i][j2];
        }
        
        // for every column robot1 can go to there are three columns robot2 to can go
        // hence there are a total of 9 combinations that the robots can traverse simultaneously
        int maxi = 0;
        for(int dj1 = -1; dj1 < 2; dj1++) {
            for(int dj2 = -1; dj2 < 2; dj2++) {
                int temp;
                // this is the case when the robots end up at the same column
                if(j1 == j2)
                    temp = grid[i][j1] + rec(i + 1, j1 + dj1, j2 + dj2, grid);
                else
                    temp = grid[i][j1] + grid[i][j2] + rec(i + 1, j1 + dj1, j2 + dj2, grid);
                
                maxi = max(maxi, temp);
            }
        }
        
        return maxi;
    }
  
    int solve(int m, int n, vector<vector<int>>& grid) {
        // code here
        
        // we take 3 variables, i denotes the row on which we are and j1 and j2 denote
        // the columns at which robot1 and robot2 are at
        return rec(0, 0, n - 1, grid);
    }
 
 /********************************************************************** MEMOIZATION ********************************************************************************/
  
 class Solution {
  public:
  
  
    int rec(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(j1 < 0 || j2 < 0 || j1 >= n || j2 >= n)
            return -1e8;
            
        // base case
        if(i == m - 1) {
            if(j1 == j2)
                return grid[i][j1];
            else 
                return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
        
        int maxi = 0;
        for(int dj1 = -1; dj1 < 2; dj1++) {
            for(int dj2 = -1; dj2 < 2; dj2++) {
                int temp;
                
                if(j1 == j2)
                    temp = grid[i][j1] + rec(i + 1, j1 + dj1, j2 + dj2, grid, dp);
                else
                    temp = grid[i][j1] + grid[i][j2] + rec(i + 1, j1 + dj1, j2 + dj2, grid, dp);
                
                maxi = max(maxi, temp);
            }
        }
        
        return dp[i][j1][j2] = maxi;
    }
  
    int solve(int m, int n, vector<vector<int>>& grid) {
        // code here
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return rec(0, 0, n - 1, grid, dp);
    }
};
  
 /********************************************************************** DP **************************************************************************************/

  class Solution {
  public:
  
  
    int rec(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(j1 < 0 || j2 < 0 || j1 >= n || j2 >= n)
            return -1e8;
            
        // base case
        if(i == m - 1) {
            if(j1 == j2)
                return grid[i][j1];
            else 
                return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
        
        int maxi = 0;
        for(int dj1 = -1; dj1 < 2; dj1++) {
            for(int dj2 = -1; dj2 < 2; dj2++) {
                int temp;
                
                if(j1 == j2)
                    temp = grid[i][j1] + rec(i + 1, j1 + dj1, j2 + dj2, grid, dp);
                else
                    temp = grid[i][j1] + grid[i][j2] + rec(i + 1, j1 + dj1, j2 + dj2, grid, dp);
                
                maxi = max(maxi, temp);
            }
        }
        
        return dp[i][j1][j2] = maxi;
    }
  
    int solve(int m, int n, vector<vector<int>>& grid) {
        // code here
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return rec(0, 0, n - 1, grid, dp);
    }
};
