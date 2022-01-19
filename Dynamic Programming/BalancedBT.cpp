/********************************************** QUESTION *****************************************************************

Given an integer h, find the possible number of balanced binary trees of height h. You just
need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.

**************************************************************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

/*********************************************** BRUTE FORCE APPROACH ****************************************************/

long balancedBTs1(int n)
{

    if (n == 0 || n == 1)
        return 1;

    int mod = (int)pow(10, 9) + 7;

    int x = balancedBTs1(n - 1);
    int y = balancedBTs1(n - 2);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);
    long ans = (temp1 + temp2) % mod;
    return ans;
}

/*********************************************** TOP TO BOTTOM APPROACH ****************************************************/

long balancedBTs_helper(int *dp, int n)
{
    if (n == 0 || n == 1)
        return 1;

    int mod = (int)pow(10, 9) + 7;

    if (dp[n] != -1)
        return dp[n];

    int x = balancedBTs1(n - 1);
    int y = balancedBTs1(n - 2);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);
    dp[n] = (temp1 + temp2) % mod;

    return dp[n];
}

long balancedBTs2(int n)
{

    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    return balancedBTs_helper(dp, n);
}

/*********************************************** BOTTOM UP APPROACH ****************************************************/

long balancedBTs3(int n)
{
    long *dp = new long[n + 1];

    int mod = (int)pow(10, 9) + 7;

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] % mod * ((2 * dp[i - 2]) % mod + dp[i - 1] % mod)) % mod;
    }

    return dp[n];
}

int main()
{

    // Taking input
    long n;
    cout << "Enter the height : " << endl;
    cin >> n;

    // brute force
    long num1 = balancedBTs1(n);
    cout << "The number of binary trees is : " << num1 << endl;

    // top down
    long num2 = balancedBTs2(n);
    cout << "The number of binary trees is : " << num2 << endl;

    // bottom up approach
    long num3 = balancedBTs3(n);
    cout << "The number of binary trees is : " << num3 << endl;
}