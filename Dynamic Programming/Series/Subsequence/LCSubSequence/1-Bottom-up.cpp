/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[1001][1001];

int LCS(string X, string Y, int n, int m) {
  if(n == 0 || m == 0) return 0;
  if(dp[n][n] != -1) return dp[n][m];
  if(X[n-1] == Y[m-1]) return dp[n][m] = 1 + LCS(X, Y, n-1, m-1);
  else return dp[n][m] = max(LCS(X, Y, n-1, m), LCS(X, Y, n, m-1));
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));


  string X = "abhidfa";
  string Y = "abidpkkka";
  // answer = "abida", i.e, 5

  int n = X.length();
  int m = Y.length();
  
  cout << LCS(X, Y, n, m);
  
  return 0;
}