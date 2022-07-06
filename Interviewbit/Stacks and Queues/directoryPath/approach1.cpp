string Solution::simplifyPath(string A) {
    
    stack<string> st;
    
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == '/') {
            continue;
        }
        
        string word = "";
        //find what is in between /
        while(i < A.size() && A[i] != '/') {
            word+= A[i];
            i++;
        }
        
        //if it is . then it means we are in same directory and don't need to do anything
        if(word == ".") {
            continue;
        }
      
        //if it is .. that means we want to go one directory back i.e pop the topmost directory stored in stack  
        else if(word == "..") {
            if(st.size() > 0) st.pop();
        }
        
        //it is a normal word denoting a directory hence push it into stack
        else {
            st.push(word);
        }
    }
    
    //we have now only the required directories in stack, we'll form a path using that directory
    string absolute;
    
    while(!st.empty()) {
        string s = st.top();
        reverse(s.begin(), s.end());
        absolute.push_back('/');
        absolute.append(s);
        st.pop();
        
        //gives tle
        //absolute = '/' + st.top() + absolute;
        //st.pop();
    }
    
    if(absolute.length() == 0) return "/";
    
    reverse(absolute.begin() + 1, absolute.end());
    
    return absolute;
}
