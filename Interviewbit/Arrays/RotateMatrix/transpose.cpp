void Solution::rotate(vector<vector<int> > &A) {
    
    for(int level = 0; level < A.size() - 1; level++) {
        for(int i = level + 1; i < A.size(); i++) {
            int swap = A[level][i];
            A[level][i] = A[i][level];
            A[i][level] = swap;
        }
    }
    
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A.size() / 2; j++) {
            int swap = A[i][j];
            A[i][j] = A[i][A.size() - j - 1];
            A[i][A.size() - j - 1] = swap;
        }
    }
    
}
