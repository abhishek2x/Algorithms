/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void insert(vector<int> v, int temp) {
  if(v.size() == 0 || v[v.size()-1] <= temp) {
    v.push_back(temp);
    return;
  }
  int val = v[v.size()-1];
  v.pop_back();
  insert(v, temp);
  v.push_back(val);
}

void sort(vector<int> v) {
  if(v.size() == 1) {
    return;
  }
  int temp = v[v.size()-1];
  v.pop_back();
  return sort(v);
  insert(v, temp);
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  vector<int> v = {1, 2, 3, 7, 4, 9, 0};

  sort(v);
  
  return 0;
}