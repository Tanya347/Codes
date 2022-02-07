#include<bits/stdc++.h>
using namespace std;
  
  //shift bits till the number doesn't become zero, this will
  //give position of leftmost bit
  int leftMostBit(n) {
    int pos = 0;
    while(n != 0) {
      pos++;

      n = n >> 1;
    }
    return pos;
  }

  //function to find survivor
  int solution(int n){
    int i = leftMostBit(n);
    int j = 1 << (i - 1);
    n = n ^ j;
    n = n << 1;
    n = n | 1;

    return n;
  }

  
  int main()
  {
    int n;
    cin>>n;
    cout<<solution(n);
  }
