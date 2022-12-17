/********************************************************************** QUESTION **************************************************************************************/

/*

Given an integer n representing number of vertices. Find out how many undirected graphs (not necessarily connected) can be constructed out of a given n number of vertices.

 
Example 1:

Input: 2
Output: 2

Example 2:

Input: 5
Output: 1024
 

Your Task:

Complete the function count() which takes an integer n as input and return the count of total number of graphs possible.


Expected Time Complexity: O(1)

Expected Space Complexity: O(1)


Constraints:

1<=n<=10

*/

/********************************************************************** ANSWER **************************************************************************************/

class Solution {
  public:
    long long count(int n) {
        // your code here
        return (long long)pow(2, n*(n - 1)/2);
    }
};

/********************************************************************** EXPLANATION **************************************************************************************/

Each node has the choice of either connecting or not connecting with all n - 1 nodes. So there are 2 choices for each node
There are total n nodes. So n ( n - 1)
Now as there the connection between two nodes gets counted twice, the combinations is actually n (n - 1)/2
Which makes the no. of possible graphs = 2n(n - 1)/2
