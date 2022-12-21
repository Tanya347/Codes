int subsetSum(vector<int> nums, int sum) {
        
    //normal code for subset sum
        
    int n = nums.size();
    vector<vector<int>> subs(n + 1, vector<int>(sum + 1, 0));
    
    for(int i = 0; i <= n; i++) {
        subs[i][0] = 1;
    }
    
    // Let the target arr = [0,0,1] and the target = 1.

    // The previous code will give us the answer 1 as it first takes the element arr[2] and then finds the answer by picking it. 
    // Then from the base condition, we will return 0 ( as the target will become 0 by picking 1). 
    // But for this question, the answer will be 4 with the following subsets({0,1},{0,1},{0,0,1} and {1}).
        
    // hence for such a possibility we start j from 0 not 1
        
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
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
        
    // As the array elements are positive integers including zero, we don’t want to find the case when S1 is negative or we can say 
        // that totSum is lesser than D, therefore if totSum<D, we simply return 0.
    // S1 can’t be a fraction, as all elements are integers, therefore if totSum + D is odd, we can return 0.
    
    if(sum < d || (d + sum) % 2 == 1)
        return 0;
        
    // sum(subset1) + sum(subset2) = sum(arr)
    // sum(subset1) - sum(subset2) = diff
    // from these equations we get sum(subset1) = (diff + sum)/2
    // we only need to count number of subsets with sum1 because 
    // the other subset will by default have value sum - sum1
    
    int subsetsum = (diff + sum)/2;
  
    int count = subsetSum(nums, subsetsum);
    
    return count;
}
