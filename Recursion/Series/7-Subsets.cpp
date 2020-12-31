// Print all subsets : POWERSETS

/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void getSubsets(string ip, string op) {
  if(ip.length() == 0) {
    cout << op << "\n";
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

  string str = "ABC";

  getSubsets(str, "");

  return 0;
}