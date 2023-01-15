/******************************************************************* QUESTION *******************************************************************************/

/*

You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {
public:
    
    // this function assumes that s1 is the bigger string
    bool checkPossible(string &s1, string &s2) {

        if(s1.size() != s2.size() + 1)
            return false;
        
        int i = 0, j = 0;

        // move till we don't reach the end of bigger string
        // since during the case where characters don't match we are just
        // incrementing the pointer pointing to bigger string both pointers
        // should cover the entire strings
        while(i < s1.size()) {
            if(j < s2.size() && s1[i] == s2[j]) {
                i++;
                j++;
            } else i++;
        }

        // check if we have reached the end of both the strings then only can we 
        // say s2 is predecessor or s1
        if(i == s1.size() && j == s2.size()) return true;
        return false;
    }
    
    // comparator function that helps in sorting according to size
    static bool comp(string &s1, string &s2) {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(), comp);

        int n = words.size();
        vector<int> dp(n + 1, 1);
        int maxi = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {

                // normal lis code only difference is that instead of checking for greater
                // we are calling a function that checks whether words[j] is a predecessor of
                // words[i] or not
                if(checkPossible(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }

            maxi = max(dp[i], maxi);
        }

        return maxi;
    }
};
