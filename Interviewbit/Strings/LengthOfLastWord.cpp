int Solution::lengthOfLastWord(const string A) {
    int i = A.length() - 1;
    int length = 0;
    
    //if there's space in the last
    while(A[i] == ' ') {
        i--;
    }
    
    while(A[i] != ' ' && i >= 0) {
            length++;
            i--;
    }
    return length;
}
