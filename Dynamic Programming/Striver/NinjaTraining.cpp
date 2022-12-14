/********************************************************************** QUESTION **************************************************************************************/

/*

Geek is going for n days training program, he can perform any one of these three activities Running, Fighting, and Learning Practice. each activity has the same point on each day. as Geek wants to improve all his skills, he can't do the same activity on two consecutive days, help Geek to maximize his merit points as we were given a 2D array of n*3 points corresponding to each day and activity.

Example:
Input:
n = 3
point= [[1,2,5],[3,1,1],[3,3,3]]
Output:
11
Explanation:
Geek will learn a new move and earn 5 point then on second
day he will do running and earn 3 point and on third day
he will do fighting and earn 3 points so, maximum point is 11.

Your Task:
You don't have to read input or print anything. Your task is to complete the function maximumPoints() which takes the integer n and 2 D array points and returns the maximum point he can earn.

Expected Time Complexity: O(n)
Expected Space Complexity: O(n2)

Constraint:
1 <=  n <= 100000
1 <=  point[i] <= 100

*/

/********************************************************************** BRUTE FORCE **************************************************************************************/

class Solution {
  public:
  
    int maximumPoints(vector<vector<int>>& points, int day, int last) {
        
        int maxi = 0;
        //base case
        if(day == 0) {
            for(int i = 0; i <= 2; i++) {
                if(i != last)
                maxi = max(maxi, points[day][i]);
            }
            return maxi;
        }
            
        for(int i = 0; i <= 2; i++) {
            if(i != last) 
                maxi = max(maxi, points[day][i] + maximumPoints(points, day - 1, i));
        }
        
        return maxi;
    }
    
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        
        return maximumPoints(points, n - 1, 3);
    }
};

/********************************************************************** MEMOIZATION **************************************************************************************/

class Solution {
  public:
  
    int maximumPoints(vector<vector<int>>& points, int day, int last, vector<vector<int>>& dp) {
        
        if(dp[day][last] != -1)
            return dp[day][last];
        
        int maxi = 0;
        
        //base case
        if(day == 0) {
            for(int i = 0; i <= 2; i++) {
                if(i != last)
                maxi = max(maxi, points[day][i]);
            }
            return dp[day][last] = maxi;
        }
            
        for(int i = 0; i <= 2; i++) {
            if(i != last) 
                maxi = max(maxi, points[day][i] + maximumPoints(points, day - 1, i, dp));
        }
        
        return dp[day][last] = maxi;
    }
    
    int maximumPoints(vector<vector<int>>& points, int n) {
        
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return maximumPoints(points, n - 1, 3, dp);
    }
};

/********************************************************************** DP **************************************************************************************/

class Solution {
  public:
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        
        vector<vector<int>> dp(n, vector<int>(4, 0));
        
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][1], points[0][0]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
        
        for(int day = 1; day < n; day++) {
            for(int last = 0; last < 4; last++) {
                
                dp[day][last] = 0;
                
                for(int task = 0; task < 3; task++) {
                    if(last != task)
                    dp[day][last] = max(dp[day][last], points[day][task] + dp[day - 1][task]);
                }
            }
        }
        
        return dp[n - 1][3];
    }
  
};
