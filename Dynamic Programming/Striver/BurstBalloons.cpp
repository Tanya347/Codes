/******************************************************************* QUESTION *******************************************************************************/

/*

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10
 

Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100

*/

/******************************************************************* BRUTE FORCE *******************************************************************************/

https://whimsical.com/i-1-j-4-XKJ5BDPr8AqwSwxFE2TKQq

refer to above link for detailed explanation of the approach

class Solution {
public:

    int rec(vector<int>& nums, int i, int j) {

        if(i > j) 
            return 0;
        
        int maxi = INT_MIN;

        for(int ind = i; ind <= j; ind++) {
            int coins = nums[i - 1]*nums[ind]*nums[j + 1] + rec(nums, i, ind - 1) + rec(nums, ind + 1, j);
            maxi = max(maxi, coins);
        
        }

        return maxi;
    }

    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        return rec(nums, 1, nums.size() - 2);
    }
};

/******************************************************************* MEMOISATION *******************************************************************************/

class Solution {
public:

    int rec(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {

        if(i > j) 
            return 0;
        
        int maxi = INT_MIN;
        if(dp[i][j] != -1)
            return dp[i][j];

        for(int ind = i; ind <= j; ind++) {
            int coins = nums[i - 1]*nums[ind]*nums[j + 1] + rec(nums, i, ind - 1, dp) + rec(nums, ind + 1, j, dp);
            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {

        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        // when you dry run you'll see that i and j go till n + 1 i.e. the last index
        // hence we need a dp array of size n + 2
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        return rec(nums, 1, n, dp);
    }
};

/******************************************************************* DP *******************************************************************************/

class Solution {
public:

    int maxCoins(vector<int>& nums) {

        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n - 2; i >= 1; i--) {
            for(int j = 1; j <= n - 2; j++) {

                int maxi = 0;

                for(int ind = i; ind <= j; ind++) {
                    int coins = nums[i - 1]*nums[ind]*nums[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
                    maxi = max(maxi, coins);
                }

                dp[i][j] = maxi;
            }
        }

        return dp[1][n - 2];
    }
};
