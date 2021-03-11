/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[1001][1001];

bool SubsetSum(vector<int>& arr, int n, int sum) {
  if(sum == 0) return true;
  if(n == 0) return false; 

  if(dp[n-1][sum] != -1) return dp[n-1][sum];
  if(arr[n-1] > sum) return dp[n-1][sum] = SubsetSum(arr, n-1, sum);

  return dp[n-1][sum] = SubsetSum(arr, n-1, sum-arr[n-1]) || SubsetSum(arr, n-1, sum);
}

int SubsetWithGivenDiff(vector<int>& arr, int n, int diff) {
  ll sum=0;
  for(auto i: arr) sum += i;
  bool S[sum]={false};
  
  for(int i=0; i<sum; i++) 
    if(SubsetSum(arr, n, i)) S[i] = true;

  // for(auto i: S) cout << i << "\n";

  int ans=0;
  for(int i=0; i<sum-diff; i++)
    if(S[i] && S[i+diff]) ans++;
  
  return ans;
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));
  vector<int> arr = {1, 2, 7};
  int diff = 4;

  cout << SubsetWithGivenDiff(arr, 3, diff);
 
  return 0;
}