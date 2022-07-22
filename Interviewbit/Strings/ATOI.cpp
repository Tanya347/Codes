/********************************************************************** QUESTION **************************************************************************************/

/*

There are certain questions where the interviewer would intentionally frame the question vague.

The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9

Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

    Questions:

    Q1. Does string contain whitespace characters before the number?

    A. Yes

    Q2. Can the string have garbage characters after the number?

    A. Yes. Ignore it.

    Q3. If no numeric character is found before encountering garbage characters, what should I do?

    A. Return 0.

    Q4. What if the integer overflows?

    A. Return INT_MAX if the number is positive, INT_MIN otherwise.

Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.

*/

/********************************************************************** ANSWER **************************************************************************************/

int Solution::atoi(const string A) {
    
    // reach index where white space end
    int i = 0;
    while(A[i] == ' ' && i < A.length()) i++;
    
    // read next character to check for postivity or negativity
    bool positive = true;
    
    if(A[i] == '-') {
        positive = false;
        i++;
    } else if(A[i] == '+')
        i++;
    
    // find ending point of string
    int j = i;   
    while((A[j] - '0') >= 0 && (A[j] - '0') <= 9) {
        j++;
    }
    
    // extract relevant string
    string s = A.substr(i, j - i);
    
    // return based on length of string
    if(s.length() == 0)
        return 0;
    else if(positive && s.length() >= 10)
        return INT_MAX;
    else if(!positive && s.length() >= 10)
        return INT_MIN;
    
    // convert into integer
    int ans = 0, p = 0;
    i = s.length() - 1;
    while(i >= 0) {
        ans += (s[i] - '0')*pow(10, p);
        p++;
        i--;
    }
    
    // negativity
    if(!positive)
        ans = -ans;
    
    // if answer overflows
    if(ans > INT_MAX)
        return INT_MAX;
    else if(ans < INT_MIN)
        return INT_MIN;
        
    return ans;
}
