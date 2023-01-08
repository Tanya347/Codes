/******************************************************************* QUESTION *******************************************************************************/

/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000

*/

/******************************************************************* BRUTE FORCE *******************************************************************************/

class Solution {
public:

    int maxProfit(vector<int>& prices, int i, int buy) {
        if(i >= prices.size())
            return 0;
        
        int profit = 0;
        if(buy == 0) {
            profit = max(maxProfit(prices, i + 1, 0), -prices[i] + maxProfit(prices, i + 1, 1));
        } 
        if(buy == 1) {
            profit = max(maxProfit(prices, i + 1, 1), prices[i] + maxProfit(prices, i + 2, 0));
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        return maxProfit(prices, 0, 0);
    }
};

/******************************************************************* MEMOIZATION *******************************************************************************/

class Solution {
public:

    int maxProfit(vector<int>& prices, int i, int buy, vector<vector<int>>& dp) {
        
        if(i >= prices.size())
            return 0;
        
        if(dp[i][buy] != -1)
            return dp[i][buy];

        if(buy == 0) {
            dp[i][buy] = max(maxProfit(prices, i + 1, 0, dp), -prices[i] + maxProfit(prices, i + 1, 1, dp));
        } 
        if(buy == 1) {
            dp[i][buy] = max(maxProfit(prices, i + 1, 1, dp), prices[i] + maxProfit(prices, i + 2, 0, dp));
        }

        return dp[i][buy];
    }

    int maxProfit(vector<int>& prices) {

        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return maxProfit(prices, 0, 0, dp);
    }
};

/******************************************************************* DP *******************************************************************************/

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        vector<vector<int>> dp(prices.size() + 2, vector<int>(2, 0));

        for(int i = prices.size() - 1; i >= 0; i--) {
            for(int j = 0; j <= 1; j++) {
                if(j == 0)
                    dp[i][j] = max(dp[i + 1][0], -prices[i] + dp[i + 1][1]);
                else
                    dp[i][j] = max(dp[i + 1][1], prices[i] + dp[i + 2][0]);
            }
        }

        return dp[0][0];
    }
};

/******************************************************************* SPACE OPT *******************************************************************************/

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        vector<int> ahead1(2, 0);
        vector<int> ahead2(2, 0);
        vector<int> curr(2, 0);

        for(int i = prices.size() - 1; i >= 0; i--) {

            for(int j = 0; j <= 1; j++) {
                if(j == 0)
                    curr[j] = max(ahead1[0], -prices[i] + ahead1[1]);
                else
                    curr[j] = max(ahead1[1], prices[i] + ahead2[0]);
            }
            
            ahead2 = ahead1;
            ahead1 = curr;
        }

        return curr[0];
    }
};
