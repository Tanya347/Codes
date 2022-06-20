vector<int> Solution::repeatedNumber(const vector<int> &A) {
    unordered_map<int, int> mp;
    
    for(int i = 0; i < A.size(); i++) {
        mp[A[i]]++;
    }
    
    vector<int> ans(2);
    for(int i = 1; i <= A.size(); i++) {
        if(mp.find(i) != mp.end() && mp[i] > 1)
            ans[0] = i;
        else if(mp.find(i) == mp.end())
            ans[1] = i;
    }
    
    return ans;
}
