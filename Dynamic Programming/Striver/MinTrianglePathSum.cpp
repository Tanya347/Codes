/********************************************************************** QUESTION **************************************************************************************/

/*

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:

Input: triangle = [[-10]]
Output: -10


Constraints:

    1 <= triangle.length <= 200
    triangle[0].length == 1
    triangle[i].length == triangle[i - 1].length + 1
    -104 <= triangle[i][j] <= 104

 
Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?

*/

/********************************************************************** BRUTE FORCE *******************************************************************************/

class Solution {
public:

    int rec(vector<vector<int>>& triangle, int i, int j) {
        int m = triangle.size();
        int n = triangle[i].size();

        if(i == m - 1)
            return triangle[i][j];

        if(j == n)
            return INT_MAX;

        return triangle[i][j] + min(rec(triangle, i + 1, j), rec(triangle, i + 1, j + 1));

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1)    
            return triangle[0][0];
        return rec(triangle, 0, 0);
    }
};

/********************************************************************** MEMOIZATION **************************************************************************************/

class Solution {
public:

    int rec(vector<vector<int>>& triangle, int i, int j, int** dp) {

        if(i == triangle.size() - 1) {
            dp[i][j] = triangle[i][j];
            return triangle[i][j];
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(j == triangle[i].size())
            return INT_MAX;

        dp[i][j] = triangle[i][j] + min(rec(triangle, i + 1, j, dp), rec(triangle, i + 1, j + 1, dp));
        return dp[i][j];

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1)    
            return triangle[0][0];
        
        int **dp = new int*[triangle.size()];
        for(int i = 0; i < triangle.size(); i++) {
            dp[i] = new int[i + 1];
            for(int j = 0; j < i + 1; j++) {
                dp[i][j] = -1;
            }
        }

        return rec(triangle, 0, 0, dp);
    }
};

/********************************************************************** DP **************************************************************************************/

// striver

int minimumPathSum(vector<vector<int> > &triangle, int n){
    vector<vector<int> > dp(n,vector<int>(n,0));
    
    for(int j=0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = triangle[i][j]+dp[i+1][j];
            int diagonal = triangle[i][j]+dp[i+1][j+1];
            
            dp[i][j] = min(down, diagonal);
        }
    }
    
    return dp[0][0];
    
}

// mine
class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {

        int m = triangle.size();

        if(triangle.size() == 1)    
            return triangle[0][0];
        
        int **dp = new int*[m];
        for(int i = 0; i < m; i++) {
            dp[i] = new int[i + 1];
            for(int j = 0; j < i + 1; j++) {
                dp[i][j] = 0;
            }
        }

        dp[0][0] = triangle[0][0];

        for(int i = 1; i < m; i++) {
            for(int j = 0; j < i + 1; j++) {
                if(j == i)
                    dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                else if(j == 0)
                    dp[i][j] = triangle[i][j] +  dp[i - 1][j];
                else
                    dp[i][j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i < triangle[m - 1].size(); i++)
            ans = min(ans, dp[m - 1][i]);
        
        return ans;
    }
};

/********************************************************************** SPACE OPT 1 ROW **************************************************************************************/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m - 1].size();
        vector<int> curr(n, 0);

        for(int i = 0; i < n; i++) {
            curr[i] = triangle[m - 1][i];
        }

        for(int i = m - 2; i >= 0; i--) {
            for(int j = 0; j < i + 1; j++) {
                curr[j] = triangle[i][j] + min(curr[j], curr[j + 1]); 
            }
        }

        return curr[0];
    }
};

/********************************************************************** OPTIMIZED SPACE ******************************************************************************/

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {

        int m = triangle.size();

        if(triangle.size() == 1)    
            return triangle[0][0];
        
        for(int i = m - 2; i >= 0; i--) {
            for(int j = 0; j < triangle[i].size(); j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};
