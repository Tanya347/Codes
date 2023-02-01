/******************************************************************* QUESTION *******************************************************************************/

/*

Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase English letters only.

*/

/******************************************************************* BRUTE FORCE *******************************************************************************/

class Solution {
public:

    // INTUITION
    // we need to do front partitioning i.e. suppose our string is bababcbadcede
    // we will check substrings from a particular index, suppose from i = 0
    // now b is a palindrome so we call function on ababcbadcede and add 1 to the answer
    // also bab is a palindrom so we call abcbadcede and same for babab
    // we do this till we don't reach n 
    // and we return the min of all possibilities

    bool isPalindrome(int i, int j, string s) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int helper(int i, int n, string &str) {
        if(i == n)
            return 0;
        
        int minCost = INT_MAX;

        for(int j = i; j < n; j++) {
            if(isPalindrome(i, j, str)) {
                int cost = 1 + helper(j+1, n, str);
                minCost = min(minCost, cost);
            }
        }

        return minCost;
    }

    int minCut(string s) {
        int n = s.size();

        // we need to substract 1 because the code does a partition for last element as well by calling j+1 which amounts to n which is not required
        return helper(0, n, s) - 1;
    }
};

/******************************************************************* MEMOIZATION *******************************************************************************/

class Solution {
public:

    vector<int> dp;
    vector<vector<int>> pal;

    // using memoization here as well
    int isPalindrome(int i, int j, string s) {
        
        if(i >= j)
            return 1;

        if(pal[i][j] != -1)
            return pal[i][j];

        return pal[i][j] = (s[i] == s[j]) && isPalindrome( i + 1, j - 1, s);
    }

    int helper(int i, int n, string &str) {
        if(i == n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];

        int minCost = n;

        for(int j = i; j < n; j++) {
            if(isPalindrome(i, j, str)) {
                int cost = 1 + helper(j+1, n, str);
                minCost = min(minCost, cost);
            }
        }

        return dp[i] = minCost;
    }

    int minCut(string s) {
        int n = s.size();
        dp.resize(n, -1);
        pal.resize(n, vector<int>(n, -1));
        return helper(0, n, s) - 1;
    }
};

/******************************************************************* DP *******************************************************************************/

class Solution {
public:

    int minCut(string s) {
        
        int n = s.size();
        
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {
            int minCost = INT_MAX;

            for(int j = i; j < n; j++) {

                // because of the indices, the strings tested first are of size 1 then 2 and so on
                // so we can take advantage of that and populate palindrome array
                // if the size is 1 or 2 then it is easy to find palindrome
                // if the size is greater than 2 but after excluding first and last elements
                // it is a palindrome then it is a palindrome if first & last element is same
                
                if(s[i] == s[j] && (j - i < 2 || pal[i+1][j-1])) {
                    pal[i][j] = true;
                    int cost = 1 + dp[j + 1];
                    minCost = min(cost, minCost);
                }
            }

            dp[i] = minCost;
        }

        return dp[0] - 1;
    }
};
