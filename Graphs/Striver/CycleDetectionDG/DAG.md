![image](https://user-images.githubusercontent.com/80675137/208669339-8b9e25c9-d04b-4bac-ba64-6008497aa92f.png)

* previously in undirected graph what we used to is we used one visited array and also maintained a check of the parent. If the node has been visited already and is not the parent of the node we are exploring then that means cycle is detected

* But in case of directed graphs, what can happen is there may be two directions leading to one node and that node may be visited before but that doesn't mean that there is a cycle

* So to keep a check of whether or not the node is visited again in the same recursion branch we maintain another visited array that maintains the visited status of nodes during the current visit

* We keep marking nodes visited in visited array and current visited array but while backtracking we mark the nodes as unvisited in current_visited array because the current call is over

* Now whenever a case arises that the current node has been visited but it is not visited in the current visit array that means it was visited in some other call and is not a part of a cycle

* But if it is the case that the node is visited and also visited in current call then that means there is a cycle and we can return true
