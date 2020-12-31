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

void InsertInStack(stack<int> &s, int key) {
  if(s.empty() || key > s.top()) {
    s.push(key);
    return;
  }

  int top = s.top();
  s.pop();

  InsertInStack(s, key);
  s.push(top);
}

void sort(stack<int> &s) {
  if(s.empty()) {
    return;
  }

  int top = s.top();
  s.pop();

  // make this stack empty.
  // Also maintain element in top variable
  sort(s);
  InsertInStack(s, top);
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

  sort(st);

  printIt(st);

  return 0;
}