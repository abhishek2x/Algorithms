/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int MCM(vector<int> arr, int i, int j) {
    if(i>=j) return 0;

    int ans=INT_MAX;
    for(int k=i; k<j; k++) {
      int temp = MCM(arr, i, k) + MCM(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
      ans = min(ans, temp);
    }
    return ans;
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);
  
  vector<int> v = { 1, 2, 3, 4, 3 };

  int i=1;
  int j=v.size()-1;

  cout << MCM(v, i, j);

  return 0;
}