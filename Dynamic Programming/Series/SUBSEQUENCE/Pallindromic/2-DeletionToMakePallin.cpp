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

  string X = "agbcba";
  // answer = 1

  string Y = X;
  reverse(Y.begin(), Y.end());

  int m = X.length();

  for(int i=0; i<m+1; i++)
    for(int j=0; j<m+1; j++) {
      if(i == 0 || j == 0) dp[i][j] = 0;
      else if(X[i-1] == Y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }

  cout << m - dp[m][m];
  
  return 0;
}