/************************************************* QUESTION *****************************************************************************/

Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?
 Input format :
The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.
Output format :
Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).
Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec
Sample Input 1 :
4 2 3
Sample Output 1 :
Whis
Sample Input 2 :
10 2 4
Sample Output 2 :
Beerus
Explanation to Sample Input 1:
Initially, there are 4 coins,  In the first move, Beerus can remove either 1, 2, or 3 coins in all three cases, Whis can win by removing all the remaining coins. 

/************************************************* ANSWER *****************************************************************************/

#include<vector>

string findWinner(int n, int x, int y)
{
	// Write your code here .

	if(x > y) {
		swap(x, y);
	}

	// dp represents that for a particular number of coins represented by index i
	// whether Beerus will win or not
	vector<bool> dp(n + 1, 0);

	// i represents number of remaining coins
	for(int i = 1; i <= n; i++) {

		if(i == 1 || i == x || i == y)
			dp[i] = true;

		// if lesser number of coins are left then players can only pick 1 coin every turn
		// so the answer would be the opposite of the answer when there are i - 1 coins left
		else if(i < x)
			dp[i] = !dp[i - 1];

		// If the next player will lose when there are i - x coins or i - 1 coins, then the current player will 
		// ensure he transitions the game to that losing state. Thus, current player wins.
		// If the next player will win for both i - x coins and i - 1 coins, then no matter what the current player does, 
		// the next player will always be in a winning position. Thus, current player loses.

		else if(i < y)
			dp[i] = !(dp[i - x] && dp[i - 1]);

		// If the next player loses for any of the scenarios (i - 1, i - x, or i - y coins), the current player 
		// will transition the game to that state and win.
		// If the next player wins for all three scenarios (i - 1, i - x, and i - y), the current player loses as 
		// they can't put the next player in a losing position.
		else	
			dp[i] = !(dp[i - x] && dp[i - y] && dp[i - 1]);
	}

	return dp[n] ? "Beerus" : "Whis";
}
