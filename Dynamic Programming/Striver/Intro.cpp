/********************************************************************** FIBONACCI **************************************************************************************/

/*



*/

/********************************************************************** ANSWER **************************************************************************************/

class Solution {
  public:
  int m = 1e9+7;
    long long int topDown(int n) {
        vector<long long int> mem(n + 1, -1);
        
        if(n <= 1) {
            mem[n] = n;
            return mem[n];
        }
        
        if(mem[n] != -1)
            return mem[n] % m;
            
        mem[n] = (topDown(n - 1) + topDown(n - 2))%m; 
        return mem[n] % m;
    }
    long long int bottomUp(int n) {
        vector<long long int> dp(n + 1, 0);
        
        dp[1] = 1;
        for(int i = 2; i < n + 1; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2])%m;
        }
        
        return dp[n]%m;
    }
};

/********************************************************************** QUESTION **************************************************************************************/

/*

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:

    1 <= n <= 45

*/

/********************************************************************** BRUTE FORCE **************************************************************************************/

// 31/45 test cases passed

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

/********************************************************************** MEMOIZATION **************************************************************************************/

// 34.56 speed 29.54 memory

class Solution {
public:
    
    int climbStairs_mem(int n, int* dp) {
        if(n <= 2) {
            dp[n] = n;
            return dp[n];
        }
        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = climbStairs_mem(n - 1, dp) + climbStairs_mem(n - 2, dp);
        return dp[n];
    }
    
    int climbStairs(int n) {
        int *dp = new int[n + 1];
        for(int i = 0; i < n + 1; i++) {
            dp[i] = -1;
        }
        return climbStairs_mem(n, dp);
    }


};

/********************************************************************** DP **************************************************************************************/

// Speed 34.56% Memory 15.2%

class Solution {
public:
    
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);

        if(n <= 2)
            return n;
        
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i < n + 1; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

