class Solution {
public:

    int coinChange(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {
        if(amount <= 0 || i >= coins.size())
            return (amount == 0) ? 0 : INT_MAX - 1;
        
        if(dp[i][amount] != -1)
            return dp[i][amount];

        int ans = -1;
        if(coins[i] <= amount)
            ans = min(coinChange(coins, amount, i + 1, dp), 1 + coinChange(coins, amount - coins[i], i, dp));
        
        else
            ans = coinChange(coins, amount, i + 1, dp);

        return dp[i][amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int ans = coinChange(coins, amount, 0, dp);

        return ans == INT_MAX - 1 ? -1 : ans;
    }
};
