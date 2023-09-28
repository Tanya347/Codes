/********************************************************** QUESTION ****************************************************************************/

You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of K.
Output format :
The first and only line of output contains count of all such pairs which have an absolute difference of K. 
Constraints :
0 <= n <= 10^4
Time Limit: 1 sec
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2
Explanation
(5,2) and (1,4) are the possible combinations as their absolute difference is 3.
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
6

/********************************************************** ANSWER 1 ****************************************************************************/

#include <unordered_map>

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here

	int ans = 0;
	unordered_map<int, int> mp;

	for(int i = 0; i < n; i++) {
		ans += mp[arr[i] + k];
		if(k != 0) {
			ans += mp[arr[i] - k];
		}
		++mp[arr[i]];
	}
	
	return ans;
}

/********************************************************** ANSWER 2 ****************************************************************************/

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here

	unordered_map<int, int> mp;

	for(int i = 0; i < n; i++) {
		mp[arr[i]]++;
	}

	int ans = 0;

	for(int i = 0; i < n; i++) {

		if(k == 0) {
			int count = mp[arr[i]];
			return (count * (count - 1)) / 2;
		}
		else {
			int count =  mp[arr[i]];
			int count1 = mp[arr[i] - k];
			int count2 = mp[arr[i] + k];
			mp.erase(arr[i]);
			ans += count*count1 + count*count2;
		}
		
	}

	return ans;
}
