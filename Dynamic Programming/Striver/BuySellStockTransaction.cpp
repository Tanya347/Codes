/******************************************************************* QUESTION *******************************************************************************/

/*

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {
public:

    int maxProfit(vector<int>& prices, int i, int buy, int fee) {
        if(i == prices.size())
            return 0;
        
        int profit = 0;
        if(buy == 0) {
            profit = max(maxProfit(prices, i + 1, 0, fee), -prices[i] + maxProfit(prices, i + 1, 1, fee));
        } 
        if(buy == 1) {
            profit = max(maxProfit(prices, i + 1, 1, fee), prices[i] + maxProfit(prices, i + 1, 0, fee) - fee);
        }

        return profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        return maxProfit(prices, 0, 0, fee);
    }
};

/******************************************************************* MEMOIZATION *******************************************************************************/

class Solution {
public:

    int maxProfit(vector<int>& prices, int i, int buy, int fee, vector<vector<int>>& dp) {
        if(i == prices.size())
            return 0;
        
        if(dp[i][buy] != -1)
            return dp[i][buy];

        if(buy == 0) {
            return dp[i][buy] = max(maxProfit(prices, i + 1, 0, fee, dp), -prices[i] + maxProfit(prices, i + 1, 1, fee, dp));
        } 
        else {
            return dp[i][buy] = max(maxProfit(prices, i + 1, 1, fee, dp), prices[i] + maxProfit(prices, i + 1, 0, fee, dp) - fee);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return maxProfit(prices, 0, 0, fee, dp);
    }
};

/******************************************************************* DP *******************************************************************************/

class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {

        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));

        for(int i = prices.size() - 1; i >= 0; i--) {
            for(int j = 0; j <= 1; j++) {
                if(j == 0)
                    dp[i][j] = max(dp[i + 1][0], -prices[i] + dp[i + 1][1]);
                else
                    dp[i][j] = max(dp[i + 1][1], prices[i] + dp[i + 1][0] - fee);
            }
        }

        return dp[0][0];
    }
};

/******************************************************************* SPACE OPT *******************************************************************************/

class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {

        vector<int> ahead(2, 0);

        for(int i = prices.size() - 1; i >= 0; i--) {

            vector<int> curr(2, 0);
            for(int j = 0; j <= 1; j++) {
                if(j == 0)
                    curr[j] = max(ahead[0], -prices[i] + ahead[1]);
                else
                    curr[j] = max(ahead[1], prices[i] + ahead[0] - fee);
            }

            ahead = curr;
        }

        return ahead[0];
    }
};
