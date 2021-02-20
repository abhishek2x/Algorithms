/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printIt(vector<int> v) {
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << "\n";
}

void BubbleSort(vector<int> v, int n) {

  if(n == 1) {
    printIt(v);
    return;
  }

  // at the end of this loop,
  // largest will reach the end position.
  for (int i = 0; i < n-1; i++)
    if(v[i] > v[i+1])
      swap(v[i], v[i+1]);
      
  BubbleSort(v, n-1);
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  vector<int> v = {64, 34, 25, 12, 22, 11, 90};
  printIt(v);

  BubbleSort(v, v.size());
  return 0;
}