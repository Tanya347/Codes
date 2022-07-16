string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

string Solution::intToRoman(int A) {
    string ans;
    
    for(int i = 0; A != 0; i++) {
        while(A >= num[i]) {
            A -= num[i];
            ans += roman[i];
        }
    }
    
    return ans;
}
