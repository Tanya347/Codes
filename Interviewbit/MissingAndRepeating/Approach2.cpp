vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> ans;
    vector<int> temp = A;
    for(int i = 0; i < A.size(); i++) {
        if(temp[abs(temp[i]) - 1] > 0)
            temp[abs(temp[i]) - 1] = -temp[abs(temp[i]) - 1];
        else 
            ans.push_back(abs(temp[i]));
    }
    
    for(int i = 0; i < temp.size(); i++) {
        if(temp[i] > 0)
            ans.push_back(i + 1);
    }
    
    return ans;
}
