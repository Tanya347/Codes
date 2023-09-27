/******************************************************************* QUESTION ************************************************************************/

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note :
1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
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

#include <string>
#include <vector>
using namespace std;

vector<string> comb = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    
    if(num == 0) {
        output[0] = "";
        return 1;
    }
    
    int last = num % 10;
    int n = comb[last].size();
    
    int count = keypad(num/10, output);
    
    for(int i = 1; i < n; i++) {
        
        for(int j = 0; j < count; j++) {
            output[j + count*i] = output[j] + comb[last][i];
        }
    }
    
    for(int i = 0; i < count; i++) {
        output[i] += comb[last][0];
    }
    
    return n*count; 
}

/******************************************************************* EXPLANATION ************************************************************************/

Suppose for 23 we want to generate possible combinations

according to the code for num 0 we get an empty string
moving one step up in the recursion tree num will be 2 and will have "" in the output and count would be 1.
at index 1 we will recieve 'b' and at index 2 we will recieve 'c'. 'a' will get appended to "" at index 0.

Now returning back to where last is 3, count is 3 and n = 3.

  i = 1, j = 0
  at index 0 + 1*3 = 3 we will get a + e = "ae"
  i = 1, j = 1
  at index 1 + 1*3 = 4 we will get b + e = "be"
  i = 1, j = 2
  at index 2 + 1*3 = 5 we will get c + e = "ce"

  and same for "af" at 6, "bf" at 7 and "cf" at 8

int the last loop, 'd' will get appended to what is present at index 0, 1, 2 i.e. "ad", "bd", "cd"

hence output array becomes: "ad", "bd", "cd", "ae", "be", "ce", "af", "bf", "cf"

what we are essentially doing is, creating a template at the starting count number indices of the output array, which we are then using to create next combinations
leaving the first character. The first character is later used to create required combinations from the first count strings we were using as template.

we have to do all this index manipulation because of the parameter output which is a static array given to us. Had it been a vector, things would have been easier.
