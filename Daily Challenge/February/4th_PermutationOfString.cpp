/******************************************************************* QUESTION *******************************************************************************/

/*

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int m = s1.size();
        int n = s2.size();

        // bigger string cannot be contained in smaller string
        if(m > n)
            return false;

        vector<int> map1(26, 0);
        vector<int> map2(26, 0);

        // store count of characters of s1 in map1
        // store count of first m characters of s2 in map2
        for(int i = 0; i < m; i++) {
            map1[s1[i] - 'a']++;
            map2[s2[i] - 'a']++;
        }


        // we already have the count of characters in first window of m length
        // if the count matches with that of s1 then the window is a permutation
        // otherwise we will decrement the count of first character in window and
        // introduce a new character to the window, which will start from mth index
        
        if(map1 == map2) return true;

        for(int i = m; i < n; i++) {

            map2[s2[i - m] - 'a']--;
            map2[s2[i] - 'a']++;

            // this needs to be after creating a window because what if we don't get 
            // a next iteration hence beginning is not a good option 
            if(map1 == map2) return true;
        }

        return false;
    }
};

/******************************************************************* EXPLANATION *******************************************************************************/

/*

1. The first step is to find the freq of all characters of s1.

2. Then we will be starting with a window of size 1 initially in s2. That means start=0, end=0.

3. Along with this, we will also be maintaining the frequency of the characters in the current window.

4. We will be continuing the below steps untill we reach a situation where the end of the window reaches the end of s2. That means we will be doing the steps while end<length of s2.
		a) Increase the frequency of the character which is just now newly included inside the window. That means increase the frequency of s2[end].
		b) Now check if the frequency of the characters in the current window, is same as the frequency of characters int s1. But this is only possible if the length of current substring(window) is same as the length of s1. If this is true, then we can directly return true from here.
		c) If the frequency doesnt match, we have to change the window:-
					i) If the length of window in less than the length of s1, then we should increase the length of the the window by increasing the end. So end+=1.
					ii) If not, that means length of window is greater than or equal to the length of s1, so we will need to move to a new window. For that we will have to move start to the next character but before that we will have to decrease the frequency of start character from the curr window frequency. That means
							-Decrese the frequency of s2[start].
							-Move start to the next element.
							-Move end to the next element.
							
5. If the algorithm did not return true for any window, then we will reach here(out of the loop). This will mean that we did not find any such substring in s2. So return false.

*/
