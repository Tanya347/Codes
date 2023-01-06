/******************************************************************* QUESTION *******************************************************************************/

/*

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.

*/

/******************************************************************* BRUTE FORCE *******************************************************************************/

class Solution {
public:
    bool isMatch(string s, string p) {
        

        // Base case

        // if both strings exhausted return true as they have matched
        if(s.empty() && p.empty())
            return true;

        // if pattern is exhausted and string is still left that means they can't match
        if(p.empty() && !s.empty())
            return false;

        // if string has exhausted and pattern is left, check if pattern is all stars as
        // they can match empty string as well
        if(s.empty() && !p.empty()) {
            for(int i = 0; i < p.size(); i++) {
                if(p[i] != '*')
                    return false;
            }
            return true;
        }

        // matching characters
        if(s[0] == p[0] || p[0] == '?')
            return isMatch(s.substr(1), p.substr(1));
        
        // if it is star then either eliminate star and see if they match or eliminate
        // one character from string and keep the star
        else if(p[0] == '*')
            return isMatch(s.substr(1), p) || isMatch(s, p.substr(1));
        
        else 
        return false;
    }
};

/******************************************************************* MEMOIZATION *******************************************************************************/

class Solution {
public:

    bool isMatch(string s, string p, int i, int j, vector<vector<int>>& dp) {

        // Base case

        // if both strings exhausted return true as they have matched
        if(i == s.size() && j == p.size())
            return true;

        // if pattern is exhausted and string is still left that means they can't match
        if(j == p.size() && i != s.size())
            return false;

        // if string has exhausted and pattern is left, check if pattern is all stars as
        // they can match empty string as well
        if(i == s.size() && j != p.size()) {
            for(int k = j; k < p.size(); k++) {
                if(p[k] != '*')
                    return false;
            }
            return true;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        // matching characters
        if(s[i] == p[j] || p[j] == '?')
            return dp[i][j] = isMatch(s, p, i + 1, j + 1, dp);
        
        // if it is star then either eliminate star and see if they match or eliminate
        // one character from string and keep the star
        else if(p[j] == '*')
            return dp[i][j] = isMatch(s, p, i, j + 1, dp) || isMatch(s, p, i + 1, j, dp);
        
        else 
            return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return isMatch(s, p, 0, 0, dp);
    }
};

/******************************************************************* DP *******************************************************************************/

class Solution {
public:

    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        
        dp[0][0] = true;

        for(int i = 1; i <= p.size(); i++) {
            bool allStars = true;
            for(int j = 1; j <= i; j++) {
                if(p[j - 1] != '*')
                    allStars = false;
            }
            dp[0][i] = allStars;
        }

        for(int i = 1; i <= s.size(); i++) {
            for(int j = 1; j <= p.size(); j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = false;
            }
        }

        return dp[s.size()][p.size()];
    }
};

/******************************************************************* SPACE OPTIMIZATION *******************************************************************************/

class Solution {
public:

    bool isMatch(string s, string p) {
        vector<bool> prev(p.size() + 1, false);
        
        prev[0] = true;

        for(int i = 1; i <= p.size(); i++) {
            bool allStars = true;
            for(int j = 1; j <= i; j++) {
                if(p[j - 1] != '*')
                    allStars = false;
            }
            prev[i] = allStars;
        }

        for(int i = 1; i <= s.size(); i++) {

            vector<bool> curr(p.size() + 1, false);

            for(int j = 1; j <= p.size(); j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    curr[j] = prev[j - 1];
                else if(p[j - 1] == '*')
                    curr[j] = prev[j] || curr[j - 1];
                else
                    curr[j] = false;
            }

            prev = curr;
        }

        return prev[p.size()];
    }
};
