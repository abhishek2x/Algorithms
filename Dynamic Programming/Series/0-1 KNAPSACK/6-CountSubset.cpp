/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[1001][1001];
// [n][sum]

int summing(vector<int>& arr, int n, int sum) {
  if(sum == 0) return 1;
  if(n == 0) return 0;

  if(dp[n-1][sum] != -1)
    return dp[n-1][sum];

  if(arr[n-1] > sum) {
    return dp[n-1][sum] = summing(arr, n-1, sum);
  }

  return dp[n-1][sum] = summing(arr, n-1, sum-arr[n-1]) + summing(arr, n-1, sum);
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  vector<int> arr = {2, 3, 5, 6, 8, 10};
  int W = 10;

  cout << summing(arr, 6, W);
  return 0;
}
