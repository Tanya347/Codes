/******************************************************************* QUESTION *******************************************************************************/

/*

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {
public:
    int minInsertions(string s) {
        string t = s;
        
        reverse(t.begin(), t.end());

        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

        for(int i = 1; i <= s.size(); i++) {
            for(int j = 1; j <= t.size(); j++) {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return s.size() - dp[s.size()][t.size()];
    }
};

/******************************************************************* SPACE OPT *******************************************************************************/

class Solution {
public:
    int minInsertions(string s) {
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

        return s.size() - prev[t.size()];
    }
};
