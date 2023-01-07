/******************************************************************* QUESTION *******************************************************************************/

/*

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104

*/

/******************************************************************* KHUD KA DIMAAG *******************************************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int profit = 0;
        int minPrice = prices[0];
        unordered_map<int, int> profits;

        for(int i = 1; i < n; i++) {
            if(prices[i] - minPrice > profit) 
                profit = prices[i] - minPrice;

            if(profit && (prices[i] < prices[i - 1])) {
                profits[profit]++;
                profit = 0;
                minPrice = prices[i];
            }
            else
                minPrice = min(prices[i], minPrice);

        }

        for(auto it: profits) {
            profit += it.first*it.second;
        }

        return profit;
    }
};

/******************************************************************* KISI AUR KA DIMAG *******************************************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int i = 0;
        int profit = 0;

        for(int j = 1; j < prices.size(); j++) {
            if(prices[j] > prices[i])
                profit += prices[j] - prices[i];

            i++;
        }

        return profit;
    }
};

/******************************************************************* RECURSION *******************************************************************************/

class Solution {
public:

    int maxProfit(vector<int>& prices, int i, int buy) {
        if(i == prices.size())
            return 0;
        
        int profit = 0;
        if(buy == 0) {
            profit = max(maxProfit(prices, i + 1, 0), -prices[i] + maxProfit(prices, i + 1, 1));
        } 
        if(buy == 1) {
            profit = max(maxProfit(prices, i + 1, 1), prices[i] + maxProfit(prices, i + 1, 0));
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        return maxProfit(prices, 0, 0);
    }
};

/******************************************************************* MEMOISATION *******************************************************************************/

class Solution {
public:

    int maxProfit(vector<int>& prices, int i, int buy, vector<vector<int>>& dp) {
        
        if(i == prices.size())
            return 0;
        
        if(dp[i][buy] != -1)
            return dp[i][buy];

        if(buy == 0) {
            dp[i][buy] = max(maxProfit(prices, i + 1, 0, dp), -prices[i] + maxProfit(prices, i + 1, 1, dp));
        } 
        if(buy == 1) {
            dp[i][buy] = max(maxProfit(prices, i + 1, 1, dp), prices[i] + maxProfit(prices, i + 1, 0, dp));
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

        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));

        for(int i = prices.size() - 1; i >= 0; i--) {
            for(int j = 0; j <= 1; j++) {
                if(j == 0)
                    dp[i][j] = max(dp[i + 1][0], -prices[i] + dp[i + 1][1]);
                else
                    dp[i][j] = max(dp[i + 1][1], prices[i] + dp[i + 1][0]);
            }
        }

        return dp[0][0];
    }
};

/******************************************************************* SPACE OPT *******************************************************************************/

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        vector<int> ahead(2, 0);

        for(int i = prices.size() - 1; i >= 0; i--) {

            vector<int> curr(2, 0);
            for(int j = 0; j <= 1; j++) {
                if(j == 0)
                    curr[j] = max(ahead[0], -prices[i] + ahead[1]);
                else
                    curr[j] = max(ahead[1], prices[i] + ahead[0]);
            }

            ahead = curr;
        }

        return ahead[0];
    }
};
