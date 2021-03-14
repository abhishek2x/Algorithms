/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[1001][1001];

int change2(vector<int> c, int n, int W) {
  if(n == 0) return INT_MAX-1;
  if(W == 0) return 0;
  if(n == 2) {
    if(c[n-1]%W == 0) return c[n-1]/W;
    else return INT_MAX-1;
  }

  if(dp[n-1][W] != -1) return dp[n-1][W];
  if(c[n-1] > W) return change2(c, n-1, W);
  return min(change2(c, n, W-c[n-1]), change2(c, n-1, W));
}


int change(vector<int> c, int n, int sum) {

  for(int i=0; i<sum+1; i++) dp[0][i] = INT_MAX-1;
  for(int i=0; i<n; i++) dp[i][0] = 0;

  for(int i=1; i<sum+1; i++) 
    if(i%c[0] == 0) dp[1][i] = i/c[0];
    else dp[1][i] = INT_MAX-1;

  for(int i=1; i<n+1; i++) {
    for(int j=2; j<sum+1; j++) {
      if(c[i-1] <= j) {
        dp[i][j] = min(dp[i][j-c[i-1]]+1, dp[i-1][j]);
      }
      else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  return dp[n][sum];

}


int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));
  vector<int> coins = {9, 6, 5, 1};
  int n=4, W=11;

  cout << change(coins, n, W) << "\n";

  return 0;
}
 