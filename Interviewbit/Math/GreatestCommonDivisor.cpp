int Solution::gcd(int A, int B) {
    
    if(A == 0 && B == 0)
        return 0;
    if(A == 0 && B != 0)
        return B;
    if(A != 0 && B == 0)
        return A; 
    
    int g = 1;
    
    for(int i = 2; i <= min(A, B); i++) {
        if(A % i == 0 && B % i == 0)
            g = i;
    }
    
    return g;
}
