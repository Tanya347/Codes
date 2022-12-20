// gfg

int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        vector<vector<long long int>> dp(n + 1, vector<long long int>(sum + 1, 0));
        int mod = (int)1e9 + 7;
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= n; i++) {
            
            // we can't ignore 0 as it can also be the sum i.e. an element can be 0
            // when we are considering sum to be 0 then there are two ways possible, one is 
            // including the 0 element and other is not including it i.e keeping an empty subset
            for(int j = 0; j <= sum; j++) {
                if(arr[i - 1] <= j)
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j])%mod;
                else
                    dp[i][j] = (dp[i - 1][j])%mod;
            }
        }
        
        return dp[n][sum]%mod;
	}

/************************************************************************************************************************************************************/

int isSubSet(int arr[],int n,int sum){
    
    int dp[n+1][sum+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                dp[i][j]=1;
            }
            if(j==0){
                dp[i][j]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];

}

