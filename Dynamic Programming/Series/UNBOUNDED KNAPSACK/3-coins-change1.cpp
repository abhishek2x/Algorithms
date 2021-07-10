/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[1001][1001];

int change(vector<int> c, int n, int W) {
  if(W == 0) return 1;
  if(n == 0) return 0;

  if(c[n-1] > W) return change(c, n-1, W);
  if(dp[n-1][W] != -1) return dp[n-1][W];
  return change(c, n-1, W) + change(c, n, W-c[n-1]);
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));
  vector<int> coins = {1, 2, 3};
  int n=3, W=5;

  cout << change(coins, n, W) << "\n";

  return 0;
}