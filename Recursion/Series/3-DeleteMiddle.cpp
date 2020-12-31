// Delete middle element of Stack

/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printIt(stack<int> s) {
  while(!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
}

void DelMid(stack<int> &st, int curr, int len) {
  if(st.empty() || curr == len){
    return;
  }

  int top = st.top();
  st.pop();

  DelMid(st, curr+1, len);

  if(curr != len/2){
    st.push(top);
  }
}

int main(){

  ios :: sync_with_stdio(false);
  cin.tie(0);

  stack<int> st;
  st.push(64);
  st.push(34);
  st.push(25);
  st.push(12);
  st.push(22);
  st.push(11);
  st.push(90);

  DelMid(st, 0, 7);
  printIt(st);

  return 0;
}