/********************************************************************** QUESTION **************************************************************************************/

/*

Problem Description

Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings.

You need to return the length of such longest common subsequence.



Problem Constraints

1 <= |A|, |B| <= 1005


Input Format

First argument is an string A.

Second argument is an string B.



Output Format

Return the length of such longest common subsequence between string A and string B.


Example Input

Input 1:

 A = "abbcdgf"
 B = "bbadcgf"



Example Output

Output 1:

 5



Example Explanation

Explanation 1:

 The longest common subsequence is "bbcgf", which has a length of 5


*/

/********************************************************************** BRUTE FORCE ************************************************************************************/

// ONE METHOD
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.length() == 0 || text2.length() == 0)
            return 0;
        
        if(text1[0] == text2[0])
            return 1 + longestCommonSubsequence(text1.substr(1), text2.substr(1));
        
        else {
            return max(longestCommonSubsequence(text1.substr(1), text2), longestCommonSubsequence(text1, text2.substr(1)));
        }
        
    }
};

// ANOTHER METHOD
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2, int m, int n) {
        if(m == 0 || n == 0)
            return 0;
        
        if(text1[m - 1] == text2[n - 1])
            return 1 + longestCommonSubsequence(text1, text2, m - 1, n - 1);
        
        else {
            return max(longestCommonSubsequence(text1, text2, m - 1, n), longestCommonSubsequence(text1, text2, m, n - 1));
        }
        
    }
};

/********************************************************************** MEMOIZATION ************************************************************************************/

//ONE METHOD
class Solution {
public:
    int lcs_helper(string text1, string text2, vector<vector<int>>& dp, int i, int j) {
        if(text1.length() == 0 || text2.length() == 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(text1[0] == text2[0])
            dp[i][j] = 1 + lcs_helper(text1.substr(1), text2.substr(1), dp, i + 1, j + 1);
        
        else {
            int a = lcs_helper(text1.substr(1), text2, dp, i + 1, j);
            int b = lcs_helper(text1, text2.substr(1), dp, i, j + 1);
            
            dp[i][j] = max(a, b);
        }
        
        return dp[i][j];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return lcs_helper(text1, text2, dp, 0, 0);
    }
};

// ANOTHER METHOD
int helper(string &A, string &B, vector<vector<int>>& mem, int m, int n) {
    
    if(m == 0 || n == 0)
        return 0;
        
    if(mem[m][n] != -1)
        return mem[m][n];
        
    if(A[m - 1] == B[n - 1])
        mem[m][n] = 1 + helper(A, B, mem, m - 1, n - 1);
    
    else
        mem[m][n] = max(helper(A, B, mem, m - 1, n), helper(A, B, mem, m, n - 1));
    
    return mem[m][n];
}

int Solution::solve(string A, string B) {
    vector<vector<int>> mem(A.length() + 1, vector<int>(B.length() + 1, -1));
    return helper(A, B, mem, A.length(), B.length());
}

/********************************************************************** DP ************************************************************************************/

int Solution::solve(string A, string B) {
    
    int m = A.length();
    int n = B.length();
    vector<vector<int>> dp(A.length() + 1, vector<int>(B.length() + 1, 0));
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(A[i - 1] == B[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    return dp[m][n];
}
