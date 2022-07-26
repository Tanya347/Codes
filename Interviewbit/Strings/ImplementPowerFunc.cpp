/********************************************************************** QUESTION **************************************************************************************/

/*

Problem Description
 
 
Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative. In other words, make sure the answer you return is non negative.


Problem Constraints
-109 <= x <= 109
0 <= n <= 109
1 <= d <= 109


Example Input
x = 2
n = 3
d = 3


Example Output
2


Example Explanation
23 % 3 = 8 % 3 = 2.

*/

/********************************************************************** ANSWER **************************************************************************************/

int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(n == 0)
        return 1%d;
    if(n == 1)
    // d - abs(x)%d condition for negative x
        return max(abs(x)%d, d - abs(x)%d);
    
    // ans can be huge
    long long ans = pow(x, n/2, d) % d;
    ans = (ans*ans)%d;
    if(n%2)
        ans = (ans*x)%d;
    return ans%d;
}
