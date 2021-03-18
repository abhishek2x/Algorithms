/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

// Inc - Refer: https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int boolenParenPlay(string s, int i, int j, bool isTrue) {
  // base condition
  if(i > j) return false;
  if(i == j) {
    if(isTrue) return s[i] == 'T';
    else return s[i] == 'F';
  } 

  // for loop
  int ans=0;
  for(int k=i+1; k<j; k+=2) {
    int lT, rT, lF, rF;
    lT = boolenParenPlay(s, i, k-1, true);
    lF = boolenParenPlay(s, i, k-1, false);    
    rT = boolenParenPlay(s, k+1, j, true);    
    rF = boolenParenPlay(s, k+1, j, false);    

    if(s[k] == '&') {
      if(isTrue) ans += lT*rT;
      else ans += lT*rF + lF*rT + rF*lF;
    }
    else if(s[k] == '|') {
      if(isTrue) ans += lT*rF + rT*lF + lT*rT;
      else ans += lF*rF;
    }
    else if(s[k] == '^') {
      if(isTrue) ans += lT*rF + rT*lF;
      else ans += rT*lT + rF*lF;
    }
  }
  return ans;
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);
  
  // input
  vector<char> symbols = {'T', 'T', 'F', 'T'};
  vector<char> operators = {'|', '&', '^'};
  // There are 4 ways
  // ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and
  // (T|((T&F)^T))

  // work
  string s="";
  int j=0;

  for (int i = 0; i < symbols.size(); i++) 
  {
    s.push_back(symbols[i]);
    if (j < operators.size())
        s.push_back(operators[j++]);
  }

  int i=0; j=s.length()-1;
  bool isTrue = true;

  cout << boolenParenPlay(s, i, j, isTrue);

  return 0;
}