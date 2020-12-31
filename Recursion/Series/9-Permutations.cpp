// Permutations with space

/*!
* Copyright (c) 2020 Abhishek Srivastava

A B C
A BC
AB C 
ABC

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void getPermutations(string ip, string op) {
  if(ip.length() == 0) {
    cout << op << "\n";
    return;
  }

  string op1 = op + " " + ip[0];
  string op2 = op + ip[0];
  ip.erase(ip.begin()+0);

  getPermutations(ip, op1);
  getPermutations(ip, op2);
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  string ip = "1234";
  string op = "";
  
  op.push_back(ip[0]);
  ip.erase(ip.begin()+0);

  getPermutations(ip, op);

  return 0;
}