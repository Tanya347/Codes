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
