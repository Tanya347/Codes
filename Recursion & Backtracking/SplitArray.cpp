
bool helper(int *input, int size, int lsum, int rsum, int i) {
    
    if(i == size)
        return lsum == rsum;
    
    if(input[i] % 5 == 0) {
        lsum += input[i];
    }
    
    else if(input[i] % 3 == 0) {
        rsum += input[i];
    }
    
    else return helper(input, size, lsum + input[i], rsum, i + 1) || 
         helper(input, size, lsum, rsum + input[i], i + 1);
    
    return helper(input, size, lsum, rsum, i + 1);
}

bool splitArray(int *input, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    return helper(input, size, 0, 0, 0);
    
}
