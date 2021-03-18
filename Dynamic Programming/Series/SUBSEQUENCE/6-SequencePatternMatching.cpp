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

  string X = "AXY";
  string Y = "ADSXFY";
  // answer = "true"

  int m = X.length();
  int n = Y.length();

  int i, j;

  for(i=0; i<=m; i++) 
    for(j=0; j<=n; j++) {
      if(i == 0 || j == 0) dp[i][j] = 0;
      else if(X[i-1] == Y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  if(dp[m][n] == X.length()) cout << "True";
  else cout << "False";
  
  return 0;
}