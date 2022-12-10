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
