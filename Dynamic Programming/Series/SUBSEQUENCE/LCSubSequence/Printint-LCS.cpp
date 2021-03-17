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
  // answer = "abcida",

  int m=X.length();
  int n=Y.length();

  int i, j;
  
  for(int i=0; i<m+1; i++) 
    for(int j=0; j<n+1; j++) {
      if(i==0 || j == 0) dp[i][j] = 0;
      else if(X[i-1] == Y[j-1]) dp[i][j] = 1+dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }

  i=m; j=n;
  string ans = "";
  while(i > 0 && j > 0) {
    if(X[i-1] == Y[j-1]) {
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