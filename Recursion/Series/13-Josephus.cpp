// Game of Death in Circle

/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int getAlive(vector<int> v, int k, int index) {
  if(v.size() == 1) {
    return v[0];
  }

  index = (index+k) % v.size();
  v.erase(v.begin()+k);
  
  return getAlive(v, k, index);
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n, k;

  n=5;
  k=2;

  k--;
  vector<int> v;
  for (int in = 0; in < n; in++)
    v[in] = in;

  cout << getAlive(v, k, 0);
  return 0;
}