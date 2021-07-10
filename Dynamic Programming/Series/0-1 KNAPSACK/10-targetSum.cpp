/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[1001][1001];

int SubsetSum(vector<int>& arr, int n, int sum) {
  if(sum == 0) return 1;
  if(n == 0) return 0; 

  if(dp[n-1][sum] != -1) return dp[n-1][sum];
  if(arr[n-1] > sum) return dp[n-1][sum] = SubsetSum(arr, n-1, sum);

  return dp[n-1][sum] = SubsetSum(arr, n-1, sum-arr[n-1]) + SubsetSum(arr, n-1, sum);
}

int TargetSum(vector<int>& arr, int n, int diff) {
  ll sum=0;
  for(auto i: arr) sum += i;

  int s1 = (sum+diff)/2;
  return SubsetSum(arr, n, s1);

}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));
  vector<int> arr = {1, 2, 7};
  int diff = 4;

  cout << TargetSum(arr, 3, diff);
  return 0;
}