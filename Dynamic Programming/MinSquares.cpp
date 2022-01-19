/********************************************** QUESTION *****************************************************************

Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as
1 is the minimum count of numbers required to represent N as sum of squares.

**************************************************************************************************************************/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/****************************************** BOTTOM UP APPROACH **************************************************/
int minSquares1(int n)
{
    // checking if n is a perfect square directly returning 1 in that case
    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;

    // base cases
    if (n <= 3)
        return n;

    // dp tabulation
    int *dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 0; i < n + 1; i++)
    {
        // variable that keeps tab of minimum count required
        int minimum = i;

        // setting i/2 as a higher standard for the for loop to run
        // sufficient number of times

        for (int j = 1; j <= i / 2; j++)
        {
            // number after subtracting current square
            int k = i - j * j;

            // find minimum count if k greater than 0 or breaking
            if (k >= 0)
                minimum = min(minimum, dp[k] + 1);
            else
                break;
        }
        dp[i] = minimum;
    }

    return dp[n];
}

/**************************************************** TOP DOWN APPROACH ************************************************************/

int minSquares2_helper(int n, int *dp)
{

    // base cases
    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;

    if (n <= 3)
    {
        return n;
    }

    if (dp[n] != -1)
        return dp[n];

    int minimum = n;
    for (int i = 1; i <= n / 2; i++)
    {
        int k = n - i * i;
        if (k >= 0)
            minimum = min(minimum, 1 + minSquares2_helper(k, dp));
        else
            break;
    }

    dp[n] = minimum;
    return dp[n];
}

int minSquares2(int n)
{
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    return minSquares2_helper(n, dp);
}

/********************************************* BRUTE FORCE APPROACH ******************************************************/

int minSquares3(int n)
{
    // base cases
    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;

    if (n <= 3)
    {
        return n;
    }

    int minimum = n;
    for (int i = 1; i <= n / 2; i++)
    {
        int k = n - i * i;
        if (k >= 0)
            minimum = min(minimum, 1 + minSquares3(k));
        else
            break;
    }

    return minimum;
}

int main()
{

    // Taking input
    int n;
    cout << "Enter the number you want to check : " << endl;
    cin >> n;

    // bottom up
    int num1 = minSquares1(n);
    cout << "The minimum number is : " << num1 << endl;

    // top down
    int num2 = minSquares2(n);
    cout << "The minimum number is : " << num2 << endl;
    /*
    // brute force
    int num3 = minSquares3(n);
    cout << "The minimum number is : " << num3 << endl;*/
}