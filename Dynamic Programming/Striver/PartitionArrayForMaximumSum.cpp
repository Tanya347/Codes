/******************************************************************* QUESTION *******************************************************************************/

/*

Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length

*/

/******************************************************************* BRUTE FORCE *******************************************************************************/

class Solution {
public:

    int helper(vector<int>& arr, int i, int k) {
        
        if(i >= arr.size())   
            return 0;

        int maxSum = 0;
        int maxi = arr[i];

        for(int j = 0; j < k; j++) {
            if(i + j < arr.size()) {
                maxi = max(maxi, arr[i + j]);
                int sum = maxi*(j + 1) + helper(arr, i + j + 1, k);
                maxSum = max(sum, maxSum);
            }
        }

        return maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return helper(arr, 0, k);
    }
};

/******************************************************************* MEMOIZATION *******************************************************************************/

class Solution {
public:

    vector<int> dp;

    int helper(vector<int>& arr, int i, int k) {
        
        if(i >= arr.size())   
            return 0;

        int maxSum = 0;
        int maxi = arr[i];

        if(dp[i] != -1)
            return dp[i];

        for(int j = 0; j < k; j++) {
            if(i + j < arr.size()) {
                maxi = max(maxi, arr[i + j]);
                int sum = maxi*(j + 1) + helper(arr, i + j + 1, k);
                maxSum = max(sum, maxSum);
            }
        }

        return dp[i] = maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        dp.resize(arr.size(), -1);
        return helper(arr, 0, k);
    }
};

/******************************************************************* DP *******************************************************************************/

class Solution {
public:

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        dp.resize(arr.size() + 1, 0);

        for(int i = n - 1; i >= 0; i--) {
            
            int maxi = arr[i];
            int maxSum = 0;

            for(int j = 0; j < k; j++) {
                if(i + j < arr.size()) {
                    maxi = max(maxi, arr[i + j]);
                    int sum = maxi*(j + 1) + helper(arr, i + j + 1, k);
                    maxSum = max(sum, maxSum);
                }
            }

            dp[i] = maxSum;
        }

        return dp[0];
    }
};
