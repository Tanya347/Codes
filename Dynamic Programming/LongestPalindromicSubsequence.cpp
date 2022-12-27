int lcs(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    return dp[m][n];
} 

int Solution::solve(string A) {
    string B = A;
    reverse(B.begin(), B.end());
    return lcs(A, B);
}

/******************************************************************* SPACE OPT *******************************************************************************/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        
        reverse(t.begin(), t.end());

        vector<int> prev(t.size() + 1, 0);

        for(int i = 1; i <= s.size(); i++) {

            vector<int> curr(t.size() + 1, 0);
            for(int j = 1; j <= t.size(); j++) {
                if(s[i - 1] == t[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }

        return prev[t.size()];
    }
};
