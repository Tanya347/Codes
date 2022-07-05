
//we need to check that whether or not a substring of the given tree starts with vowel and ends with consonant and vice versa and return count of all such substrings


bool checkVowel(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    else return false;
}

int Solution::solve(string A) {
    int count = 0;
    int mod = pow(10, 9) + 7;
    
    for (int i = 0; i < A.size(); i++) {
        for (int len = 1; len <= A.size() - i; len++) {
            string str = A.substr(i, len);
            
            if(checkVowel(str[0]) && !checkVowel(str[len - 1]))
                count++;
                
            else if(checkVowel(str[len - 1]) && !checkVowel(str[0]))
                count++;
        }
    }
    
    return count % mod;
}
