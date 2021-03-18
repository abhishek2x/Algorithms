/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[1001][1001];

int MCM(vector<int> arr, int i, int j) {
  if(i>=j) return 0;
  if(dp[i][j] != -1) return dp[i][j];

  int mn=INT_MAX;
  for(int k=i; k<j; k++) {
    int left, right;
    
    if(dp[i][k] != -1) 
      left = dp[i][k];
    else left = MCM(arr, i, k); 
    
    if(dp[k+1][j] != -1) 
      right = dp[k+1][j];
    else right = MCM(arr, k+1, j);

    int temp = left + right + (arr[i-1] * arr[k] * arr[j]);

    mn = min(mn, temp);
  }
  return mn;
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);
  
  memset(dp, -1, sizeof(dp));
  vector<int> v = { 1, 2, 3, 4, 3 };

  int i=1;
  int j=v.size()-1;

  cout << MCM(v, i, j);

  return 0;
}