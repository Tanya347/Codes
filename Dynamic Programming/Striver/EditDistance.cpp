/******************************************************************* QUESTION *******************************************************************************/

/*

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.

*/

/******************************************************************* BRUTE FORCE *******************************************************************************/

class Solution {
public:
    int minDistance(string s1, string s2) {
        
      // if we reach the end of any of the strings then we return the length of the other cause that is the number of operations we'll
      // have to perform to match the strings
        if(s1.size() == 0 || s2.size() == 0) {
            return max(s1.size(), s2.size());
        }
        
      // if characters match then just move onto next index in both the strings
        if (s1[0] == s2[0]) {
            return minDistance(s1.substr(1), s2.substr(1)); 
        }
      
      // if characters don't match we can do three things
      // either we insert an element in s2 to match the one in s1 and move onto next character in s1
      // or we delete an element in s2 and move onto next index in s2
      // or we replace either one of the strings and move onto next indices in both of them
        return 1 + min(minDistance(s1.substr(1), s2), min(minDistance(s1, s2.substr(1)), minDistance(s1.substr(1), s2.substr(1))));
    }
};

/******************************************************************* MEMOIZATION *******************************************************************************/

class Solution {
public:
    int minDistance(string s1, string s2, vector<vector<int>>& dp, int i, int j) {
        
        if(s1.size() == 0 || s2.size() == 0) {
            return max(s1.size(), s2.size());
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if (s1[0] == s2[0]) 
            dp[i][j] = minDistance(s1.substr(1), s2.substr(1), dp, i + 1, j + 1); 
        
        else {
            int x = 1 + minDistance(s1.substr(1), s2, dp, i + 1, j);
            int y = 1 + minDistance(s1,s2.substr(1), dp, i, j + 1);
            int z = 1 + minDistance(s1.substr(1), s2.substr(1), dp, i + 1, j + 1);
        
            dp[i][j] = min(x , min(y , z));
        }
        
        return dp[i][j];
    }
    
    int minDistance(string s1, string s2) {
        
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        
        return minDistance(s1, s2, dp, 0, 0);
    }
};

/******************************************************************* DP *******************************************************************************/

class Solution {
public:
    int minDistance(string s1, string s2) {
        
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> output(m + 1, vector<int>(n + 1));
    
        for(int i = 0; i <= m; i++) {

            for(int j = 0; j <= n; j++) {
                
                if(i == 0)
                    output[i][j] = j;
                
                else if(j == 0)
                    output[i][j] = i;
                
                else {
                    if(s1[m - i] == s2[n - j])
                        output[i][j] = output[i - 1][j - 1];
                    
                    else
                    output[i][j] = 1 + min(min(output[i-1][j], output[i][j-1]), output[i-1][j-1]);
                }
            }
        }
        
        return output[m][n];
    }
};

/******************************************************************* SPACE OPT *******************************************************************************/

class Solution {
public:
    int minDistance(string s1, string s2) {
        
        int m = s1.size();
        int n = s2.size();

        if(m == 0 || n == 0)
            return max(m, n);

        vector<int> prev(n + 1, 0);
    
        for(int i = 0; i <= m; i++) {
            vector<int> curr(n + 1, 0);

            for(int j = 0; j <= n; j++) {
                
                if(i == 0)
                    prev[j] = j;
                
                if(j == 0)
                    curr[0] = i;
                
                else {
                    if(s1[m - i] == s2[n - j])
                        curr[j] = prev[j - 1];
                    
                    else
                    curr[j] = 1 + min(min(prev[j], curr[j-1]), prev[j-1]);
                }
            }

            prev = curr;
        }
        
        return prev[n];
    }
};
