/********************************************************************** QUESTION **************************************************************************************/

/*

Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Example 1:

Input: str1 = "heap", str2 = "pea"
Output: 3
Explanation: 2 deletions and 1 insertion
p and h deleted from heap. Then, p is 
inserted at the beginning One thing to 
note, though p was required yet it was 
removed/deleted first from its position 
and then it is inserted to some other 
position. Thus, p contributes one to the 
deletion_count and one to the 
insertion_count.

Example 2:

Input : str1 = "geeksforgeeks"
str2 = "geeks"
Output: 8
Explanation: 8 deletions

 

Your Task:
You don't need to read or print anything. Your task is to complete the function minOperations() which takes both strings as input parameter and returns the minimum number of operation required.

Expected Time Complexity: O(|str1|*|str2|)
Expected Space Complexity: O(|str1|*|str2|)

Constraints:
1 ≤ |str1|, |str2| ≤ 1000
All the characters are lower case English alphabets

*/

/********************************************************************** ANSWER **************************************************************************************/

// first we find the common characters using lcs
// then we delete the uncommon characters from first string
// and insert all the characters of s2 not present in s1
// this basically means we are performing as many operations as there are uncommon characters in both the strings
// then we need to subtract twice of lcs from size of both the strings

int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
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
        
        return (m - dp[m][n]) + (n - dp[m][n]); 
	} 

/******************************************************************* QUESTION *******************************************************************************/

/*

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.

*/

/******************************************************************* ANSWER *******************************************************************************/

// This question is similar to be above one so one of the approach is same but it can also be done in a different way

