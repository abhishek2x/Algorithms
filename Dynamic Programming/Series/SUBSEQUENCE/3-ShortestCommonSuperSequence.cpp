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

  string X = "abchidfa";
  string Y = "abcidpkkka";
  // answer = "abchidfkkka", i.e, 11

  int m = X.length();
  int n = Y.length(); 

  for(int i=0; i<m+1; i++) 
    for(int j=0; j<n+1; j++) {
      if(i == 0 || j == 0) dp[i][j] = 0;
      if(X[i] == Y[j]) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    }

  cout << m+n-dp[m][n];

  return 0;
}