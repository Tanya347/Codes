bool checkCycle(int node, vector<vector<int>> graph, vector<int>& visited, vector<int>& dfsVisited) {
    
    visited[node] = 1;
    dfsVisited[node] = 1;
    
    for(auto it: graph[node]) {
        if(!visited[it]) {
            if(checkCycle(it, graph, visited, dfsVisited)) return true;
        } else if(dfsVisited[it]) {
            return true;
        }
    }
    
    dfsVisited[node] = 0;
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<vector<int>> graph(A + 1);
    
    for(auto v:B) {
        graph[v[0]].push_back(v[1]);
        v.clear();
    }
    
    vector<int> visited(A + 1, 0);
    vector<int> dfsVisited(A + 1, 0);
    
    for(int i = 1; i <= A; i++) {
        if(!visited[i]) {
            if(checkCycle(i, graph, visited, dfsVisited))
                return 1;
        }
    }
    
    return 0;
}
