#include<bits/stdc++.h>
using namespace std;

int sum(int n) {
  return (n * (n + 1))/2;
}

int minJumps(int x) {
  //write your code here
  int s = sum(1), i = 2;
  while(s < x) {
    s = sum(i);
    i++;
  }

  i--;

  if(s == x) {
    return i;
  }

  int diff = s - x;

  if(diff % 2 == 0)
    return i;

  else {
    i++;
    s = sum(i);
    diff = s - x;
    if(diff % 2 == 0)
      return i;
    else
      return i + 1;
  }
  return -1;
}


int main(){
    int x;
    cin>>x;

    int jumps = minJumps(x);
    cout<<jumps;
}
