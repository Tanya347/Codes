#include<algorithm>

int maximumProfit(int budget[], int n) {
    // Write your code here
	int ans = 0;
    sort(budget, budget + n);
    
    for(int i = 0; i < n; i++) {
        ans = max(ans, budget[i]*(n - i));
    }
    
    return ans;
}
