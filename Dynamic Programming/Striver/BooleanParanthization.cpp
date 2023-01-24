/******************************************************************* QUESTION *******************************************************************************/

/*

A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

't' that evaluates to true.
'f' that evaluates to false.
'!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
'&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
'|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.

 

Example 1:

Input: expression = "&(|(f))"
Output: false
Explanation: 
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.
Example 2:

Input: expression = "|(f,f,f,t)"
Output: true
Explanation: The evaluation of (false OR false OR false OR true) is true.
Example 3:

Input: expression = "!(&(f,t))"
Output: true
Explanation: 
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.
 

Constraints:

1 <= expression.length <= 2 * 104
expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.

*/

/******************************************************************* BRUTE FORCE *******************************************************************************/

class Solution{
public:

    long long rec(int i, int j, int isTrue, string S) {
        
        // partition is finished
        if(i > j)
            return 0;
            
        // only one element is left
        if(i == j) {
            if(isTrue) return S[i] == 'T';
            else return S[i] == 'F';
        }
        
        long long ways = 0;
        
        for(int ind = i + 1; ind <= j - 1; ind = ind + 2) {
            
            // get all possibilties of true and false on all partitions
            long long LT = rec(i, ind - 1, 1, S);
            long long LF = rec(i, ind - 1, 0, S);
            long long RT = rec(ind + 1, j, 1, S);
            long long RF = rec(ind + 1, j, 0, S);
            
            if(S[ind] == '&') {
                
                if(isTrue)
                    ways += (LT * RT) % 1003;
                else
                    ways += ((LF * RF) % 1003 + (LF * RT) % 1003 + (LT * RF) % 1003) % 1003;
            }
            
            else if(S[ind] == '|') {
                
                if(isTrue)
                    ways += ((LT * RT) % 1003 + (LF * RT) % 1003 + (LT * RF) % 1003) % 1003;
                else
                    ways += (LF * RF) % 1003;
            }
            
            else {
                
                if(isTrue)
                    ways += ((LT * RF) % 1003 + (RT * LF) % 1003);
                else
                    ways += ((LT * RT) % 1003 + (LF * RF) % 1003);  
            }
        }
        
        return ways % 1003;
    }

    int countWays(int N, string S){
        // code here
        return rec(0, N - 1, 1, S) % 1003;
    }
};

/******************************************************************* MEMOIZATION *******************************************************************************/

class Solution{
public:

    long long rec(int i, int j, int isTrue, string S, vector<vector<vector<int>>>& dp) {
        
        // partition is finished
        if(i > j)
            return 0;
            
        // only one element is left
        if(i == j) {
            if(isTrue) return S[i] == 'T';
            else return S[i] == 'F';
        }
        
        if(dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
            
        long long ways = 0;
        
        for(int ind = i + 1; ind <= j - 1; ind = ind + 2) {
            
            // get all possibilties of true and false on all partitions
            long long LT = rec(i, ind - 1, 1, S, dp);
            long long LF = rec(i, ind - 1, 0, S, dp);
            long long RT = rec(ind + 1, j, 1, S, dp);
            long long RF = rec(ind + 1, j, 0, S, dp);
            
            if(S[ind] == '&') {
                
                if(isTrue)
                    ways += (LT * RT) % 1003;
                else
                    ways += ((LF * RF) % 1003 + (LF * RT) % 1003 + (LT * RF) % 1003) % 1003;
            }
            
            else if(S[ind] == '|') {
                
                if(isTrue)
                    ways += ((LT * RT) % 1003 + (LF * RT) % 1003 + (LT * RF) % 1003) % 1003;
                else
                    ways += (LF * RF) % 1003;
            }
            
            else {
                
                if(isTrue)
                    ways += ((LT * RF) % 1003 + (RT * LF) % 1003);
                else
                    ways += ((LT * RT) % 1003 + (LF * RF) % 1003);  
            }
        }
        
        return dp[i][j][isTrue] = ways % 1003;
    }

    int countWays(int N, string S){
        // code here
        
        vector<vector<vector<int>>> dp(N, vector<vector<int>> (N, vector<int>(2, -1)));
        return rec(0, N - 1, 1, S, dp) % 1003;
    }
};

/******************************************************************* DP *******************************************************************************/

class Solution{
public:

    int countWays(int N, string S){
        
        vector<vector<vector<int>>> dp(N, vector<vector<int>> (N, vector<int>(2, 0)));
        
        for(int i = 0; i < N; i++) {
            for(int k = 0; k <= 1; k++) {
                if((k && S[i] == 'T') || (!k && S[i] == 'F'))
                    dp[i][i][k] = 1;
            }
        }
        
        for(int i = N - 1; i >= 0; i--) {
            for(int j = i + 1; j < N; j++) {
                
                for(int k = 0; k <= 1; k++) {
                    
                    int ways = 0;
                        
                    for(int ind =  i + 1; ind <= j - 1; ind = ind + 2) {
                        
                        long long LT = dp[i][ind - 1][1];
                        long long LF = dp[i][ind - 1][0];
                        long long RT = dp[ind + 1][j][1];
                        long long RF = dp[ind + 1][j][0];
                            
                        if(S[ind] == '&') {
                                
                            if(k)
                                ways += (LT * RT) % 1003;
                            else
                                ways += ((LF * RF) % 1003 + (LF * RT) % 1003 + (LT * RF) % 1003) % 1003;
                        }
                            
                        else if(S[ind] == '|') {
                                
                            if(k)
                                ways += ((LT * RT) % 1003 + (LF * RT) % 1003 + (LT * RF) % 1003) % 1003;
                            else
                                ways += (LF * RF) % 1003;
                        }
                            
                        else {
                                
                            if(k)
                                ways += ((LT * RF) % 1003 + (RT * LF) % 1003);
                            else
                                ways += ((LT * RT) % 1003 + (LF * RF) % 1003);  
                        }
                    } 
                        
                    dp[i][j][k] = ways % 1003;
                }
                
            }
        }
        return dp[0][N - 1][1] % 1003;
    }
};
