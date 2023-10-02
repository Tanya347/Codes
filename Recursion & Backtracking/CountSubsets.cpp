/************************************************* QUESTION *****************************************************************************/

You are given an array of integers and a target K. You have to find the count of subsets of the given array that sum up to K.
Note:
1. Subset can have duplicate values.
2. Empty subset is a valid subset and has sum equal to zero.
Input Format:
The first line of input will contain an integer T, that denotes the value of number of test cases.
Each test case contains two lines. The first line of each test case will contain two space-separated integers N and K, where N is the size of the given array and K is the target value. 
The second line of each test case will contain N space separated integers denoting the elements of the input array.
Output Format ;
For each test case, print the number of subsets that sum upto K in a separate line.
Constraints
1 <= T <= 50
2 <= N <= 15
0 <= array[i] <= 10^9
0 <= K <= 10^9
Time Limit: 1 second
Sample Input 1:
1
5 6
2 4 4 3 1
Sample Output 1:
3
Explanation:
Following are the three subsets, that sum upto K=6:
1. [2, 4], Element 4 in this subset is the one at index 1
2. [2, 4], Element 4 in this subset is the one at index 2
3. [2, 3, 1]  
Sample Input 2:
2
8 8
1 4 1 3 1 1 2 3 
8 2
4 1 4 4 2 4 1 1
Sample Output 2:
30
4

/************************************************* ANSWER *****************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int countSubsets(int n, vector<int>& v, int k, int ind) {

    if(ind == n) {
        if(k == 0)
            return 1;
        else return 0;
    }

    if(k == 0 && ind > 0) return 1;  // Check if ind > 0
    else if(k == 0) return 0;  // Return 0 if k=0 and ind=0if(k == 0) return 1;

    int x = 0, y = 0;

    // take
    if(v[ind] <= k)
        x = countSubsets(n, v, k - v[ind], ind + 1);

    // not take
    y = countSubsets(n, v, k, ind + 1);

    return x + y;
}

int main(){
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<int> v;

        for(int i = 0; i < n; i++) {
            int temp;
            cin>>temp;
            v.push_back(temp);
        }

        cout<<countSubsets(n, v, k, 0)<<endl;
    }
    return 0;
}
