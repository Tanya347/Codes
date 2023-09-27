/******************************************************************* QUESTION ************************************************************************/

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S
Output Format :
All possible codes in different lines
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw

/******************************************************************* ANSWER ************************************************************************/

#include <string.h>
using namespace std;

void print_helper(string input, string output) {
    if(input[0] == '\0') {
        cout<<output<<endl;
        return;
    }
    
    int n1 = input[0] - '0';
    int n2 = 10*(input[0] - '0') + input[1] - '0';
    
    char c1 = n1 + 'a' - 1;
    print_helper(input.substr(1), output + c1);
    
    if(n2 >= 10 && n2 <= 26) {
        char c2 = n2 + 'a' - 1;
        print_helper(input.substr(2), output + c2);
    }
    
    return;
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output = "";
    print_helper(input, output);
}
