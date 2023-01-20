/******************************************************************* QUESTION *******************************************************************************/

/*

Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
 

Constraints:

1 <= nums.length <= 2000
-106 <= nums[i] <= 106

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        vector<int> dp(nums.size(), 1), count(nums.size(), 1);

        int maxi = 1;

        for(int i = 1; i < nums.size(); i++) {

            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {

                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }

                    // if the sizes for different elements are coming out to be same
                    // they can give same length for LIS, hence update the count of 
                    // current element with count of LISs till that particular previous index
                    else if(dp[j] + 1 == dp[i])
                        count[i] += count[j];
                } 
            }

            maxi = max(maxi, dp[i]);
        }

        int max_count = 0;

        // increment all the counts whose last element is last element of LIS
        for(int i = 0; i < nums.size(); i++) {
            if(dp[i] == maxi)
                max_count += count[i];
        }

        return max_count;
    }
};
