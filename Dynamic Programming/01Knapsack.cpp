/********************************************************************** QUESTION **************************************************************************************/

/*

You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

Example 1:

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3

Example 2:

Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0

Your Task:
Complete the function knapSack() which takes maximum capacity W, weight array wt[], value array val[], and the number of items n as a parameter and returns the maximum possible value you can get.

Expected Time Complexity: O(N*W).
Expected Auxiliary Space: O(N*W)

Constraints:
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000


*/

/********************************************************************** BRUTE FORCE **************************************************************************************/

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
        if(W <= 0 || n == 0)
            return 0;
        
        int take = INT_MIN, notTake = INT_MIN;
        if(wt[n - 1] <= W)
            take = val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1);
        
        notTake = knapSack(W, wt, val, n - 1);
        
        return max(take, notTake);
        
    }
};

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n, int i) 
    { 
       // Your code here
        if(W <= 0 || i == n)
            return 0;
        
        int take = INT_MIN, notTake = INT_MIN;
        if(wt[i] <= W)
            take = val[i] + knapSack(W - wt[i], wt, val, n, i + 1);
        
        notTake = knapSack(W, wt, val, n, i + 1);
        
        return max(take, notTake);
        
    }
    
    int knapSack(int W, int wt[], int val[], int n) {
        return knapSack(W, wt, val, n, 0);
    }
};

/********************************************************************** MEMOIZATION **************************************************************************************/

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n, int i, vector<vector<int>>& dp) 
    { 
       // Your code here
        if(W <= 0 || i == n)
            return 0;
        
        if(dp[i][W] != -1)
            return dp[i][W];
            
        int take = INT_MIN, notTake = INT_MIN;
        if(wt[i] <= W)
            take = val[i] + knapSack(W - wt[i], wt, val, n, i + 1, dp);
        
        notTake = knapSack(W, wt, val, n, i + 1, dp);
        
        return dp[i][W] = max(take, notTake);
        
    }
    
    int knapSack(int W, int wt[], int val[], int n) {
        
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return knapSack(W, wt, val, n, 0, dp);
    }
};

/********************************************************************** DP **************************************************************************************/

class Solution
{
    public:
    
    
    int knapSack(int W, int wt[], int val[], int n) {
        
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= W; j++) {
                if(wt[i - 1] <= j)
                    dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        return dp[n][W];
    }
};

/********************************************************************** SPACE OPT **************************************************************************************/

class Solution
{
    public:
    
    
    int knapSack(int W, int wt[], int val[], int n) {
        
        vector<int> prev(W + 1, 0);
        
        for(int i = 1; i <= n; i++) {
            vector<int> curr(W + 1, 0);
            for(int j = 1; j <= W; j++) {
                if(wt[i - 1] <= j)
                    curr[j] = max(prev[j], val[i - 1] + prev[j - wt[i - 1]]);
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        
        return prev[W];
    }
};

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(2, vector<int>(W + 1, 0));
    
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= W; j++) {
                if(wt[i] <= j) {
                    dp[i % 2][j] = max(val[i] + dp[(i + 1)%2][j - wt[i]], dp[(i + 1)%2][j]);
                }
                else
                    dp[i % 2][j] = dp[(i + 1)%2][j];
            }
        }
        
        return dp[(n + 1) % 2][W];
    }
};
