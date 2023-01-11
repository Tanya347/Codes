/******************************************************************* QUESTION *******************************************************************************/

/*

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n, 1);

        for(int i = 0; i < n; i++) {
            
            hash[i] = i;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
        }

        int ans = -1;
        int lastIndex = -1;

        for(int i = 0; i < n; i++) {
            if(dp[i] > ans) {
                ans = dp[i];
                lastIndex = i;
            }
        }

        vector<int> subset;
        subset.push_back(nums[lastIndex]);

        while(hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            subset.push_back(nums[lastIndex]);
        }

        reverse(subset.begin(), subset.end());
        return subset;
    }
};
