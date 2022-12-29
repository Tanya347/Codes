/******************************************************************* QUESTION *******************************************************************************/

/*

Give a graph, a source and a destination, we need to print the shortest path from source node to destination using Djisktra's algorithm. We are taking source as 0
here and destination as n - 1 but it can be taken as something else as well.

*/

/******************************************************************* ANSWER *******************************************************************************/

// everything same as pq djisktra just we used a parent array to retrace the path followed to find shortest path

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges} {
  
  vector<pair<int, int>> adj[n];
  for(auto it: edges) {
    adj[it[0]].push_back({it[1], it[2]});
    adj[it[1]].push_back({it[0], it[2]});
  }
  
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> dist(n, 1e9), parent(n);
  
  for(int i = 0; i < n; i++) 
    parent[i] = i;
  
  dist[0] = 0;
  
  while(!pq.empty()) {
    
    int distance = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    
    for(auto it: adj[node]) {
      int adjNode = it.first;
      int adjWeight = it.second;
      if(dist[adjNode] > distance + adjWeight) {
        dist[adjNode] = distance + adjWeight;
        pq.push({dist[adjNode], adjNode});
        parent[adjNode] = node;
      }
    }
  }
    
  if(dist[n - 1] == 1e9) return {-1};
    
  vector<int> path;
  int node = n - 1;
    
  while(parent[node] != node) {
    path.push_back(parent[node]);
    node = parent[node];
  }
    
  path.push_back(0);
  reverse(path.begin(), path.end());
  return path;
}
