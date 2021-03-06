#include<vector>
#include<queue>
vector<int> kLargest(int arr[], int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }
    
    for(int i = k; i < n; i++) {
        if(pq.top() <= arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        } 
    } 
    
    vector<int> ans(k, 0);
    for(int i = k - 1; i >= 0; i--) {
        ans[i] = pq.top();
        pq.pop();
    }
    
    return ans;
