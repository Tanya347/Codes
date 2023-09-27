/******************************************************************* QUESTION ************************************************************************/

Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note :
The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

/******************************************************************* ANSWER ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> comb = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void print_helper(string output, int num) {
    
    if(num == 0) {
        cout<<output<<endl;
        return;
    }
    
    int n = comb[num%10].size();
    
    for(int i = 0; i < n; i++) {
        print_helper(comb[num%10][i] + output, num/10);
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output;
    print_helper(output, num);
}
