/********************************************************************** QUESTION **************************************************************************************/

/*

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

 
Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.

 
Constraints:

    m == image.length
    n == image[i].length
    1 <= m, n <= 50
    0 <= image[i][j], color < 216
    0 <= sr < m
    0 <= sc < n

*/

/********************************************************************** BFS ***********************************************************************************/

// TC: O(N*M*4) ~ O(N*M)
// SC: O(N*M) for queue

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int m = image.size();
        int n = image[0].size();

        // if array is empty we need not do anything
        if(m == 0) return image;

        // BFS 
        queue<pair<int,int>> indices;
        int initial = image[sr][sc];

        // if they happen to be same we do not need to do anything
        if(initial == color) return image;

        indices.push({sr, sc});

        while(!indices.empty()) {
            int i = indices.front().first;
            int j = indices.front().second;
            image[i][j] = color;
            indices.pop();

            int arr[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

            for(int k = 0; k < 4; k++) {
                int x = i + arr[k][0];
                int y = j + arr[k][1];
                if(x >= 0 && y >= 0 && x < m && y < n && image[x][y] == initial) {
                    indices.push({x, y});
                }
            }
        }

        return image;
    }
};

/********************************************************************** DFS **************************************************************************************/

// TC: O(N*M*4) ~ O(N*M)
// SC: O(N*M) for aux stack space

class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int i, int j, int color, int initial) {
        if(i >= 0 && j >= 0 && i < image.size() && j < image[0].size() && image[i][j] == initial) {
            image[i][j] = color;
            dfs(image, i+1, j, color, initial);
            dfs(image, i, j+1, color, initial);
            dfs(image, i, j-1, color, initial);
            dfs(image, i-1, j, color, initial);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // DFS
        int initial = image[sr][sc];
        
        if(initial == color) return image;

        dfs(image, sr, sc, color, initial);
        return image;
    }
};
