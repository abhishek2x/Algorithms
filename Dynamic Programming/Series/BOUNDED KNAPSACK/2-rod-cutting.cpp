/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[101][101];

int Cutter(vector<int>& prices, vector<int>& length, int n, int L) {
  if(n == 0 || L == 0) return 0;

  if(dp[n-1][L] != -1) return dp[n-1][L];

  if(length[n-1] > L) return Cutter(prices, length, n-1, L);

  return max(prices[n-1] + Cutter(prices, length, n, L-length[n-1]), Cutter(prices, length, n-1, L));
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);
  memset(dp, -1, sizeof(dp));

  vector<int> price = { 1, 5, 8, 9, 10, 17, 17, 20 }; 
  vector<int> length = { 1, 2, 3, 4, 5, 6, 7, 8 };
  int n = 8;
  int Max_len = n;

  cout << Cutter(price, length, n, Max_len);
  return 0;
}