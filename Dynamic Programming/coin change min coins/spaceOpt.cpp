class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> prev(amount + 1, 0);

        for(int i = 1; i <= amount; i++) 
            prev[i] = INT_MAX - 1;

        for(int i = 1; i <= coins.size(); i++) {
            vector<int> curr(amount + 1, 0);
            for(int j = 1; j <= amount; j++) {
                if(coins[i - 1] <= j)
                    curr[j] = min(prev[j], 1 + curr[j - coins[i - 1]]);
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }

        return (prev[amount] == INT_MAX - 1)? -1 : prev[amount];
    }
};
