int lastIndex(int input[], int size, int x) {
	
    if(size == 0)
        return -1;
    
    int ans;
    
    if(input[size - 1] == x)
        return size - 1;
    else 
        ans = lastIndex(input, size - 1, x);
    
    return (ans == -1) ? -1 : ans;

}
