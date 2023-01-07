/******************************************************************* QUESTION *******************************************************************************/

/*

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000

*/

/******************************************************************* BRUTE FORCE *******************************************************************************/

class Solution {
public:

    int maxProfit(vector<int>& prices, int buy, int cap, int i) {

        int n = prices.size();
        if(i == n || cap == 0)
            return 0;
        
        if(buy == 0)
            return max(maxProfit(prices, 0, cap, i + 1), -prices[i] + maxProfit(prices, 1, cap, i + 1));
        else
            return max(maxProfit(prices, 1, cap, i + 1), prices[i] + maxProfit(prices, 0, cap - 1, i + 1));
        
    }

    int maxProfit(int k, vector<int>& prices) {
        return maxProfit(prices, 0, k, 0);
    }
};

/******************************************************************* MEMOIZATION *******************************************************************************/

class Solution {
public:

    int maxProfit(vector<int>& prices, int buy, int cap, int i, vector<vector<vector<int>>>& dp) {

        int n = prices.size();
        
        if(i == n || cap == 0)
            return 0;
        
        if(dp[i][buy][cap] != -1)
            return dp[i][buy][cap];
        
        if(buy == 0)
            return dp[i][buy][cap] = max(maxProfit(prices, 0, cap, i + 1, dp), -prices[i] + maxProfit(prices, 1, cap, i + 1, dp));
        else
            return dp[i][buy][cap] = max(maxProfit(prices, 1, cap, i + 1, dp), prices[i] + maxProfit(prices, 0, cap - 1, i + 1, dp));
        
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return maxProfit(prices, 0, k, 0, dp);
    }
};

/******************************************************************* DP *******************************************************************************/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        
        for(int i =  prices.size() - 1; i >= 0; i--) {
            for(int j = 0; j <= 1; j++) {
                for(int l = 1; l <= k; l++) {
                    if(j == 0)
                        dp[i][j][l] = max(dp[i + 1][j][l], -prices[i] + dp[i + 1][1][l]);
                    else
                        dp[i][j][l] = max(dp[i + 1][j][l], prices[i] + dp[i + 1][0][l - 1]);
                }
            }
        }
        
        return dp[0][0][k];
    }
};

/******************************************************************* SPACE OPT *******************************************************************************/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
        
        for(int i =  prices.size() - 1; i >= 0; i--) {

            vector<vector<int>> curr(2, vector<int>(k + 1, 0));

            for(int j = 0; j <= 1; j++) {
                for(int l = 1; l <= k; l++) {
                    if(j == 0)
                        curr[j][l] = max(ahead[j][l], -prices[i] + ahead[1][l]);
                    else
                        curr[j][l] = max(ahead[j][l], prices[i] + ahead[0][l - 1]);
                }
            }

            ahead = curr;
        }
        
        return ahead[0][k];
    }
};
