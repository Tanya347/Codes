class Solution {
public:
    
    int subsetSum(vector<int> nums, int sum) {
        
        //normal code for subset sum
        
        int n = nums.size();
        vector<vector<int>> subs(n + 1, vector<int>(sum + 1, 0));

        for(int i = 0; i <= n; i++) {
            subs[i][0] = 1;
        }
      
        //j starts from 0, becuase 0s are considered valid in this problem, e.g - nums: [0,0,0,0], target: 0, ans = 16

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
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        
        int subsetsum = (sum + target)/2;
        
        //For below if condition, 

	      //sum<abs(target), consider test case - nums: [100], target: -200

	      //(target+sum) % 2 != 0, consider test case - nums: [7,9,3,8,0,2,4,8,3,9], its sum = 53 and target: 0, there could not be any 26.5 in integer array.

        if((target + sum) % 2 != 0 || abs(target) > sum )
            return 0;
    
        return subsetSum(nums, subsetsum);
    }
};
