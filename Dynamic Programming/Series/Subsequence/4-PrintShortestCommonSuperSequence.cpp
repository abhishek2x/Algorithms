/*!
* Copyright (c) 2020 Abhishek Srivastava
*/


// revisit: https://www.youtube.com/watch?v=VDhRg-ZJTuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=29

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  int dp[1001][1001];
  memset(dp, -1, sizeof(dp));

  string X = "AGGTAB";
  string Y = "GXTXAYB";
  // answer = "AGXGTXAYB"

  int m = X.length();
  int n = Y.length();

  int i, j;

  for(i=0; i<=m; i++) 
    for(j=0; j<=n; j++) {
      if(i == 0 || j == 0) dp[i][j] = 0;
      else if(X[i-1] == Y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }


  i = m; j = n;
  string ans = "";
  while(i>0 && j>0) {
    if(X[i-1] == Y[j-1]) {
      ans += X[i-1];
      i--; j--;
    }
    else if(dp[i-1][j] > dp[i][j-1]) {
      ans += Y[j-1];
      j--;
    } else {
      ans += X[i-1];
      i--;
    }
  }

  while (i > 0) { 
    ans += X[i-1];
    i--;
  } 
  while (j > 0) { 
    ans += Y[j-1];
    j--;
  }
 
  // reverse(ans.begin(), ans.end());

  cout << ans;

  return 0;
}