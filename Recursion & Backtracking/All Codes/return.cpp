/******************************************************************* QUESTION ************************************************************************/

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
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


int getCodes(string input, string output[10000]) {
    
    if(input.empty())
    {
        output[0] = "";
        return 1;
    }
    
    int n1 = input[0] - '0';
    int n2 = 10*(input[0]-'0') + (input[1]-'0');	
   
    string output1[10000], output2[10000];
    
    int ans1 = getCodes(input.substr(1),output1 );
    char c1 = n1 + 'a' - 1;
    
    for(int i = 0; i < ans1; i++) {
        output[i] = c1 + output1[i];
    }
   
    if(n2 >= 10 && n2 <= 26) {
    
    	char c2 = n2 + 'a' - 1;
    	int ans2 = getCodes(input.substr(2),output2 );
    
    	for(int i = ans1, j = 0; i < ans1 + ans2 && j < ans2; i++, j++) {
        	output[i] = c2 + output2[j];
    	}
        
        return ans1 + ans2;
    }
    
    return ans1;
}
