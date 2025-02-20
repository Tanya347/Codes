/*
given a lattice kinda graph where each node is either a torch node that has power 16 or wire node where value is 0,
if power node is connected to wire node, it will transmit power to wire and value would become 15 from 0 (1 value would be lost during transmission), again if this wire node is connected to another wire node then value would become 14 of that node
for eg 16 -> 0 -> 0 would become 15 -> 14 -> 13, unless there is one more torch node ahead, then
16 -> 0 -> 0 -> 16
16 -> 15 -> 14 -> 16
16 -> 15 -> 15 <- 16


nothing was given, I had to tell how the representation would look like, in the end we need to return graph when the power had transmitted from all torch nodes to expected wire nodes. And graph in kinda lattice, like a cube (3 d).
Used MultiSource BFS - C++ code that is easy to understand with Sample Test Case
*/

/******************************************************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;


void calculateMaxPower(vector<int>&power,vector<vector<int>>&g){
    int n=power.size();
    vector<int>vis(n,0);
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        if(power[i]==16){
            q.push({i,power[i]});
            vis[i]=1;
        }
    }
    while(q.size()){
        int l = q.size();
        while(l--){
            auto p = q.front();
            q.pop();
            int a = p.first;
            int b = p.second;
            for(auto y : g[a]){
                if(vis[y]==0){
                    power[y]=max(b-1,power[y]);
                    vis[y]=1;
                    if(power[y]>0){
                        q.push({y,power[y]});
                    }
                }
            }
        }
    }
    
    for(auto it : power){
        cout<<it<<" ";
    }
    cout<<endl;
}
int main(){
    int n,x,y;
    cin>>n;
    vector<int>power(n);
    for(int i=0;i<n;i++){
        cin>>power[i];
    }
    vector<vector<int>>g(n);
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    calculateMaxPower(power,g);
    return 0;
}

/******************************************************************************************************************************************************/

Example

Input :
n = 18
power = [0, 0, 0, 16, 16, 0, 16, 16, 0, 0, 0, 16, 0, 0, 0, 16, 0, 16]
edges = [[0,1],[1, 2],[2, 3],[1, 4],[4, 5] ,[5, 6],[4 ,7],[7, 8],[8, 9],[9, 10],[10, 11],[10 ,12],[12, 13],[12, 15],[13 ,14],[13 ,16],[16, 17]]


Output :
power = [14, 15, 15 ,16 ,16, 15, 16, 16 ,15 ,14 ,15 ,16 ,15 ,14 ,13 ,16 ,15 ,16]

/******************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int val;
    int index;
    vector<int> neighbour; // List of indices

    Node(int v, int i, vector<int> n) : val(v), index(i), neighbour(n) {}

    void setValue(int value) {
        val = value;
    }
};

vector<Node> solve(vector<Node>& graph) {
    queue<Node*> q;
    vector<bool> visited(graph.size(), false);

    // Add all torch nodes (val == 16) to the queue
    for (Node& node : graph) {
        if (node.val == 16) {
            q.push(&node);
        }
    }

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();

            if (visited[node->index]) continue;
            visited[node->index] = true;

            for (int neighbourIndex : node->neighbour) {
                Node& neighbourNode = graph[neighbourIndex];
                if (!visited[neighbourNode.index]) {
                    if (neighbourNode.val < node->val) {
                        neighbourNode.setValue(node->val - 1);
                    }
                    q.push(&neighbourNode);
                }
            }
        }
    }

    return graph;
}

// Example usage
int main() {
    vector<Node> graph = {
        Node(16, 0, {1, 2}),  // Torch node
        Node(0, 1, {0, 3}),
        Node(0, 2, {0}),
        Node(0, 3, {1})
    };

    vector<Node> result = solve(graph);

    for (const Node& node : result) {
        cout << "Node " << node.index << " has value: " << node.val << endl;
    }

    return 0;
}

