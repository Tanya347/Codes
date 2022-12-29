/******************************************************************* QUESTION *******************************************************************************/

/*

Given two strings s and t, return the number of distinct 
subsequences
 of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.

*/

/******************************************************************* BRUTE FORCE *******************************************************************************/

// 50/65 cases passed

class Solution {
public:
    int numDistinct(string s, string t) {

        // we have travelled entirety of t that means we must have found at least one match so return 1
        if(t.size() == 0)
            return 1;

        // we have travelled entirety of s but it can also be possible we couldn't find a match so return 0
        if(s.size() == 0)
            return 0;

        if(s[0] == t[0])
            // if the characters match then we can move ahead in both strings in one case
            // in the other case we can just move ahead in s, because might be possible that 
            // that character of t will be found further ahead
            return numDistinct(s.substr(1), t.substr(1)) + numDistinct(s.substr(1), t);
        else 
            // if characters don't match then there's no other option but to 
            // move ahead in s string
            return numDistinct(s.substr(1), t);
    }
};

/******************************************************************* MEMOISATION *******************************************************************************/

// 61/65 cases passed

class Solution {
public:
    int numDistinct(string s, string t, vector<vector<int>>& dp) {

        int mod = 1e9+7;
        int m = s.size();
        int n = t.size();

        if(n == 0)
            return 1;

        if(m == 0)
            return 0;

        if(dp[m - 1][n - 1] != -1)
            return dp[m - 1][n - 1];

        if(s[0] == t[0])
            return dp[m - 1][n - 1] = (numDistinct(s.substr(1), t.substr(1), dp) + numDistinct(s.substr(1), t, dp)) % mod;
        else 
            return dp[m - 1][n - 1] = numDistinct(s.substr(1), t, dp);
    }

    int numDistinct(string s, string t) {
        
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return numDistinct(s, t, dp);
    }
};

/******************************************************************* DP *******************************************************************************/

class Solution {
public:

    int numDistinct(string s, string t) {
        
        int mod = 1e9+7;
        int m = s.size();
        int n = t.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%mod;
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[m][n];
    }
};

/******************************************************************* SPACE OPT *******************************************************************************/

class Solution {
public:

    int numDistinct(string s, string t) {
        
        int mod = 1e9+7;
        int m = s.size();
        int n = t.size();

        vector<int> prev(n + 1, 0);
        prev[0] = 1;

        for(int i = 1; i <= m; i++) {
            vector<int> curr(n + 1, 1);
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == t[j - 1])
                    curr[j] = (prev[j - 1] + prev[j])%mod;
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }

        return prev[n];
    }
};
