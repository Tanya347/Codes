vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        int i = 0, j = 0;
        vector<int> ans;
        
        while(i < n && j < m) {
            if(arr1[i] == arr2[j]) {
                if(ans.empty() || (ans.size() > 0 && ans[ans.size() - 1] != arr1[i]))
                    ans.push_back(arr1[i]);
                i++;
                j++;
            }
            
            else if(arr1[i] < arr2[j]) {
                if(ans.empty() || (ans.size() > 0 && ans[ans.size() - 1] != arr1[i]))
                    ans.push_back(arr1[i]);
                i++;
            }
            else {
                if(ans.empty() || (ans.size() > 0 && ans[ans.size() - 1] != arr2[j]))
                    ans.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i < n) {
            if(ans.size() > 0 && ans[ans.size() - 1] != arr1[i])
                ans.push_back(arr1[i]);
            i++;
        }
        
        while(j < m) {
            if(ans.size() > 0 && ans[ans.size() - 1] != arr2[j])
                ans.push_back(arr2[j]);
            j++;
        }
        
        return ans;
    }
