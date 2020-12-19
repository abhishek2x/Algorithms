/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

/*
 For demstration of concept we are using
 int variable. But ideally we will prefer using 
 double value with an Epison error estimation. 
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int getSquareRoot(int n, int start, int end) {
  int mid = start + (end-start)/2;
  if(mid*mid == n){
    return mid;
  } else if(mid*mid > n) {
    getSquareRoot(n, start, end-1);
  } else getSquareRoot(n ,start+1, end);
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n = 9;

  cout << getSquareRoot(n, 0, n/2);

  return 0;
}