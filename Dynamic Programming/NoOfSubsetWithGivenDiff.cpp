int subsetSum(vector<int> nums, int sum) {
        
    //normal code for subset sum
        
    int n = nums.size();
    vector<vector<int>> subs(n + 1, vector<int>(sum + 1, 0));
    
    for(int i = 0; i <= n; i++) {
        subs[i][0] = 1;
    }
        
        
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(nums[i - 1] <= j) {
                subs[i][j] = subs[i - 1][j] + subs[i - 1][j - nums[i - 1]];
            } else {
                subs[i][j] = subs[i - 1][j];
            }
        }
    }
            
    return subs[n][sum];
}

int countSubset(vector<int> &nums, int diff) {
    
    //  calculate sum of entire array
    int sum = 0;
        
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
        
    // sum(subset1) + sum(subset2) = sum(arr)
    // sum(subset1) - sum(subset2) = diff
    // from these equations we get sum(subset1) = (diff + sum)/2
    // we only need to count number of subsets with sum1 because 
    // the other subset will by default have value sum - sum1
    
    int subsetsum = (diff + sum)/2;
  
    int count = subsetSum(nums, subsetsum);
    
    return count;
}
