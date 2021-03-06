
/*!
* Copyright (c) 2020 Abhishek Srivastava
// Kth Symbol Grammer

0
01
0110
01101001

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int NthGrammer(int n, int k){
  if(n == 1) {
    return 0;
  }
  if(k%2 == 0) {
    return !NthGrammer(n-1, k/2);
  } else {
    return NthGrammer(n-1, (k+1)/2);
  }
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  int N=4, K=5;
  cout << NthGrammer(N, K);

  return 0;
}