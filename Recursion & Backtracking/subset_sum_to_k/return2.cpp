#include<iostream>
using namespace std;
            

int subsetSumToK(int input[], int n, int output[][50], int k) {
   
    
    if(n<=0)
    {
        if(k==0)
        {
            output[0][0]=0;
            return 1;
        }
        else
            return 0;
    }
    
    int output1[1000][50], output2[1000][50];
    
    int s1 = subsetSumToK(input + 1, n - 1, output1, k);
    int s2 = subsetSumToK(input + 1, n - 1, output2, k - input[0]);
    
    int i = 0;
    
    for(int j = 0; j < s1; j++)
    {
        for(int k = 0; k <= output1[j][0]; k++)
            output[i][k] = output1[j][k];
        i++;
    }
    
    for(int j = 0; j < s2; j++)
    {
        output[i][0] = output2[j][0] + 1;
        output[i][1] = input[0];
        for(int k = 1; k <= output2[j][0]; k++)
        {
            output[i][k + 1] = output2[j][k];
        }
        i++;
    }
    
    
    return i;
}
