
void helper(string A, int B, string& ans) {
    if(B == 0) {
        if(ans < A) ans = A;
        return;
    }
    
    for(int i = 0; i < A.length(); i++) {
        for(int j = i + 1; j < A.length(); j++) {
            swap(A[i], A[j]);
            helper(A, B - 1, ans);
            swap(A[i], A[j]);
        }
    }
}

string Solution::solve(string A, int B) {
    string ans = "";
    helper(A, B, ans);
    return ans;
}
