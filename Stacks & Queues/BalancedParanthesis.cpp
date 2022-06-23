#include<stack>

bool isBalanced(string expression) 
{
    // Write your code here
    stack<char> s;
    
    for(int i = 0; i < expression.length(); i++) {
        
        if(expression[i] == '(')
            s.push(expression[i]);
        
        else if(expression[i] == ')') {
            if(!s.empty() && s.top() == '(')
                s.pop();
            else if(s.empty())
                return false;
        }
    }
    
    return (s.empty())?true:false;
}
