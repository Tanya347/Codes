/******************************************************************* QUESTION *******************************************************************************/

/*

For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {


        // for two strings to have gcd str1 + str2 = str2 + str1
        // now if the two strings have gcd then we need to just find the gcd of their sizes
        // that will give us the size of the gcd

        return str1 + str2 == str2 + str1 ? str1.substr(0, gcd(str1.size(), str2.size())): "";
    }
};
