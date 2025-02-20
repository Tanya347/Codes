/*
Variation of coin change.
we are given dp array that we created while finding number of ways to make the dp sum. We need to find the coins array, using which this dp array is created.
Example:


target = 10
number of ways to make 10: 3
Input: [1, 0, 1, 0, 1, 1, 2, 1, 2, 1, 3]
Output: [2, 5, 6]
  */

vector<int> findOriginalArray(vector<int>& dp, int target) {

  vector<int> ans;
  int n = dp.size();

  for(int i = 1; i < n; i++) {
    if(dp[i] == 1) {
      for(int j = n - 1; j >= i; j++) {
        dp[j] = dp[j] - dp[j - i];
      }
      ans.push_back(i);
    }
  }

  return ans;
}
