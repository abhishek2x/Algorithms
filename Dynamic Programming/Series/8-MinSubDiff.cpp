/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[1001][1001];
// [n][sum]

int summing(vector<int>& arr, int n, int sum) {
  if(sum == 0) return true;
  if(n == 0) return false;

  if(dp[n-1][sum] != -1)
    return dp[n-1][sum];

  if(arr[n-1] > sum)
    return dp[n-1][sum] = summing(arr, n-1, sum);

  return dp[n-1][sum] = summing(arr, n-1, sum-arr[n-1]) || summing(arr, n-1, sum);
}

int MinSubDiff(vector<int> &arr, int n) {
  ll sum=0;
  for(int i: arr) sum += i;

  bool S[sum/2+1] = {false};
  for(int i=0; i<sum/2+1; i++) 
    if(summing(arr, n, i)) S[i] = true;

  ll mn=INT_MAX;
  for(int i=sum/2; i>=0; i--) 
    if(S[i]) {mn = min(mn, sum-2*i);}

  return mn;  
}

int main(){
  ios :: sync_with_stdio(false);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));
  vector<int> arr = {3, 1, 4, 2, 2, 1};

  cout << MinSubDiff(arr, 6);
  return 0;
}
