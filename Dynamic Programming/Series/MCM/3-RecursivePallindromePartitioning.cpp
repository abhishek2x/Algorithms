/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPallin(string String, int i, int j) {
  while(i<j) {
    if(String[i] != String[j]) return false;
    i++; j--;
  }
  return true;
}

int getPartition(string s, int i, int j) {
  if(i>=j || isPallin(s, i, j)) return 0;

  int mn = INT_MAX;
  for(int k=i; k<j; k++) {
    int temp = 1 + getPartition(s, i, k) + getPartition(s, k+1, j);
    mn = min(mn, temp);
  }
  return mn;
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  string str = "ababbbabbababa";
  // aba|b|bbabb|a|b|aba   output = 5

  int i = 0;
  int j = str.length()-1;

  cout << getPartition(str, i, j);
  
  return 0;
}