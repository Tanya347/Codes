
void print_helper(int input[], int size, int* output, int m, int k) {
    
    if(size == 0) {
        if(k == 0) {
            for(int i = 0; i < m; i++) 
            	cout<<output[i]<<" ";
        	cout<<endl;
        	return;
        }
        else
            return;
    }
    
    int* newoutput = new int[m + 1];
    
    for(int i = 0; i < m; i++) {
        newoutput[i] = output[i];
    }
    newoutput[m] = input[0];
    print_helper(input + 1, size - 1, output, m, k);
    print_helper(input + 1, size - 1, newoutput, m + 1, k - input[0]);
    
    delete [] newoutput;
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    
    int *output = new int[size];
    print_helper(input, size, output, 0, k);
    delete [] output;
}
