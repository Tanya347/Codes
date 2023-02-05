/******************************************************************* QUESTION *******************************************************************************/

/*

In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        int n = words.size();
        unordered_map<char, int> alphabet;

        for(int i = 0; i < order.size(); i++) {
            alphabet[order[i]] = i + 1;
        }

        for(int i = 0; i < n - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            int j = 0, k = 0;

            while(j < word1.length() && k < word2.length()) {
                if(alphabet[word1[j]] > alphabet[word2[k]])
                    return false;
                else if(alphabet[word1[j]] < alphabet[word2[k]])
                    break;
                else {
                    j++;
                    k++;
                }
            }

            // empty before char
            if(j < word1.length() && k == word2.length())
                return false;
            
        }

        return true;
    }
};
