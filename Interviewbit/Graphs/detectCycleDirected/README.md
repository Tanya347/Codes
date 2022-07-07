![image](https://user-images.githubusercontent.com/80675137/177704757-a6186fd6-ec3e-4659-95bb-3ffb519bb634.png)
![image](https://user-images.githubusercontent.com/80675137/177704831-d31849a1-0a8f-4372-8591-597ff7bcc120.png)

Algorithm:

    * Create the graph using the given number of edges and vertices.
    * Create a recursive function that that current index or vertex, visited, and recusrsion stack.
    * Mark the current node as visited and also mark the index in recursion stack.
    * Find all the vertices which are not visited and are adjacent to current node. Recursively call the function for those vertices, If the recursive function returns true return true.
    * If the adjacent vertices are already marked in the recursion stack then return true.
    * Create a wrapper class, that calls the recursive function for all the vertices and if any function returns true return true. Else if for all 
