// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// For a rooted tree with any arbitary number of children for each node,
// not necessarily n-ary tree.
// Remove all the leaf nodes, and store them in a list, this would create
// new leaf nodes. Repeat untill all the nodes are removed
// Conditions : Freshly created leaf nodes(node whose children are removed)
// should not be removed just after its children are removed, unless
// there's no other option for us, then we can remove it

vector<vector<int>> removeLeaves(vector<vector<int>>& edges, int n) {
    
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    
    for(auto it: edges){
        adj[it[1]].push_back(it[0]);
        indegree[it[0]]++;
    }
    
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }
    
    vector<vector<int>> ans;

    while(!q.empty()) {
        int s = q.size();
        vector<int> temp;
        while(s--) {
            int node = q.front();
            q.pop();
            temp.push_back(node);
            
            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        ans.push_back(temp);
    }
    
    return ans;
}

int main() {
    
    int n = 11;
    
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4},
        {2, 5}, {2, 6}, {3, 7}, {3, 8},
        {4, 9}, {4, 10}
    };
    
    vector<vector<int>> ans = removeLeaves(edges, n);
    
    for(int i = 0; i < ans.size(); i++) {
        cout<<"Level "<<i + 1<<": ";
        for(int j = 0; j < ans[i].size(); j++) {
            cout<<ans[i][j];
            if(j != ans[i].size() - 1) cout<<", ";
        }
        cout<<endl;
    }
    
    return 0;
}
