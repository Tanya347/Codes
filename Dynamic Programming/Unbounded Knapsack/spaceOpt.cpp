class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int> prev(W + 1, 0);
        
        for(int i = 1; i <= N; i++) {
            vector<int> curr(W + 1, 0);
            for(int j = 1; j <= W; j++) {
                if(wt[i - 1] <= j) {
                    curr[j] = max(prev[j], val[i - 1] + curr[j - wt[i - 1]]);
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        
        return prev[W];
    }
};
