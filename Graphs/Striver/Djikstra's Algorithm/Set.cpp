class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int, int>> st;
        
        vector<int> dist(V, 1e9);
        
        dist[S] = 0;
        st.insert({0, S});
        
        while(!st.empty()) {
            auto it = *(st.begin());
            int d = it.first;
            int n = it.second;
            st.erase(it);
            
            for(auto it: adj[n]) {
                
                int adjNode = it[0];
                int adjWeight = it[1];
                
                if(dist[adjNode] > d + adjWeight) {
                    
                    // if someone reached before erase the paths
                    // will affect the T.C. minutely but can save further iterations
                    if(dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});
                        
                    dist[adjNode] = d + adjWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};
