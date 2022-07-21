/********************************************************************** QUESTION **************************************************************************************/

/*

Problem Description

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

Note: The test cases are generated in the following format (use the following format to use See Expected Output option):

First integer N is the number of nodes.

Then, N intgers follow denoting the label (or hash) of the N nodes.

Then, N2 integers following denoting the adjacency matrix of a graph, where Adj[i][j] = 1 denotes presence of an undirected edge between the ith and jth node, O otherwise.



Problem Constraints

1 <= Number of nodes <= 105


Input Format

First and only argument is a node A denoting the root of the undirected graph.


Output Format

Return the node denoting the root of the new clone graph.


Example Input

Input 1:

      1
    / | \
   3  2  4
        / \
       5   6

Input 2:

      1
     / \
    3   4
   /   /|\
  2   5 7 6



Example Output

Output 1:

 Output will the same graph but with new pointers:
      1
    / | \
   3  2  4
        / \
       5   6

Output 2:

      1
     / \
    3   4
   /   /|\
  2   5 7 6



Example Explanation

Explanation 1:

 We need to return the same graph, but the pointers to the node should be different.

*/

/********************************************************************** ANSWER **************************************************************************************/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

UndirectedGraphNode* dfs(UndirectedGraphNode* node, unordered_map<int, UndirectedGraphNode*>& visited) {
        
    // create a new node and store its address
    UndirectedGraphNode *n = new UndirectedGraphNode(node -> label);
    visited[node -> label] = n;
        
    // travel all the neighbors of this particular node
    for(int i = 0; i < node -> neighbors.size(); i++) {
            
        // if not visited then call bfs on this node so that it gets all the neighbors of this node
        if(visited.find(node -> neighbors[i] -> label) == visited.end()) {
            
            UndirectedGraphNode *new_node = dfs(node -> neighbors[i], visited);
            
            // push back the results in the neighbors array of this particular node
            n -> neighbors.push_back(new_node);
                
        }
            
        // if it has already been created visited that means we do not need to perform the task of finding its 
        // neighbours we can just find the address of this node based on the label and insert into the neighbors
        // of this particular node
        else {
            n -> neighbors.push_back(visited.find(node -> neighbors[i] -> label) -> second);
        }
    }
        
    return n;
} 

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(node == NULL)
            return NULL;
       
    // create a map for visited nodes
    // this map has index as label and value as the address of node so that
    // we can search for a node based on its label 
    unordered_map<int, UndirectedGraphNode*> visited;
    return dfs(node, visited);
}
