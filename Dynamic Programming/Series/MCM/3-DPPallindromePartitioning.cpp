/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[101][101];

bool isPallin(string String, int i, int j) {
  while(i<j) {
    if(String[i] != String[j]) return false;
    i++; j--;
  }
  return true;
}

int getPartition(string s, int i, int j) {
  if(i>=j || isPallin(s, i, j)) return 0;
  if(dp[i][j] != -1) return dp[i][j];

  int mn = INT_MAX;
  for(int k=i; k<j; k++) {
    int left, right;

    if(dp[i][k] != -1)
      left = dp[i][k];
    else left = getPartition(s, i, k);
    
    if(dp[k+1][j] != -1) 
      right = dp[k+1][j];
    else right = getPartition(s, k+1, j);

    int temp = left + right + 1;
    mn = min(mn, temp);
  }
  return mn;
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));
  string str = "ababbbabbababa";
  // aba|b|bbabb|a|b|aba   output = 3

  int i = 0;
  int j = str.length()-1;

  cout << getPartition(str, i, j);
  
  return 0;
}