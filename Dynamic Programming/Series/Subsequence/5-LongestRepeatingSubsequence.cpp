/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  int dp[1001][1001];
  memset(dp, -1, sizeof(dp));

  string X = "aabebcdd";
  string Y = X;
  // answer = "abd"

  int m = X.length();
  int n = Y.length();

  int i, j;

  for(i=0; i<=m; i++) 
    for(j=0; j<=n; j++) {
      if(i == 0 || j == 0) dp[i][j] = 0;
      else if(X[i-1] == Y[j-1] && i != j) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }

  i=m; j=m;
  string ans="";

  while(i>0 && j>0){
    if(X[i-1] == Y[j-1] && i!=j) {
      ans += X[i-1];
      i--; j--;
    }
    else if(dp[i-1][j] > dp[i][j-1]) i--;
    else j--;
  }

  reverse(ans.begin(), ans.end());
  cout << ans;
  
  return 0;
}