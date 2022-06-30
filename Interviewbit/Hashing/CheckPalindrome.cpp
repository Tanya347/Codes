/********************************************************************** QUESTION **************************************************************************************/

/*

Given a string A consisting of lowercase characters.

Check if characters of the given string can be rearranged to form a palindrome.

Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.

Example Input

Input 1:

 A = "abcde"

Input 2:

 A = "abbaee"


Example Output

Output 1:

 0

Output 2:

 1


*/

/********************************************************************** SOLUTION **************************************************************************************/

int Solution::solve(string A) {
    unordered_map<int, int> freq;
    for(int i = 0; i < A.length(); i++) {
        freq[A[i]]++;
    }
    
    int odd_count = 0;
    for(auto it: freq) {
        if(it.second % 2 != 0)
            odd_count++;
    }
    
    //if there is one character with odd number then only can string form a palindrome
    if(odd_count <= 1)
        return 1;
    else 
        return 0;
}
