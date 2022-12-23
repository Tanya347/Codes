bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int> indegree(V, 0);
	    
	    // finding indegree of every vertex
	    for(int i = 0; i < V; i++) {
	        for(auto j : adj[i])
	            indegree[j]++;
	    }
	    
	    queue<int> q;
	    
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    vector<int> ans;
	    
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto n : adj[node]) {
	            indegree[n]--;
	            if(indegree[n] == 0)
	                q.push(n);
	        }
	    }
	    
	    if(ans.size() == V) 
	        return false;
	    else
	        return true;
    }
