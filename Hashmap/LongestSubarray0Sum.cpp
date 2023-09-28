/********************************************************** QUESTION ****************************************************************************/

Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format
The first and only line of output contains length of the longest subarray whose sum is zero.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1:
10 
 95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output 1:
5
Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897 
Note
You don't have to print anything. Just complete the definition of the function given and return the value accordingly.

/********************************************************** ANSWER ****************************************************************************/

#include <unordered_map>

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here

    for(int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
    }

    int length = 0;

    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            length = max(length, i + 1);
        }
        else if(mp.find(arr[i]) != mp.end()) {
            length = max(length, i - mp[arr[i]]);
        }
        mp[arr[i]] = i;
    }

    return length;

}
