/******************************************************************* QUESTION *******************************************************************************/

/*

Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

*/

/******************************************************************* BRUTE FORCE *******************************************************************************/

class Solution {
public:

    int LIS(vector<int>& nums, int i, int prev_index) {

        if(i == nums.size())
            return 0;

        int notake = LIS(nums, i + 1, prev_index);
        int take = INT_MIN;
        if(prev_index == -1 || nums[i] > nums[prev_index])
            take = 1 + LIS(nums, i + 1, i);
        
        return max(take, notake);
    }

    int lengthOfLIS(vector<int>& nums) {
        return LIS(nums, 0, -1);
    }
};

/******************************************************************* MEMOIZATION *******************************************************************************/

class Solution {
public:

    int LIS(vector<int>& nums, int i, int prev_index, vector<vector<int>>& dp) {

        if(i == nums.size())
            return 0;

        if(dp[i][prev_index+1]!=-1)
            return dp[i][prev_index+1];

        int notake = LIS(nums, i + 1, prev_index, dp);
        int take = INT_MIN;
        if(prev_index == -1 || nums[i] > nums[prev_index])
            take = 1 + LIS(nums, i + 1, i, dp);
        
        return dp[i][prev_index+1] = max(take, notake);
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return LIS(nums, 0, -1, dp);
    }
};

/******************************************************************* DP *******************************************************************************/

class Solution {
public:
 
    int lengthOfLIS(vector<int>& arr) {

        int n = arr.size();
        vector<vector<int>> dp(n + 1,vector<int>(n + 1,0));
    
        for(int ind = n - 1; ind >= 0; ind--){
            for (int prev_index = ind - 1; prev_index >= -1; prev_index--){
                
                int notTake = 0 + dp[ind + 1][prev_index + 1];
        
                int take = 0;
        
                if(prev_index == -1 || arr[ind] > arr[prev_index]){
                    
                    take = 1 + dp[ind + 1][ind + 1];
                }
        
                dp[ind][prev_index + 1] = max(notTake,take);
                
            }
        }
        
        return dp[0][0];
    }
};

/******************************************************************* SPACE OPT *******************************************************************************/

class Solution {
public:

    int lengthOfLIS(vector<int>& arr) {

        int n = arr.size();
        vector<int> ahead(n + 1,0);
    
        for(int ind = n - 1; ind >= 0; ind--){

            vector<int> curr(n + 1, 0);            

            for (int prev_index = ind - 1; prev_index >= -1; prev_index--){
                
                int notTake = 0 + ahead[prev_index + 1];
        
                int take = 0;
        
                if(prev_index == -1 || arr[ind] > arr[prev_index]){
                    
                    take = 1 + ahead[ind + 1];
                }
        
                curr[prev_index + 1] = max(notTake,take);
                
            }

            ahead = curr;
        }
        
        return ahead[0];
    }
};

/******************************************************************* LOOP *******************************************************************************/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> dp(nums.size(), 1);
        
        int ans = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            int max_ans = 1;
            for(int j = i - 1; j >= 0; j--) {
                int l = 1;
                if(nums[i] > nums[j])
                    max_ans = max(max_ans, dp[j] + 1);
            }
            dp[i] = max_ans;
            ans = max(max_ans, ans);
        }
        
        return ans;
    }
};

/******************************************************************* BINARY SEARCH *******************************************************************************/

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
       // your code here
       vector<int> temp;
       temp.push_back(arr[0]);
       int len = 1;
       
       for(int i = 1; i < n; i++) {
           if(arr[i] > temp.back()) {
              temp.push_back(arr[i]);
              len++;
           }
           else {
              int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
              temp[ind] = arr[i];
           }
       }
       
       return len;
    }
};
