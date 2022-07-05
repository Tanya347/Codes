//find number of consonants and vowels and return product as a unique vowel/consonant pair will definitely form a substring


int Solution::solve(string A) {
    
    int size = A.size();
    
    if(size == 1)
        return 0;
    
    long long int v = 0, c = 0;
    
    for(int i = 0; i < size; i++) {
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u')
        v++;
        else 
        c++;
    }
    
    long long int ans = v*c % 1000000007;
    
    return ans;
}
