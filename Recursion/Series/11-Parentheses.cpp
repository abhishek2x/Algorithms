// Generate all balanced Parentheses

/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
  
void getParathesised(string ans, int open, int close) {
  if(close == 0) {
    cout << ans << "\n";
    return;
  }
  else {
    if(open != 0){
      string ans1 = ans+ "{";
      getParathesised(ans1, open-1, close);
    }
    if(close > open) {
      string ans1 = ans + "}";
      getParathesised(ans1, open, close-1);
    }
  }
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  int num = 3;

  string s = "";
  getParathesised(s, num, num);
  return 0;
}