class Solution {
public:

    int coinChange(vector<int>& coins, int amount, int i) {
        if(amount <= 0 || i >= coins.size())
            return (amount == 0) ? 0 : INT_MAX - 1;
        
        int ans = -1;
        if(coins[i] <= amount)
            ans = min(coinChange(coins, amount, i + 1), 1 + coinChange(coins, amount - coins[i], i));
        
        else
            ans = coinChange(coins, amount, i + 1);

        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        
        int ans = coinChange(coins, amount, 0);
        return ans == INT_MAX - 1 ? -1 : ans;
    }
};
