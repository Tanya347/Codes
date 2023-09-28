/********************************************************** QUESTION ****************************************************************************/

Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S
Output Format :
All permutations (in different lines)
Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba

/********************************************************** ANSWER ****************************************************************************/

#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    
    if(input.size() == 0) {
        output[0] = "";
        return 1;
    }
    
    string output1[10000];
    int s = 0;
    
    for(int i = 0; i < input.size(); i++) {
        int count = returnPermutations(input.substr(0, i) + input.substr(i + 1), output1);
        
        for(int j = 0; j < count; j++) {
            output[s++] = input[i] + output1[j];
        }
    }
    
    return s;
}
