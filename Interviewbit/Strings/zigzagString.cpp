/********************************************************************** QUESTION **************************************************************************************/

/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R

And then read line by line: PAHNAPLSIIGYIR

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"

**Example 2 : **

ABCD, 2 can be written as

A....C
...B....D

and hence the answer would be ACBD.

*/

/********************************************************************** ANSWER **************************************************************************************/


string Solution::convert(string s, int r) {
    if(r == 1 || s.size() == 1)
        return s;
    
    if(s.size() == 0)
        return "";
        
    int n = s.length();
    int step = 2*r - 2;
    string ans = "";
 
    for(int i = 0; i < r; i++) {
        int j = i, k = step - j, l = r - 1;
        while(j < n) {
            ans += s[j];
            // when j is greater than 0 then j % step != 0 hence a pair will be inserted into 
            // the string, but when we reach the last row i.e. i = r - 1 then k becomes equal to l 
            // and hence the condition k > l fails and only one character is inserted into the string
            if(j % step != 0 && k < n && k > l) {
                ans += s[k];
                k += step;
                l += step;
            }
            j += step;
        }
    }   
    
    return ans;
}
