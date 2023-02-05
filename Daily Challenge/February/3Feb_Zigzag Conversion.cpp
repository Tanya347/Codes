/******************************************************************* QUESTION *******************************************************************************/

/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

*/

/******************************************************************* ANSWER *******************************************************************************/

class Solution {
public:
    string convert(string s, int numRows) {
        
        // edge cases
        if(s.length() <= 2 || numRows <= 1)
            return s;

        /*
        
        Required pattern:
                          rows   strings
          P     I     N    1      PIN
           A   L S   I G   2      ALSIG
            Y A   H R      3      YAHR
             P     I       4      PI
             
           P A Y P A L I S H I R I N G
           1 2 3 4 3 2 1 2 3 4 3 2 1 2
           
           these are the rows 
           so we want to make the strings for each row 
           now we will traverse the whole string and once we hit the last or first row will start moving up or down respectively
        */
        
        int row = 0, step;
        vector<string> rows(numRows, "");

        for(int i = 0; i < s.length(); i++) {

            rows[row].push_back(s[i]);

            if(row == 0)
                step = 1;
            else if(row == numRows - 1)
                step = -1;

            row += step;
        }

        string ans = "";
        for(int i = 0; i < numRows; i++) {
            ans.append(rows[i]);
        }

        return ans;
    }
};
