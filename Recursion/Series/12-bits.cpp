// Print all binary nos having more prefix 1's than 0's

/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void generate(string op, int ones, int zeros, int n) {
  if(n == 0) {
    cout << op << "\n";
    return;
  }
  else {
    string op1 = op + "1";
    generate(op1, ones+1, zeros, n-1);

    if(ones > zeros) {
      string op0 = op + "0";
      generate(op0, ones, zeros+1, n-1);
    }
    
  }
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n = 5;
  generate("", 0, 0, n);

  return 0;
}
