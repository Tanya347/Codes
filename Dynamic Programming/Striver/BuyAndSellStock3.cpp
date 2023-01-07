/******************************************************************* QUESTION *******************************************************************************/

/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/

/******************************************************************* ANSWER *******************************************************************************/



/******************************************************************* MERA DIMAG (193/214) *******************************************************************************/
// where it went wrong

[1,2,4,2,5,7,2,4,9,0]

output : 12
expected : 13

  
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        // keeps track of ongoing profit
        int profit = 0;

        // selling price in current transaction
        int minPrice = prices[0];

        // stores all transactions
        unordered_map<int, int> profits;

        for(int i = 1; i < n; i++) {

            // getting max profit out of current transaction
            if(prices[i] - minPrice > profit) 
                profit = prices[i] - minPrice;

            // if low price found begin new transaction
            if(profit && (prices[i] < prices[i - 1])) {
                profits[profit]++;
                profit = 0;
                minPrice = prices[i];
            }
            else
            // get lower price if possible
                minPrice = min(prices[i], minPrice);
        }

        profits[profit]++;
        
        int one = 0, two = 0;
        
        for(auto it: profits) {

            if(it.first > one) {
                if(it.second > 1)
                    one = two = it.first;
                else {
                    two = one;
                    one = it.first;
                }
            } else if(it.first > two)
                two = it.first;
        }

        return one + two;
    }
};
