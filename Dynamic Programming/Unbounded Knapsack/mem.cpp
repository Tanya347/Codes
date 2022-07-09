class Solution{
public:
    
    int knapSack_mem(int N, int W, int val[], int wt[], vector<vector<int>>& mem) {
        if(N == 0 || W <= 0) {
            return 0;
        }
        
        if(mem[N][W] != -1) {
            return mem[N][W];    
        }
        
        int ans;
        if(wt[0] > W)
            ans = knapSack_mem(N - 1, W, val + 1, wt + 1, mem);
        
        else {
            ans = max(knapSack_mem(N - 1, W, val + 1, wt + 1, mem), val[0] + knapSack_mem(N, W - wt[0], val, wt, mem));
        }
        
        mem[N][W] = ans;
        return ans;
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> mem(N + 1, vector<int>(W + 1, -1));
        return knapSack_mem(N, W, val, wt, mem);
    }
};
