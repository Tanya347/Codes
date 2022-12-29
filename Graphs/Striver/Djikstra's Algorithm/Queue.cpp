vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> dist(V, 1e9);
        
        dist[S] = 0;
        pq.push({0, S});
        
        while(!pq.empty()) {
            int d = pq.top().first;
            int n = pq.top().second;
            pq.pop();
            
            for(auto it: adj[n]) {
                
                int adjNode = it[0];
                int adjWeight = it[1];
                
                if(dist[adjNode] > d + adjWeight) {
                    
                    dist[adjNode] = d + adjWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
