/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int t[101][1001];

int unKnaping(vector<int>& values, vector<int>& weights, int n, int W) {
  // base
  if(n == 0 || W == 0)
    return 0;

  if(t[n][W] != -1)
    return t[n][W];

  // choice 
  if(weights[n-1] > W){
    // not include
    return t[n][W] = unKnaping(values, weights, n-1, W);
  } else {
    // include or not include
    return t[n][W] = max( values[n-1] + unKnaping(values, weights, n, W-weights[n-1]), unKnaping(values, weights, n-1, W));
  }
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  memset(t, -1, sizeof(t));
  
  vector<int> values = {10, 30, 20};
  vector<int> weights = {5, 10, 15};
  int W = 100;

  cout << unKnaping(values, weights, 3, W);
  return 0;
}
