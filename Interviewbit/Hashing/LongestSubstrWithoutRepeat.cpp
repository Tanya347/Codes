
/*

Given a string, 

find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.

*/



int Solution::lengthOfLongestSubstring(string A) {
    unordered_map<char, int> mp;
    int n = A.length();
    int ans = 1, length = 0;
    
    for(int i = 0; i < A.length(); i++) {
        
        if(mp.find(A[i]) != mp.end() && mp[A[i]] >= length) {
            ans = max(ans, i - length);
            length = mp[A[i]] + 1;
        }
        
        mp[A[i]] = i;
    }
    
    ans = max(ans, n - length);
    return ans;
}
