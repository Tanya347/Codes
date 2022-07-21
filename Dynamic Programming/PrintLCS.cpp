#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string findLCS(string X, string Y)
	{
		// Write your code here...
		int m = X.length();
		int n = Y.length();
		
		vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0)) ;
		
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				if(X[i - 1] == Y[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				} else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		
		
		string ans;
		
		int i = m, j = n;
		
		while(i > 0 && j > 0) {
			if(X[i - 1] == Y[j - 1]) {
				ans.push_back(X[i - 1]);
				i--;
				j--;
			} else {
				if(dp[i - 1][j] > dp[i][j - 1])
					i--;
				else
					j--;
			}
		}
		
		reverse(ans.begin(), ans.end());
		
		return ans;
	}

int main() {
	//code
	string ans = findLCS("abcdefas", "asbcdeflas");
	cout<<ans;
	return 0;
}
