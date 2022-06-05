int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    
    //base case
    if(n==0){
        if(k==0){
            output[0][0]=0;
            return 1;
        }
        else
            return 0;
    }
    
    //with first element
    int s1 = subsetSumToK(input + 1, n - 1, output, k - input[0]);
    int s2 = subsetSumToK(input + 1, n - 1, output + s1, k);
    
    //shift elements
    for(int i=0;i<s1;i++){
        for(int j=output[i][0];j>=1;j--)
            output[i][j+1]=output[i][j];
    }
    
    for(int i=0;i<s1;i++){
        output[i][0]++;
        output[i][1]=input[0];
    }
    
    //without first element
    return s1+s2;
}
