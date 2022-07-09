class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        if(N == 0 || W <= 0) {
            return 0;
        }
        
        if(wt[0] > W)
            return knapSack(N - 1, W, val + 1, wt + 1);
        
        else {
            return max(knapSack(N - 1, W, val + 1, wt + 1), val[0] + knapSack(N, W - wt[0], val, wt));
        }
    }
};
