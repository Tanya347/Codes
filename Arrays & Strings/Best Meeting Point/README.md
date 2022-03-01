1. A group of two or more people wants to meet and minimize the total travel distance.
2. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. 
3. Return min distance where distance is calculated using 'Manhattan Distance', where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

Constraints
1 <= grid.length <= 10^4
 1 <= grid[i].length 	<= 10^4

Format
```Input
[
    [1,0,0,0,1],
    [0,0,0,0,0],
    [0,0,1,0,0]
]
```

```
Output
6
```

Explanation:
The point (0,2) is an ideal meeting point, as the total travel distance of 2 + 2 + 2 = 6 is minimal. So return 6.

```
Example
Sample Input

3 5
1 0 0 0 1
0 0 0 0 0
0 0 1 0 0

Sample Output
6
```
