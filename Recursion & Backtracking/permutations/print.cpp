/********************************************************** QUESTION ****************************************************************************/

Given an input string (STR), print all possible permutations of the input string.
Note:
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.
Input Format:
The only input line contains a string (STR) of alphabets in lower case
Output Format:
Print each permutations in a new line
Constraint:
1<=length of STR<=8
Time Limit: 1sec
Sample Input 1:
cba
Sample Output 1:
abc
acb
bac
bca
cab
cba

/********************************************************** ANSWER ****************************************************************************/

#include <iostream>
#include <string>
using namespace std;

void print_helper(string input, string output) {
	
    if(input.size() == 0) {
        cout<<output<<endl;
    }
    
    for(int i = 0; i < input.size(); i++) {
        print_helper(input.substr(0,i) + input.substr(i + 1), input[i] + output);
    }
}

void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    string output = "";
    print_helper(input, output);
}
