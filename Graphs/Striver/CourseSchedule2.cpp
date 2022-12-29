/********************************************************************** QUESTION **************************************************************************************/

/*

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]

 

Constraints:

    1 <= numCourses <= 2000
    0 <= prerequisites.length <= numCourses * (numCourses - 1)
    prerequisites[i].length == 2
    0 <= ai, bi < numCourses
    ai != bi
    All the pairs [ai, bi] are distinct.



*/

/********************************************************************** BFS **************************************************************************************/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];

        for(auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            for(auto it: adj[i])
                indegree[it]++;
        }

        vector<int> topo;
        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }

        }
        
        if(topo.size() == numCourses)
            return topo;
        else 
            return {};
        
    }
};

/********************************************************************** DFS **************************************************************************************/

class Solution {
public:

    bool dfs(int node, vector<int> adj[], stack<int>& st,  vector<int>& vis, vector<int>& curr_vis) {
	    vis[node] = 1;
        curr_vis[node] = 1;

	    for(auto it: adj[node]) {
	        if(!vis[it]) {
	            if(!dfs(it, adj, st, vis, curr_vis))
                    return false;
            }
            else if(curr_vis[it])
                return false;
	    }

        curr_vis[node] = 0;
	    st.push(node);
        return true;
	}

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];

        for(auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(numCourses, 0), curr_vis(numCourses, 0);
	    stack<int> st;
	    
	    for(int i = 0; i < numCourses; i++) {
	        if(!vis[i]) {
	            if(!dfs(i, adj, st, vis, curr_vis))    
                    return {};
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