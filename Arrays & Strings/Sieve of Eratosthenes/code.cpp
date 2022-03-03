#include<bits/stdc++.h>
using namespace std;

void printPrimeUsingSieve(int n){
    //Write your code here
    vector<bool> isPrime(n + 1, true);
    for(int i = 2; i*i <= n; i++) {
        if(isPrime[i]) {
            int j = 2;
            while(i*j <= n) {
                isPrime[i*j] = false;
                j++;
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        if(isPrime[i])
            cout<<i<<" ";
    }
} 

int main(){
    int n;
    cin>>n;
    printPrimeUsingSieve(n);
}
