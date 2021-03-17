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
  // answer = "abcida", i.e, 3

  int m = X.length();
  int n = Y.length(); 

  int maxLength = 0;

  for(int i=0; i<m+1; i++){
    for(int j=0; j<n+1; j++) {
      if (i == 0 || j == 0) dp[i][j] = 0;
      else if (X[i-1] == Y[j-1]){
        dp[i][j] = 1 + dp[i-1][j-1];
        maxLength = max(maxLength, dp[i][j]);
      }
      else dp[i][j] = 0;
    }
  }
  
  cout << maxLength;

  return 0;
}