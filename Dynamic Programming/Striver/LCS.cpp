/********************************************************************** QUESTION **************************************************************************************/

/*

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

 

Constraints:

    1 <= text1.length, text2.length <= 1000
    text1 and text2 consist of only lowercase English characters.


*/

/********************************************************************** BRUTE FORCE **************************************************************************************/

class Solution {
public:

    int lcs(string text1, string text2, int m, int n) {
        if(m < 0 || n < 0)
            return 0;
        
        if(text1[m] == text2[n])
            return 1 + lcs(text1, text2, m - 1, n - 1);
        else
            return max(lcs(text1, text2, m - 1, n), lcs(text1, text2, m, n - 1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        return lcs(text1, text2, text1.size() - 1, text2.size() - 1);
    }
};

class Solution {
public:

    int lcs(string text1, string text2, int i, int j) {
        if(i == text1.length() || j == text2.length())
            return 0;

        if(text1[i] == text2[j])
            return 1 + lcs(text1, text2, i + 1, j + 1);
        
        else
            return max(lcs(text1, text2, i, j + 1), lcs(text1, text2, i + 1, j));
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        return lcs(text1, text2, 0, 0);
    }
};

/********************************************************************** MEM **************************************************************************************/

class Solution {
public:

    int lcs(string text1, string text2, int m, int n, vector<vector<int>>& dp) {
        if(m < 0 || n < 0)
            return 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];

        if(text1[m] == text2[n])
            return dp[m][n] = 1 + lcs(text1, text2, m - 1, n - 1, dp);
        else
            return dp[m][n] = max(lcs(text1, text2, m - 1, n, dp), lcs(text1, text2, m, n - 1, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return lcs(text1, text2, text1.size() - 1, text2.size() - 1, dp);
    }
};

class Solution {
public:

    int lcs(string text1, string text2, int i, int j, vector<vector<int>>& dp) {
        if(i == text1.length() || j == text2.length())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(text1[i] == text2[j])
            return dp[i][j] = 1 + lcs(text1, text2, i + 1, j + 1, dp);
        
        else
            return dp[i][j] = max(lcs(text1, text2, i, j + 1, dp), lcs(text1, text2, i + 1, j, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return lcs(text1, text2, 0, 0, dp);
    }
};

/********************************************************************** DP **************************************************************************************/

class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        
        for(int i = text1.size() - 1; i >= 0; i--) {
            
            for(int j = text2.size() - 1; j >= 0; j--) {
                if(text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else {
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        return dp[0][0];
    }
};

class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        
        for(int i = 1; i <= text1.size(); i++) {
            for(int j = 1; j <= text2.size(); j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }
};

/********************************************************************** SPACE OPT **************************************************************************************/

class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        
        vector<int> prev(text2.size() + 1, 0);
        
        for(int i = text1.size() - 1; i >= 0; i--) {
            
            vector<int> curr(text2.size() + 1, 0);
            
            for(int j = text2.size() - 1; j >= 0; j--) {
                if(text1[i] == text2[j]) {
                    curr[j] = 1 + prev[j + 1];
                }
                else {
                    curr[j] = max(curr[j + 1], prev[j]);
                }
            }
            prev = curr;
        }

        return prev[0];
    }
};

class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        
        vector<int> prev(text2.size() + 1, 0);
        
        for(int i = 1; i <= text1.size(); i++) {
            vector<int> curr(text2.size() + 1, 0);
            for(int j = 1; j <= text2.size(); j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                }
                else {
                    curr[j] = max(curr[j - 1], prev[j]);
                }
            }
            prev = curr;
        }

        return prev[text2.size()];
    }
};
