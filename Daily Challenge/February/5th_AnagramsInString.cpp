/******************************************************************* QUESTION *******************************************************************************/

/*

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int m = s.size(), n = p.size();

        if(n > m) return {};

        vector<int> ans;
        vector<int> map1(26, 0);
        vector<int> map2(26, 0);

        for(int i = 0; i < n; i++) {
            map1[p[i] - 'a']++;
            map2[s[i] - 'a']++;
        }

        // index of first window is 0
        if(map1 == map2) ans.push_back(0);

        for(int i = n; i < m; i++) {

            map2[s[i - n] - 'a']--;
            map2[s[i] - 'a']++;

            // here when we look at the window i stands for the last element
            // if we subtract window size n then we reach the index before the window starts
            // hence we also add 1
            if(map1 == map2) ans.push_back(i - n + 1);
        }

        return ans;
    }
};
