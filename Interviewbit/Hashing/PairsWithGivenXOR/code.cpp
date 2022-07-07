int Solution::solve(vector<int> &A, int B) {
    
    unordered_map<int, int> key;
    
    for(int i = 0; i < A.size(); i++) {
        key[A[i]]++;
    }
    
    int count = 0;
    
    //we will find whether A[i]^B exists or not cause
    // if 5 ^ 6 = 3
    // then 5 ^ 3 = 6 and 6 ^ 3 = 5
    // the XOR itself can give you the other element in the pair
  
    for(int i = 0; i < A.size(); i++) {
        if(key.find(A[i] ^ B) != key.end()) {
            count += key[A[i]] * key[A[i] ^ B];
            key[A[i]] = 0;
            key[A[i] ^ B] = 0;
        }
    }
    
    return count;
}
