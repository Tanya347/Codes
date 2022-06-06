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
