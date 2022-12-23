/********************************************************************** QUESTION **************************************************************************************/

/*

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:

Input: amount = 10, coins = [10]
Output: 1

 

Constraints:

    1 <= coins.length <= 300
    1 <= coins[i] <= 5000
    All the values of coins are unique.
    0 <= amount <= 5000


*/

/********************************************************************** EXPLANATION **************************************************************************************/

this question is similar to subset sum but only difference is we have to include same elemeent as many times so just one line changes rest remains same

/********************************************************************** ANSWER **************************************************************************************/

class Solution {
public:

    int change(int amount, vector<int>& coins, int i) {
        if(i == coins.size())
            return 0;
        
        if(amount == 0)
            return 1;
        
        if(coins[i] > amount)
            return change(amount, coins, i + 1);
        
        else 
            return change(amount, coins, i + 1) + change(amount - coins[i], coins, i);
    }

    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        return change(amount, coins, 0);
    }
};

// 14 / 28 test cases passed

/********************************************************************** MEMOIZATION **************************************************************************************/

class Solution {
public:

    int change(int amount, vector<int>& coins, int i, vector<vector<int>>& dp) {
        if(i == coins.size())
            return 0;
        
        if(amount == 0)
            return 1;
        
        if(dp[i][amount] != -1)
            return dp[i][amount];

        if(coins[i] > amount)
            return dp[i][amount] = change(amount, coins, i + 1, dp);
        
        else 
            return dp[i][amount] = change(amount, coins, i + 1, dp) + change(amount - coins[i], coins, i, dp);
    }

    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;

        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return change(amount, coins, 0, dp);
    }
};

/********************************************************************** DP **************************************************************************************/

class Solution {
public:

    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;

        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        
        for(int i = 0; i < coins.size() + 1; i++)
            dp[i][0] = 1;

        for(int i = 1; i < coins.size() + 1; i++) {
            for(int j = 1; j < amount + 1; j++) {
                if(coins[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[coins.size()][amount];
    }
};

/********************************************************************** SPACE OPT **************************************************************************************/

class Solution {
public:

    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;

        vector<int> prev(amount + 1, 0);
        
        prev[0] = 1;

        for(int i = 1; i < coins.size() + 1; i++) {
            vector<int> curr(amount + 1, 1);
            
            for(int j = 1; j < amount + 1; j++) {
                if(coins[i - 1] <= j)
                    curr[j] = prev[j] + curr[j - coins[i - 1]];
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }

        return prev[amount];
    }
};
