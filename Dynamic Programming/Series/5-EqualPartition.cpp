/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[101][101];

bool SubsetSum(vector<int> v, int n, int sum) {
  if(sum == 0) return true;
  if(n == 0) return false;

  if(dp[n-1][sum] != -1)
    return dp[n-1][sum];

  if(v[n-1] > sum) 
    return dp[n-1][sum] = SubsetSum(v, n-1, sum);
  else return dp[n-1][sum] = SubsetSum(v, n-1, sum) || SubsetSum(v, n-1, sum - v[n-1]);
}

bool Equi(vector<int> v, int n) {
  int sum=0;
  for (int i = 0; i < n; i++)
    sum += v[i];
  
  if(sum%2 != 0){
    return false;
  } else {
    return SubsetSum(v, n, sum/2);
  }
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  vector<int> arr = {1, 6, 6, 11};
  int n = 4;

  sort(arr.begin(), arr.end());
  cout << Equi(arr, n);

  return 0;
}