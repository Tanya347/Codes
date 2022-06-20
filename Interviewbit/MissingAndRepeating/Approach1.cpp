vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> ans;
    long long int len = A.size();
    long long int n_sum = len*(len + 1) / 2, n_square = (len * (len + 1) * (2*len + 1)) / 6;
    
    
    for(int i = 0; i < A.size(); i++) {
        n_sum -= (long long int)A[i];
        n_square -= (long long int)A[i] *(long long int)A[i];
    }
    
    int b = (int)(n_sum + n_square/n_sum)/2;
    int a = (int)(b - n_sum);
    
    ans.push_back(a);
    ans.push_back(b);
    
    return ans;
}
