#include<bits/stdc++.h>
using namespace std;
 
int main(){
    
    int n,i,j,k,m;
    cin>>n>>i>>j>>k>>m;
 
    //setting its ith bit on
    int onmask = 1 << i;
 
    //setting its jth bit off
    int offmask = ~(1 << j);
 
    //toggling kth bit
    int togglemask = 1 << k;
 
    //checking mth bit
    int checkmask = 1 << m;
 
    cout<<(n | onmask)<<endl;
    cout<<(n & offmask)<<endl;
    cout<<(n ^ togglemask)<<endl;
    string ans = (n & checkmask) ? "true" : "false";
    cout<<ans<<endl;
}
