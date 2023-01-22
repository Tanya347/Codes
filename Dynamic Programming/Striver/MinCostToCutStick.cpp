/******************************************************************* QUESTION *******************************************************************************/

/*

Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:


Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.

 

Example 1:


Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
Example 2:

Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.

*/

/******************************************************************* BRUTE FORCE *******************************************************************************/

// i and j will represent the current window of stick, how many cuts have been performed etc

class Solution {
public:

    int cost(int i, int j, vector<int>& cuts) {
        // base case
        if(i > j)
            return 0;

        int mini = 1e8;

        for(int ind = i; ind <= j; ind++) {
            // cost will be defined by length of current stick left from previous cuts hence we will use the cut area j + 1 and i - 1 indicating that
            // cuts at these areas have already been performed
            // then we'll iterate over all possible cut areas and find the min cost
            // when cut is performed at index ind then we remove it from our focus and send ind - 1 and ind + 1 as the prospect cut areas for next time
            int c = cuts[j + 1] - cuts[i - 1] + cost(i, ind - 1, cuts) + cost(ind + 1, j, cuts); 
            mini = min(mini, c);
        }

        return mini;
    }

    int minCost(int n, vector<int>& cuts) {
        
        // we insert 0 and size of stick just for the case where no cut has been performed yet so and i and j point to first and last index of cuts
        // so to get the cost for such cases
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
      
        // even though size of cuts is +2 we restrict j to second last element as the last index basically has size of the stick
        return cost(1, cuts.size() - 2, cuts);
    }
};

/******************************************************************* MEMOIZATION *******************************************************************************/

class Solution {
public:

    int cost(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int mini = 1e8;

        for(int ind = i; ind <= j; ind++) {
            int c = cuts[j + 1] - cuts[i - 1] + cost(i, ind - 1, cuts, dp) + cost(ind + 1, j, cuts, dp); 
            mini = min(mini, c);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));
        return cost(1, cuts.size() - 2, cuts, dp);
    }
};

/******************************************************************* DP *******************************************************************************/

class Solution {
public:

    int minCost(int n, vector<int>& cuts) {
        
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        
        // we take plus 2 cause size has been increased and index may go out of bounds when we use operations like ind + 1
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        // i went from 1 to c so we reverse it here in bottom up and same goes for j rest is exactly same as recursion
        for(int i = c; i >= 1; i--) {
            for(int j = 1; j <= c; j++) {
                
                if(i > j) continue;

                long mini = 1e9;
                for(int ind = i; ind <= j; ind++) {
                    long cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                    mini = min(cost, mini);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][c];
    }
};
