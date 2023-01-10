/******************************************************************* QUESTION *******************************************************************************/

/*

Given an integer n and array of integers, returns the Longest Increasing subsequence which is lexicographically smallest.
LIS  of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}. 
 

Example 1:

Input:
n = 16
arr = [0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15]
Output:
0 4 6 9 13 15 
Explanation:
longest Increasing subsequence is 0 4 6 9 13 15  and the length of the longest increasing subsequence is 6.
Example 2:

Input:
n = 1
arr = [1]
Output:
1
Your Task:
You don't need to read input or print anything. Your task is to complete the function longestIncreasingSubsequence() which takes integer n and array arr and returns the longest increasing subsequence.

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n)

Constraint:
1 <= n < = 1000
1 <= arr[i] <= 50000

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n, 1);
        vector<int> hash(n, 1);
        
        for(int i = 0; i < n; i++) {
            
            hash[i] = i;
            for(int j = 0; j < i; j++) {
                if(arr[j] < arr[i] && 1 + dp[j] > dp[i]) {
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
        
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        
        while(hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        
        reverse(temp.begin(), temp.end());
        
        return temp;
    }
};
