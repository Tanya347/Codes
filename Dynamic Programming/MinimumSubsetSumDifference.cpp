vector<vector<bool>> subsetSum(vector<int> nums, int sum) {
        
    //normal code for subset sum
        
    int n = nums.size();
    vector<vector<bool>> subs(n + 1, vector<bool>(sum + 1));
    
    for(int i = 0; i <= n; i++) {
        subs[i][0] = true;
    }
        
    for(int j = 1; j <= sum; j++) {
        subs[0][j] = false;
    }
        
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(nums[i - 1] <= j) {
                subs[i][j] = subs[i - 1][j] || subs[i - 1][j - nums[i - 1]];
            } else {
                subs[i][j] = subs[i - 1][j];
            }
        }
    }
            
    return subs;
}

int Solution::solve(vector<int> &nums) {
    
    //  calculate sum of entire array
    int sum = 0;
        
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    // cout<<sum<<endl;
        
    //  fetch the subsets that form sum lesser than half of actual sum
    vector<vector<bool>> subsetsum = subsetSum(nums, (sum + 1)/2);
        
    //  store all those sums that have a subset in the array
    vector<int> sums;
    for(int i = 0; i < subsetsum[nums.size()].size(); i++) {
        if(subsetsum[nums.size()][i]) {
            sums.push_back(i);
        }
    }
    
        
    //  find the min difference, we extract smaller sum from sums array
    //  and by default the larger array will be sum - si. Hence,
    //  difference = sum - si - si = sum - 2*si
    int mn = INT_MAX;
    for(int i = 0; i < sums.size(); i++) {
        // cout<<mn<<" ";
        mn = min(mn, abs(sum - 2*sums[i]));
    }
        // cout<<endl;
    return mn;
}
