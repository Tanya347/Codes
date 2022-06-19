#include<queue>

vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    
    priority_queue<int> pq;
    
    for(int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }
    
    for(int i = k; i < n; i++) {
        if(pq.top() >= arr[i]) {
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
}
