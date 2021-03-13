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
  if(c[n-1] > W) return change(c, n-1, W);
  return min(change(c, n, W-c[n-1]), change(c, n-1, W));
}


int change(vector<int> c, int n, int sum) {

  for(int i=0; i<sum+1; i++) dp[0][i] = INT_MAX-1;
  for(int i=0; i<n; i++) dp[i][0] = 0;

  for(int i=1; i<sum+1; i++) 
    if(j%c[0] == 0) dp[1][j] = j/c[0];
    else dp[1][j] = INT_MAX-1;

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
 