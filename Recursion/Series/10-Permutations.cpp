// Permutations with case change
/*!
* Copyright (c) 2020 Abhishek Srivastava

Assume that input is in small case

ip = ab

ab
Ab
aB
AB

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void playCases(string ip, string op) {
  if(ip.length() == 0) {
    cout << op << "\n";
    return ;
  }

  string op1 = op + ip[0];
  string op2 = op + (char)toupper(ip[0]);
  ip.erase(ip.begin()+0);
  
  playCases(ip, op1);
  playCases(ip, op2);
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  string ip = "abc";
  string op = "";

  playCases(ip, op);

  return 0;
}