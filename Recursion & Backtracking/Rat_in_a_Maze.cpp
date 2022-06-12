#include<bits/stdc++.h>
using namespace std;

void getPath(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& path, int n) {
    if(i == n - 1 && j == n - 1) {
        path[i][j] = 1;
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < n; j++) {
            	cout<<path[i][j]<<" ";
        	}
    	}
        cout<<endl;
    }
    
    if(i < 0 || j < 0 || i >= n || j >= n || path[i][j] == 1 || matrix[i][j] == 0) {
        return;
    } 
    
    path[i][j] = 1;
    getPath(matrix, i - 1, j, path, n);
    getPath(matrix, i + 1, j, path, n);
    getPath(matrix, i, j - 1, path, n);
    getPath(matrix, i, j + 1, path, n);
        
    path[i][j] = 0;
}



int main() {

	// Write your code here
    int n;
    cin>>n;
    
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>matrix[i][j];
        }
    }
    
    vector<vector<int>> path(n, vector<int>(n, 0));
    getPath(matrix, 0, 0, path, n);
    
	return 0;
}
