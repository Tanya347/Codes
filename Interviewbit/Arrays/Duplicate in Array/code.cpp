int Solution::repeatedNumber(const vector<int> &A) {
    
    int j = 0;
    vector<int> B = A;
    
    // we use the fact that value of elements in array are less than n hence we can use them as indexes
    // what we are doing is we extract whatever is present at a particular index and make it the next index
    // and mark whatever is present at current index as -1, this way if a duplicate element exists then it will
    // send us to an index again which was already marked as -1 by the other duplicate
    while(B[j] != -1) {
        int k = B[j];
        B[j] = -1;
        j = k;
    }
    
    return j;
}
