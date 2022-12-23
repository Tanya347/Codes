/********************************************************************** QUESTION **************************************************************************************/

/*

Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.


Example 1:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.

Example 2:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 4, 2, 1, 3, 0.


Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of a the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then console output will be 1 else 0.


Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).


Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ (N*(N-1))/2


*/

/********************************************************************** KAHN'S ALGORITHM **************************************************************************************/

vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
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
	    
	    return ans;
	}

/********************************************************************** EXPLANATION **************************************************************************************/

- The steps include first finding the indegree of every node
- Then we push those nodes into the queue whose indegree is 0
- Then we run BFS on those nodes and once popping it out we push those nodes into answer array
- Then we travel all the nodes it points to and reduce their indegrees 
- If the indegree of a node becomes 0 we simply push it into the queue

what we're basically trying to do is that we are targetting those nodes first with 0 outdegree and then we're further reaching into the depth by exploring their neigbours
this is what topological sorting is all about

/********************************************************************** ANSWER USING STACK *********************************************************************************/

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs(int node, vector<int> adj[], stack<int>& st,  vector<int>& vis) {
	    vis[node] = 1;
	    for(auto it: adj[node]) {
	        if(!vis[it])
	            dfs(it, adj, st, vis);
	    }
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V, 0);
	    stack<int> st;
	    
	    for(int i = 0; i < V; i++) {
	        if(!vis[i]) {
	            dfs(i, adj, st, vis);
	        }
	    }
	    
	    vector<int> ans;
	    while(!st.empty()) {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};


/********************************************************************** EXPLANATION **************************************************************************************/

- Here we are performing normal DFS
- Only difference is that we are maintaining a stack that maintains nodes whose neighbours have been fully traversed
- The ones that are like leafs will be pushed into the stack first and hence they will be popped out last
- The ones that are connected to a lot of nodes will be pushed later and popped earlier
