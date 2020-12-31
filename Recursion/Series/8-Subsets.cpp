// Print unique subsets and variations

/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

set<string> mp;

void getSubsets(string ip, string op) {
  if(ip.length() == 0) {
    mp.insert(op);
    return;
  }

  string op1 = op;
  string op2 = op;

  op2.push_back(ip[0]);
  ip.erase(ip.begin()+0);

  getSubsets(ip, op1);
  getSubsets(ip, op2);
  
  return;
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  string str = "AAB";
  getSubsets(str, "");

  for (auto &&i : mp)
    cout << i << "\n";
  
  return 0;
}